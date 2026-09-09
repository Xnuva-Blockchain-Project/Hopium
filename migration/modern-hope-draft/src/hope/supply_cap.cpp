// HOPE prospective supply-cap consensus helpers.
// UNTESTED / DO NOT RELEASE.

#include <hope/supply_cap.h>

#include <algorithm>
#include <consensus/params.h>

namespace hope {

CAmount NetNewPoWIssuance(const CAmount coinbase_value, const CAmount fees)
{
    return std::max<CAmount>(0, coinbase_value - fees);
}

CAmount NetNewPoSIssuance(const CAmount actual_stake_reward, const CAmount fees)
{
    return std::max<CAmount>(0, actual_stake_reward - fees);
}

CAmount RemainingMintableSupply(const CAmount previous_issued, const Consensus::Params& params)
{
    if (params.nMaxMoneySupply <= 0) return 0;
    if (previous_issued >= params.nMaxMoneySupply) return 0;
    return params.nMaxMoneySupply - previous_issued;
}

CAmount LimitSubsidyBySupplyCap(const int height,
                               const CAmount previous_issued,
                               const CAmount scheduled_subsidy,
                               const Consensus::Params& params)
{
    if (!params.IsSupplyCapActive(height)) return scheduled_subsidy;
    return std::min(scheduled_subsidy, RemainingMintableSupply(previous_issued, params));
}

bool CheckSupplyCap(const int height,
                    const CAmount previous_issued,
                    const CAmount block_net_new_issuance,
                    const Consensus::Params& params)
{
    if (block_net_new_issuance < 0) return false;
    if (!params.IsSupplyCapActive(height)) return true;

    if (previous_issued >= params.nMaxMoneySupply) {
        return block_net_new_issuance == 0;
    }

    return block_net_new_issuance <= (params.nMaxMoneySupply - previous_issued);
}

CAmount NextIssuedSupply(const CAmount previous_issued, const CAmount block_net_new_issuance)
{
    return previous_issued + std::max<CAmount>(0, block_net_new_issuance);
}

} // namespace hope
