// HOPE prospective supply-cap consensus helpers.
// UNTESTED / DO NOT RELEASE.
#ifndef HOPE_SUPPLY_CAP_H
#define HOPE_SUPPLY_CAP_H

#include <consensus/amount.h>

namespace Consensus { struct Params; }

namespace hope {

CAmount NetNewPoWIssuance(CAmount coinbase_value, CAmount fees);
CAmount NetNewPoSIssuance(CAmount actual_stake_reward, CAmount fees);
CAmount RemainingMintableSupply(CAmount previous_issued, const Consensus::Params& params);
CAmount LimitSubsidyBySupplyCap(int height,
                               CAmount previous_issued,
                               CAmount scheduled_subsidy,
                               const Consensus::Params& params);
bool CheckSupplyCap(int height,
                    CAmount previous_issued,
                    CAmount block_net_new_issuance,
                    const Consensus::Params& params);
CAmount NextIssuedSupply(CAmount previous_issued, CAmount block_net_new_issuance);

} // namespace hope

#endif // HOPE_SUPPLY_CAP_H
