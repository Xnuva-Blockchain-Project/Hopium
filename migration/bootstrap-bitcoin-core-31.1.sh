#!/usr/bin/env bash
set -euo pipefail

# HOPE modernisation bootstrap
# DEVELOPMENT ONLY — DO NOT DEPLOY TO THE LIVE HOPE NETWORK.

UPSTREAM_REPO="https://github.com/bitcoin/bitcoin.git"
UPSTREAM_TAG="v31.1"
UPSTREAM_COMMIT="9be056a8a72b624dae9623b2f7bded92c2a21c91"
DEST="${1:-modern-hope-worktree}"

if [[ -e "$DEST" ]]; then
    echo "STOP: destination already exists: $DEST" >&2
    exit 1
fi

git clone --filter=blob:none --no-checkout "$UPSTREAM_REPO" "$DEST"
git -C "$DEST" checkout --detach "$UPSTREAM_TAG"

actual="$(git -C "$DEST" rev-parse HEAD)"
if [[ "$actual" != "$UPSTREAM_COMMIT" ]]; then
    echo "STOP: upstream commit mismatch" >&2
    echo "expected: $UPSTREAM_COMMIT" >&2
    echo "actual:   $actual" >&2
    exit 1
fi

cat <<'EOF'
Bitcoin Core v31.1 baseline materialised for the HOPE migration workspace.

Overlay source lives under:
  migration/modern-hope-draft/

Authoritative HOPE source:
  hope-repair-final-20260904
  cd33f95f21fdff1bf7d00c60c9c0197fbc0af93e

DO NOT run this unfinished tree against the live HOPE network.
DO NOT publish binaries from this tree.
EOF
