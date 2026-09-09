# HOPE consensus preservation manifest

**Purpose:** migration reference only.  
**Authoritative source branch:** `hope-repair-final-20260904`  
**Authoritative source commit:** `cd33f95f21fdff1bf7d00c60c9c0197fbc0af93e`

The modern client must remain on the existing HOPE blockchain. This is a software migration, not a new chain.

## Mainnet identity observed in authoritative HOPE source

- Consensus: hybrid Proof of Work + Proof of Stake
- Genesis hash: `00000270333dc42277a321c31bf0107115d8d6b551279e4c13c187a36ec6e133`
- Genesis merkle root: `ce5b6c5f10dcef789266b8c446915af0da47ab10a2572cd226b7055559a44a37`
- Genesis timestamp text: `12 02 2025 The last thing remaining was hope`
- Genesis time: `1739371451`
- Genesis nonce: `547879`
- Genesis bits: `0x1e0fffff`
- Genesis version: `1`
- Message start: `7b 85 a5 dc`
- P2P port: `22536`
- RPC port: `22535`
- CashAddr prefix: `hopium`
- P2PKH prefix: `40`
- P2SH prefix: `41`
- WIF/secret prefix: `168`
- Extended public key bytes: `04 88 b2 1e`
- Extended secret key bytes: `04 88 ad e4`
- Development-fund address: `HKFJqGeSywQeN549dhrtiUeAmGUNrjhXNh`

## Mainnet hybrid consensus observed in authoritative source

- PoW hash: Scrypt `1024_1_1_256`
- Historical block ID rule:
  - version <= 6: Scrypt PoW hash is also the block ID
  - version > 6: serialized double-SHA256 is the block ID
  - PoW remains Scrypt
- Target timespan: `3600` seconds
- Target spacing V1: `120` seconds
- Target spacing: `120` seconds
- PoW limit: `00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff`
- PoS limit: `00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff`
- PoS V2 limit: same as above
- Last-PoW parameter currently present in source: `100000000`
- Stake timestamp mask: `0x0f`
- Coinbase/stake maturity: `100`
- Maximum reorganisation depth: `500`
- Protocol times: V1-retarget `1739371451`, V2 `1739371452`, V3 `1739371453`, V3.1 `4102437600`

## Reward behaviour observed in authoritative source

- Block 1 PoW subsidy: `10,000,000 HOPE`
- Later PoW subsidy: `10 HOPE`
- PoS subsidy: `5 HOPE`
- Development-fund donation percentage constant: `18%`

These values are to be preserved during the mechanical migration. They are not declarations that the published 110,000,000 HOPE cap is already correctly enforced.

## Consensus-sensitive structures that must be ported

- version<2 transaction timestamps
- coinstake transaction semantics
- PoS block signatures
- PoW/PoS block classification
- Scrypt PoW and version-dependent block IDs
- hybrid PoW/PoS retargeting
- stake modifier/kernel logic
- PoS timestamp mask
- coinstake reward validation
- development-fund reward behaviour
- hybrid block-index proof-type/stake metadata
- historical script activation behaviour
- historical last-PoW handling as actually observed

## 110,000,000 HOPE cap and LastPOWBlock

The published 110,000,000 HOPE maximum supply is a **separate consensus-correction project**.

The current authoritative source contains `nLastPOWBlock = 100000000` on mainnet. Do not silently change this to another value during modernisation, even if other documents suggest a different intended value.

Migration rule:

1. preserve current historical behaviour;
2. reconstruct/validate actual issuance from the live chain;
3. resolve the LastPOWBlock discrepancy from chain evidence;
4. design any cap correction as a separate prospective activation;
5. never rewrite historical blocks or balances.

## Release invariant

A release candidate is unacceptable unless it validates the existing HOPE chain from the original genesis through the live tip and agrees with the authoritative chain on all historical consensus decisions.
