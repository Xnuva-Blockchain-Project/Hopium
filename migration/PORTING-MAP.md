# HOPE -> Bitcoin Core 31.1 porting map

HOPE is structurally very close to Zeus in the legacy trees, but this port uses HOPE's own authoritative source as the consensus oracle.

| Legacy HOPE area | Modern target | Required action |
|---|---|---|
| `src/primitives/transaction.*` | modern transaction primitives | preserve legacy transaction timestamp and coinstake semantics |
| `src/primitives/block.*` | modern block primitives | preserve block signature, hybrid classification, Scrypt/version hash rules |
| `src/consensus/params.h` | modern consensus params | add HOPE hybrid timing, PoS and last-PoW fields |
| `src/pow.*` | modern pow module | preserve per-proof-type hybrid retarget |
| `src/pos.*` | HOPE PoS module | port stake modifier, kernel and coinstake proof |
| `src/chain.*` | modern block index | preserve proof-type/stake metadata without colliding with modern status bits |
| `src/chainparams.*` | modern kernel chainparams | preserve genesis, magic, ports, prefixes and dev-fund identity |
| `src/main.cpp` consensus paths | modern validation/Chainstate | re-home HOPE block/PoS/reward checks |
| `src/miner.cpp` | modern mining/wallet | port PoW construction and PoS staking after consensus core |
| reward/donation code | HOPE consensus adapter | preserve 10m block-1, 10 PoW, 5 PoS, 18% donation |

## Non-negotiable

If modern Bitcoin behaviour conflicts with an already-established HOPE historical consensus rule, the historical HOPE rule wins for existing history.
