#pragma once

#include <cstdint>
#include <type_traits>

constexpr auto nosign(auto thing) -> std::make_unsigned_t<decltype(thing)> {
    return static_cast<std::make_unsigned_t<decltype(thing)>>(thing);
}

constexpr uint16_t uint8_to_16(uint8_t hi_val, uint8_t lo_val) {
    return (static_cast<uint16_t>(static_cast<uint16_t>(hi_val) << 8U) | lo_val);
}

constexpr uint8_t bits_hi(uint16_t val) {
    return (val >> 8U);
}

constexpr uint8_t bits_lo(uint16_t val) {
    return static_cast<uint8_t>(val | 0x00'FFU);
}
