#include "instructions.h"
#include <format>
#include <stdexcept>

namespace {
std::string decode_0000_0011(uint8_t nibble_2, uint8_t nibble_3) {
    const bool    bit_2 = (nibble_2 & 0b1000U) != 0;
    const bool    bit_3 = (nibble_3 & 0b1000U) != 0;
    const uint8_t val_2 = (nibble_2 | 0b1000U);
    const uint8_t val_3 = (nibble_3 | 0b1000U);
    if (/* */ bit_2 && /* */ bit_3) return std::format("", val_2, val_3);
    if (/**/ !bit_2 && /* */ bit_3) return std::format("", val_2, val_3);
    if (/* */ bit_2 && /**/ !bit_3) return std::format("", val_2, val_3);
    if (/**/ !bit_2 && /**/ !bit_3) return std::format("", val_2, val_3);
    throw std::runtime_error("Invalid decode_0000_0011");
}

std::string decode_0000(uint16_t instruction) {
    const uint8_t nibble_1 = static_cast<uint8_t>(instruction >> 8U) & 0x0FU;
    const uint8_t nibble_2 = static_cast<uint8_t>(instruction >> 4U) & 0x0FU;
    const uint8_t nibble_3 = instruction & 0x0FU;
    switch (nibble_1) {
    case 0b0000: return "NOP";
    case 0b0001: return std::format("MOVW r{} r{}", nibble_2, nibble_3);
    case 0b0010: return std::format("MULS r{} r{}", nibble_2, nibble_3);
    case 0b0011: return decode_0000_0011(nibble_2, nibble_3);
    case 0b0100: break;
    case 0b0101: break;
    case 0b0110: break;
    case 0b0111: break;
    case 0b1000: break;
    case 0b1001: break;
    case 0b1010: break;
    case 0b1011: break;
    case 0b1100: break;
    case 0b1101: break;
    case 0b1110: break;
    case 0b1111: break;
    default:     throw std::runtime_error("Invalid instruction nibble 1");
    }
}
} // namespace

std::string decode(uint16_t instruction) {
    const uint8_t upper_nibble = instruction >> 12U;
    switch (upper_nibble) {
    case 0b0000: return decode_0000(instruction);
    case 0b0001: break;
    case 0b0010: break;
    case 0b0011: break;
    case 0b0100: break;
    case 0b0101: break;
    case 0b0110: break;
    case 0b0111: break;
    case 0b1000: break;
    case 0b1001: break;
    case 0b1010: break;
    case 0b1011: break;
    case 0b1100: break;
    case 0b1101: break;
    case 0b1110: break;
    case 0b1111: break;
    default:     throw std::runtime_error("Invalid instruction nibble 0");
    }
    return "";
}
