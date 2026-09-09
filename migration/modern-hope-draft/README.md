# Modern HOPE draft source

**UNTESTED — DO NOT RELEASE — DO NOT CONNECT TO LIVE HOPE**

This directory is the mechanical Bitcoin Core 31.1 port workspace for the existing HOPE blockchain.

It is intentionally separate from:

- the authoritative legacy source branch `hope-repair-final-20260904`; and
- the pristine pinned Bitcoin Core 31.1 `modern-core` submodule.

## Drafted

- legacy transaction timestamp serialization;
- coinstake semantics and empty staking output handling;
- PoS block signatures and PoW/PoS block classification;
- Scrypt Proof-of-Work;
- version-dependent historical block IDs;
- hybrid PoW/PoS retarget parameters;
- PoS-aware block-index metadata;
- modern UTXO stake metadata;
- stake kernel / coinstake proof module;
- HOPE main/test/regtest genesis and network identity;
- HOPE RPC/P2P port families;
- HOPE address prefixes and dev-fund identities;
- HOPE reward schedule: 10m block 1, 10 PoW, 5 PoS;
- 18% development-fund donation constant;
- historical script activation adapter.

## Not complete

- full Chainstate integration of the hybrid validation path;
- block-signature validation wiring;
- complete coinstake reward/donation validation wiring;
- mining/staking wallet integration;
- RPC and GUI integration;
- build-system overlay;
- historical-chain validation;
- LastPOWBlock resolution;
- prospective 110,000,000 HOPE maximum-supply correction.

The current mainnet `nLastPOWBlock = 100000000` value is preserved here because this is a migration, not the separate consensus-correction phase.

No file in this directory is release-ready merely because it resembles modern Bitcoin Core.
