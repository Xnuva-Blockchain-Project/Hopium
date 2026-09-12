#ifndef HOPE_CHAIN_IDENTITY_SECURITY_H
#define HOPE_CHAIN_IDENTITY_SECURITY_H

#include <string_view>

namespace hope::security {

inline constexpr std::string_view MAINNET_GENESIS =
    "00000270333dc42277a321c31bf0107115d8d6b551279e4c13c187a36ec6e133";

// These values must be obtained from and independently checked against the
// authoritative live HOPE chain before this experimental branch can be released.
inline constexpr std::string_view MAINNET_BLOCK1 = "";
inline constexpr int MAINNET_BURIED_ANCHOR_HEIGHT = -1;
inline constexpr std::string_view MAINNET_BURIED_ANCHOR = "";
inline constexpr std::string_view MAINNET_MINIMUM_CHAINWORK = "";

inline constexpr bool REQUIRE_NOT_IBD = true;
inline constexpr bool REQUIRE_PEER = true;
inline constexpr bool PROTECT_POW = true;
inline constexpr bool PROTECT_POS = true;
inline constexpr bool CHAIN_IDENTITY_QUALIFIED = false;

constexpr bool HasQualifiedChainIdentity()
{
    return CHAIN_IDENTITY_QUALIFIED &&
           MAINNET_BLOCK1.size() == 64 &&
           MAINNET_BURIED_ANCHOR_HEIGHT >= 1 &&
           MAINNET_BURIED_ANCHOR.size() == 64 &&
           MAINNET_MINIMUM_CHAINWORK.size() == 64;
}

} // namespace hope::security

#endif // HOPE_CHAIN_IDENTITY_SECURITY_H
