#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

// NOLINTBEGIN(*-magic-numbers)

constexpr uint16_t uint8_to_16(uint8_t hi_val, uint8_t lo_val) {
    return (static_cast<uint16_t>(static_cast<uint16_t>(hi_val) << 8U) | lo_val);
}

constexpr uint8_t bits_hi(uint16_t val) {
    return (val >> 8U);
}

constexpr uint8_t bits_lo(uint16_t val) {
    return static_cast<uint8_t>(val | 0x00'FFU);
}

class Reg8 {
    uint8_t m_val{0};

public:
    Reg8() = default;

    explicit Reg8(uint8_t val)
        : m_val(val) {}

    uint8_t operator()() const { return m_val; }

    void operator()(uint8_t val) { m_val = val; }
};

class Reg16 {
    std::array<uint8_t, 2> m_val{};

public:
    Reg16() = default;

    Reg16(uint8_t hi_val, uint8_t lo_val)
        : m_val({hi_val, lo_val}) {}

    explicit Reg16(uint16_t val)
        : m_val({bits_hi(val), bits_lo(val)}) {}

    void operator()(uint16_t val) {
        m_val[0] = bits_hi(val);
        m_val[1] = bits_lo(val);
    }

    void hi(uint8_t val) { m_val[0] = val; }

    void lo(uint8_t val) { m_val[1] = val; }

    [[nodiscard]]
    uint16_t operator()() const {
        return uint8_to_16(hi(), lo());
    }

    [[nodiscard]]
    uint8_t hi() const {
        return m_val[0];
    }

    [[nodiscard]]
    uint8_t lo() const {
        return m_val[1];
    }
};

class Ousb {
public:
    static constexpr size_t flash_size = 0x3F'FFU;
    static constexpr size_t sram_size  = 0x3F'FFU;

    struct {
        Reg8 R0;
        Reg8 R1;
        Reg8 R2;
        Reg8 R3;
        Reg8 R4;
        Reg8 R5;
        Reg8 R6;
        Reg8 R7;
        Reg8 R8;
        Reg8 R9;
        Reg8 R10;
        Reg8 R11;
        Reg8 R12;
        Reg8 R13;
        Reg8 R14;
        Reg8 R15;
        Reg8 R16;
        Reg8 R17;
        Reg8 R18;
        Reg8 R19;
        Reg8 R20;
        Reg8 R21;
        Reg8 R22;
        Reg8 R23;
        Reg8 R24;
        Reg8 R25;
        Reg8 R26;
        Reg8 R27;
        Reg8 R28;
        Reg8 R29;
        Reg8 R30;
        Reg8 R31;

        [[nodiscard]]
        uint16_t X() const {
            return uint8_to_16(R26(), R27());
        }

        void X(uint16_t val) {
            R26(bits_hi(val));
            R27(bits_lo(val));
        }

    } registers;

    struct {
        Reg16 EEAR{0xFF'FFU};
        Reg8  EEDR;
        Reg8  EECR;
    } io_registers;

    Reg16 stack_pointer;

    std::array<uint8_t, flash_size> flash{};
    std::array<uint8_t, sram_size>  sram{};
};
