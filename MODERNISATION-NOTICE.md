# HOPIUM MODERNISATION WORKSPACE — DO NOT RELEASE

**Status:** EXPERIMENTAL / DEVELOPMENT ONLY  
**Branch:** `modernisation/bitcoin-core-31.1-experimental-do-not-release`  
**Created:** 2026-09-09

This branch exists solely to modernise the HOPIUM (HOPE) codebase against the current stable Bitcoin Core baseline.

## Critical safety rules

- **DO NOT merge this branch into the live/default branch until the migration and consensus validation programme is complete.**
- **DO NOT build public releases or binaries from this branch.**
- **DO NOT deploy this branch to the live HOPIUM network.**
- The existing HOPIUM blockchain must be preserved. This work is a software migration, **not a new chain**.
- Genesis block, historical block acceptance, existing balances, keys/addresses, network identity, reward history and all other consensus-relevant behaviour must be preserved unless a separately specified forward-activation change is deliberately introduced and tested.
- The planned 110,000,000 HOPE maximum-supply rule must be handled separately as an explicit, reviewed, forward-activation consensus change. It must not be silently introduced during the mechanical migration.
- Before any release, the modern client must successfully validate the existing HOPIUM chain from genesis to the live tip and must not create or follow a replacement chain.

## Upstream baseline

Target upstream baseline: **Bitcoin Core v31.1** (stable release).

The first phase of this branch is an engineering import/port workspace. Upstream source will be introduced in controlled steps so that HOPIUM-specific historical and consensus behaviour can be audited and transplanted deliberately rather than overwritten blindly.

## Release gate

This branch is **NOT FOR RELEASE** until migration, historical-chain, wallet, networking, RPC and all coin-specific consensus tests have passed.
