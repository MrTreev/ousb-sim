#pragma once
#include "ousb.h"
#include <cstdint>

enum class AddressingMode : uint8_t {
    RD_SINGLE,
    RD_DOUBLE,
    IO_DIRECT,
    DATA_DIRECT,
    DATA_INDIRECT,
    DATA_INDIRECT_PRE_DEC,
    DATA_INDIRECT_POST_INC,
    DATA_INDIRECT_DISPLACE,
    PROGRAM_CONSTANT,
    PROGRAM_POST_INC,
    PROGRAM_STORE,
    PROGRAM_DIRECT,
    PROGRAM_INDIRECT,
    PROGRAM_EXTENDED,
    PROGRAM_RELATIVE,
};

template<const char* Mnemonic, uint16_t OpMask, uint16_t OpCode>
class Instruction {
    static constexpr const char* const m_mnemonic = Mnemonic;
    static constexpr uint16_t          m_op_mask  = OpMask;
    static constexpr uint16_t          m_op_code  = OpCode;
    void                               function(Ousb& ousb, uint16_t instruction) const;
};

std::string decode(uint16_t instruction);

// AVRe+
