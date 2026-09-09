# HOPE Bitcoin Core 31.1 modernisation status

**Branch:** `modernisation/bitcoin-core-31.1-experimental-do-not-release`  
**Consensus:** hybrid PoW + PoS  
**Release status:** **UNTESTED / DO NOT RELEASE**

## Completed

- Authoritative source fixed to `hope-repair-final-20260904` at commit `cd33f95f21fdff1bf7d00c60c9c0197fbc0af93e`.
- Bitcoin Core v31.1 pinned at commit `9be056a8a72b624dae9623b2f7bded92c2a21c91`.
- Full Bitcoin Core v31.1 source available as pinned `modern-core` submodule.
- HOPE hybrid PoW/PoS operation confirmed from source.
- HOPE consensus-preservation manifest recorded.
- The current `nLastPOWBlock = 100000000` value is explicitly preserved during migration.
- Published 110m maximum-supply correction remains separate from mechanical modernisation.

## Mechanical port sequence

1. Preserve HOPE transaction/block serialization.
2. Preserve Scrypt PoW and version-dependent block IDs.
3. Port hybrid PoW/PoS parameters and retargeting.
4. Port PoS block-index metadata and stake modifier.
5. Port stake kernel / coinstake validation.
6. Port genesis, network magic, ports and address identity.
7. Port reward/donation accounting exactly as current source.
8. Integrate hybrid validation into Bitcoin Core 31.1 Chainstate.
9. Port mining, staking, wallet and RPC surfaces.
10. Branding/packaging.
11. Build and validate the existing chain from genesis to live tip.
12. Separately resolve LastPOWBlock and the prospective 110,000,000 HOPE cap.

## Hard gate

Nothing on this branch may be merged to the authoritative branch, released, or used as a live authoritative node until the historical-chain compatibility programme passes.
