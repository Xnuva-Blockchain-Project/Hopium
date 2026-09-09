// HOPE legacy consensus rule adapter for Bitcoin Core 31.1.
// UNTESTED / DO NOT RELEASE.
#ifndef HOPE_CONSENSUS_RULES_H
#define HOPE_CONSENSUS_RULES_H

#include <consensus/amount.h>
#include <script/verify_flags.h>

#include <cstdint>

namespace Consensus { struct Params; }

namespace hope {

inline constexpr unsigned int DONATION_PERCENTAGE{18};

CAmount ProofOfWorkSubsidy(int height);
CAmount ProofOfStakeSubsidy();

// Historical HOPE script flags are time-based, not Bitcoin buried-deployment heights.
script_verify_flags ScriptVerifyFlags(int64_t block_time, const Consensus::Params& params);

// Historical HOPE enables BIP68 sequence locks only at protocol-v3.1.
unsigned int LockTimeFlags(int64_t block_time, const Consensus::Params& params);

} // namespace hope

#endif // HOPE_CONSENSUS_RULES_H
