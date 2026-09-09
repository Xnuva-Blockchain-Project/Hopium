// HOPE legacy consensus rule adapter for Bitcoin Core 31.1.
// UNTESTED / DO NOT RELEASE.

#include <hope/consensus_rules.h>

#include <consensus/consensus.h>
#include <consensus/params.h>
#include <script/interpreter.h>
#include <hope/supply_cap.h>

namespace hope {

CAmount ProofOfWorkSubsidy(const int height)
{
    // Preserve authoritative HOPE behaviour exactly during mechanical migration.
    if (height == 1) return 10'000'000 * COIN;
    return 10 * COIN;
}

CAmount ProofOfStakeSubsidy()
{
    // Preserve authoritative HOPE behaviour exactly before cap activation.
    return 5 * COIN;
}

CAmount CappedProofOfWorkSubsidy(const int height,
                                 const CAmount previous_issued,
                                 const Consensus::Params& params)
{
    return LimitSubsidyBySupplyCap(height, previous_issued, ProofOfWorkSubsidy(height), params);
}

CAmount CappedProofOfStakeSubsidy(const int height,
                                  const CAmount previous_issued,
                                  const Consensus::Params& params)
{
    return LimitSubsidyBySupplyCap(height, previous_issued, ProofOfStakeSubsidy(), params);
}

script_verify_flags ScriptVerifyFlags(const int64_t block_time, const Consensus::Params& params)
{
    script_verify_flags flags{
        SCRIPT_VERIFY_P2SH |
        SCRIPT_VERIFY_DERSIG |
        SCRIPT_VERIFY_LOW_S |
        SCRIPT_VERIFY_HOPE_DERKEY
    };

    if (params.IsProtocolV3(block_time)) {
        flags |= SCRIPT_VERIFY_CHECKLOCKTIMEVERIFY;
        flags |= SCRIPT_VERIFY_NULLDUMMY;
    }

    if (params.IsProtocolV3_1(block_time)) {
        flags |= SCRIPT_VERIFY_CHECKSEQUENCEVERIFY;
    }

    // Historical HOPE did not activate Witness/Taproot through these rules.
    return flags;
}

unsigned int LockTimeFlags(const int64_t block_time, const Consensus::Params& params)
{
    return params.IsProtocolV3_1(block_time) ? LOCKTIME_VERIFY_SEQUENCE : 0;
}

} // namespace hope
