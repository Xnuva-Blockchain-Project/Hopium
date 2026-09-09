// HOPE prospective supply-cap consensus helpers.
// UNTESTED / DO NOT RELEASE.
#ifndef HOPE_SUPPLY_CAP_H
#define HOPE_SUPPLY_CAP_H

#include <consensus/amount.h>

class CBlockIndex;
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

/**
 * Validate the block's actual net new issuance and record cumulative issued
 * supply in its modern CBlockIndex entry.
 *
 * For PoW pass coinbase_value and actual_stake_reward=0.
 * For PoS pass actual_stake_reward and coinbase_value=0.
 */
bool ValidateAndRecordSupply(CBlockIndex& index,
                             bool proof_of_stake,
                             CAmount coinbase_value,
                             CAmount actual_stake_reward,
                             CAmount fees,
                             const Consensus::Params& params);

} // namespace hope

#endif // HOPE_SUPPLY_CAP_H
