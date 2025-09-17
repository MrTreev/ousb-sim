#pragma once
#include "util.h"
#include <array>
#include <bitset>
#include <cstddef>
#include <cstdint>

#define ALIAS8(alias, register)                                                                    \
    [[nodiscard]]                                                                                  \
    uint8_t alias() const {                                                                        \
        return register();                                                                         \
    }                                                                                              \
    void alias(uint8_t val) {                                                                      \
        register(val);                                                                             \
    }

#define ALIAS16(alias, reg_lo, reg_hi)                                                             \
    [[nodiscard]]                                                                                  \
    uint16_t alias() const {                                                                       \
        return uint8_to_16(reg_hi(), reg_lo());                                                    \
    }                                                                                              \
    void alias(uint16_t val) {                                                                     \
        reg_hi(bits_hi(val));                                                                      \
        reg_lo(bits_lo(val));                                                                      \
    }

#define FULL_ALIAS(alias, reg_lo, reg_hi)                                                          \
    ALIAS8(alias##L, reg_lo)                                                                       \
    ALIAS8(alias##H, reg_hi)                                                                       \
    ALIAS16(alias, reg_lo, reg_hi)

#define NAME_BIT(name, bit)                                                                        \
    [[nodiscard]]                                                                                  \
    bool name() const {                                                                            \
        return m_vals[bit];                                                                        \
    }                                                                                              \
    void name(bool val) {                                                                          \
        m_vals[bit] = val;                                                                         \
    }

// NOLINTBEGIN(*-magic-numbers)

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
        class Sreg {
            std::bitset<8> m_vals;

        public:
            Sreg() = default;

            uint8_t operator()() const { return static_cast<uint8_t>(m_vals.to_ulong()); }

            void operator()(uint8_t val) {
                m_vals.set(7, static_cast<bool>(val & 0b10000000U));
                m_vals.set(6, static_cast<bool>(val & 0b01000000U));
                m_vals.set(5, static_cast<bool>(val & 0b00100000U));
                m_vals.set(4, static_cast<bool>(val & 0b00010000U));
                m_vals.set(3, static_cast<bool>(val & 0b00001000U));
                m_vals.set(2, static_cast<bool>(val & 0b00000100U));
                m_vals.set(1, static_cast<bool>(val & 0b00000010U));
                m_vals.set(0, static_cast<bool>(val & 0b00000001U));
            }

            NAME_BIT(I, 7)
            NAME_BIT(T, 6)
            NAME_BIT(H, 5)
            NAME_BIT(S, 4)
            NAME_BIT(V, 3)
            NAME_BIT(N, 2)
            NAME_BIT(Z, 1)
            NAME_BIT(C, 0)
        } SREG;
    } cpu;

    Reg16 SP;

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

        FULL_ALIAS(X, R26, R27)
        FULL_ALIAS(Y, R28, R29)
        FULL_ALIAS(Z, R30, R31)

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
