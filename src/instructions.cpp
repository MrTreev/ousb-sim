#include "instructions.h"
#include <cstdint>
#include <format>
#include <stdexcept>

namespace {
constexpr uint8_t d_val(uint8_t nib1, uint8_t nib2) {
    return static_cast<uint8_t>(nib2 + ((nib1 & 0b0001U) << 4U));
}

constexpr uint8_t r_val(uint8_t nib1, uint8_t nib3) {
    return static_cast<uint8_t>(nib3 + ((nib1 & 0b0010U) << 3U));
}
} // namespace

std::string decode(uint16_t instruction) {
    const uint8_t byte0 = instruction >> 8U;
    const uint8_t nib1  = static_cast<uint8_t>(instruction >> 8U) & 0x0FU;
    const uint8_t nib2  = static_cast<uint8_t>(instruction >> 4U) & 0x0FU;
    const uint8_t nib3  = instruction & 0x0FU;
    switch (byte0) {
    // 0000'0000'0000'0000: NOP
    case 0b0000'0000: return "NOP";
    // 0000'0001'dddd'rrrr: MOVW Rd, Rr
    case 0b0000'0001: return std::format("MOVW r{} r{}", nib2, nib3);
    // 0000'0010'dddd'rrrr: MULS Rd, Rr
    case 0b0000'0010: return std::format("MULS r{} r{}", nib2, nib3);
    // 0000'0011'0ddd'0rrr: MULSU  Rd, Rr
    // 0000'0011'0ddd'1rrr: FMUL   Rd, Rr
    // 0000'0011'1ddd'0rrr: FMULS  Rd, Rr
    // 0000'0011'1ddd'1rrr: FMULSU Rd, Rr
    case 0b0000'0011:
        switch (((nib2 & 0b1000U) >> 2U) | ((nib3 & 0b1000U) >> 3U)) {
        case 0b00: return std::format("MULSU r{}, r{}", (nib2 | 0b1000U), (nib3 | 0b1000U));
        case 0b01: return std::format("FMUL r{}, r{}", (nib2 | 0b1000U), (nib3 | 0b1000U));
        case 0b10: return std::format("FMULS r{}, r{}", (nib2 | 0b1000U), (nib3 | 0b1000U));
        case 0b11: return std::format("FMULSU r{}, r{}", (nib2 | 0b1000U), (nib3 | 0b1000U));
        default:   throw std::runtime_error("Invalid decode_0000_0011");
        }
    // 0000'01rd'dddd'rrrr: CPC Rd, Rr
    case 0b0000'0100: [[fallthrough]];
    case 0b0000'0101: [[fallthrough]];
    case 0b0000'0110: [[fallthrough]];
    case 0b0000'0111: return std::format("CPC {}, {}", d_val(nib1, nib2), r_val(nib1, nib3));
    // 0000'10rd'dddd'rrrr: SBC Rd, Rr
    case 0b0000'1000: [[fallthrough]];
    case 0b0000'1001: [[fallthrough]];
    case 0b0000'1010: [[fallthrough]];
    case 0b0000'1011: return std::format("SBC {}, {}", d_val(nib1, nib2), r_val(nib1, nib3));
    // 0000'11dd'dddd'dddd: LSL Rd, Rd
    // 0000'11rd'dddd'rrrr: ADD Rd, Rr
    case 0b0000'1100: [[fallthrough]];
    case 0b0000'1101: [[fallthrough]];
    case 0b0000'1110: [[fallthrough]];
    case 0b0000'1111:
        if (nib2 == nib3 && (nib1 & 0b0001U) == ((nib1 & 0b0010U) >> 1U))
            return std::format("LSL {}", d_val(nib1, nib2));
        return std::format("ADD {}, {}", d_val(nib1, nib2), r_val(nib1, nib3));
    // 0001'00rd'dddd'rrrr: CPSE
    case 0b0001'0000: break;
    case 0b0001'0001: break;
    case 0b0001'0010: break;
    case 0b0001'0011: break;
    case 0b0001'0100: break;
    case 0b0001'0101: break;
    case 0b0001'0110: break;
    case 0b0001'0111: break;
    case 0b0001'1000: break;
    case 0b0001'1001: break;
    case 0b0001'1010: break;
    case 0b0001'1011: break;
    case 0b0001'1100: break;
    case 0b0001'1101: break;
    case 0b0001'1110: break;
    case 0b0001'1111: break;
    case 0b0010'0000: break;
    case 0b0010'0001: break;
    case 0b0010'0010: break;
    case 0b0010'0011: break;
    case 0b0010'0100: break;
    case 0b0010'0101: break;
    case 0b0010'0110: break;
    case 0b0010'0111: break;
    case 0b0010'1000: break;
    case 0b0010'1001: break;
    case 0b0010'1010: break;
    case 0b0010'1011: break;
    case 0b0010'1100: break;
    case 0b0010'1101: break;
    case 0b0010'1110: break;
    case 0b0010'1111: break;
    case 0b0011'0000: break;
    case 0b0011'0001: break;
    case 0b0011'0010: break;
    case 0b0011'0011: break;
    case 0b0011'0100: break;
    case 0b0011'0101: break;
    case 0b0011'0110: break;
    case 0b0011'0111: break;
    case 0b0011'1000: break;
    case 0b0011'1001: break;
    case 0b0011'1010: break;
    case 0b0011'1011: break;
    case 0b0011'1100: break;
    case 0b0011'1101: break;
    case 0b0011'1110: break;
    case 0b0011'1111: break;
    case 0b0100'0000: break;
    case 0b0100'0001: break;
    case 0b0100'0010: break;
    case 0b0100'0011: break;
    case 0b0100'0100: break;
    case 0b0100'0101: break;
    case 0b0100'0110: break;
    case 0b0100'0111: break;
    case 0b0100'1000: break;
    case 0b0100'1001: break;
    case 0b0100'1010: break;
    case 0b0100'1011: break;
    case 0b0100'1100: break;
    case 0b0100'1101: break;
    case 0b0100'1110: break;
    case 0b0100'1111: break;
    case 0b0101'0000: break;
    case 0b0101'0001: break;
    case 0b0101'0010: break;
    case 0b0101'0011: break;
    case 0b0101'0100: break;
    case 0b0101'0101: break;
    case 0b0101'0110: break;
    case 0b0101'0111: break;
    case 0b0101'1000: break;
    case 0b0101'1001: break;
    case 0b0101'1010: break;
    case 0b0101'1011: break;
    case 0b0101'1100: break;
    case 0b0101'1101: break;
    case 0b0101'1110: break;
    case 0b0101'1111: break;
    case 0b0110'0000: break;
    case 0b0110'0001: break;
    case 0b0110'0010: break;
    case 0b0110'0011: break;
    case 0b0110'0100: break;
    case 0b0110'0101: break;
    case 0b0110'0110: break;
    case 0b0110'0111: break;
    case 0b0110'1000: break;
    case 0b0110'1001: break;
    case 0b0110'1010: break;
    case 0b0110'1011: break;
    case 0b0110'1100: break;
    case 0b0110'1101: break;
    case 0b0110'1110: break;
    case 0b0110'1111: break;
    case 0b0111'0000: break;
    case 0b0111'0001: break;
    case 0b0111'0010: break;
    case 0b0111'0011: break;
    case 0b0111'0100: break;
    case 0b0111'0101: break;
    case 0b0111'0110: break;
    case 0b0111'0111: break;
    case 0b0111'1000: break;
    case 0b0111'1001: break;
    case 0b0111'1010: break;
    case 0b0111'1011: break;
    case 0b0111'1100: break;
    case 0b0111'1101: break;
    case 0b0111'1110: break;
    case 0b0111'1111: break;
    case 0b1000'0000: break;
    case 0b1000'0001: break;
    case 0b1000'0010: break;
    case 0b1000'0011: break;
    case 0b1000'0100: break;
    case 0b1000'0101: break;
    case 0b1000'0110: break;
    case 0b1000'0111: break;
    case 0b1000'1000: break;
    case 0b1000'1001: break;
    case 0b1000'1010: break;
    case 0b1000'1011: break;
    case 0b1000'1100: break;
    case 0b1000'1101: break;
    case 0b1000'1110: break;
    case 0b1000'1111: break;
    case 0b1001'0000: break;
    case 0b1001'0001: break;
    case 0b1001'0010: break;
    case 0b1001'0011: break;
    case 0b1001'0100: break;
    case 0b1001'0101: break;
    case 0b1001'0110: break;
    case 0b1001'0111: break;
    case 0b1001'1000: break;
    case 0b1001'1001: break;
    case 0b1001'1010: break;
    case 0b1001'1011: break;
    case 0b1001'1100: break;
    case 0b1001'1101: break;
    case 0b1001'1110: break;
    case 0b1001'1111: break;
    case 0b1010'0000: break;
    case 0b1010'0001: break;
    case 0b1010'0010: break;
    case 0b1010'0011: break;
    case 0b1010'0100: break;
    case 0b1010'0101: break;
    case 0b1010'0110: break;
    case 0b1010'0111: break;
    case 0b1010'1000: break;
    case 0b1010'1001: break;
    case 0b1010'1010: break;
    case 0b1010'1011: break;
    case 0b1010'1100: break;
    case 0b1010'1101: break;
    case 0b1010'1110: break;
    case 0b1010'1111: break;
    case 0b1011'0000: break;
    case 0b1011'0001: break;
    case 0b1011'0010: break;
    case 0b1011'0011: break;
    case 0b1011'0100: break;
    case 0b1011'0101: break;
    case 0b1011'0110: break;
    case 0b1011'0111: break;
    case 0b1011'1000: break;
    case 0b1011'1001: break;
    case 0b1011'1010: break;
    case 0b1011'1011: break;
    case 0b1011'1100: break;
    case 0b1011'1101: break;
    case 0b1011'1110: break;
    case 0b1011'1111: break;
    case 0b1100'0000: break;
    case 0b1100'0001: break;
    case 0b1100'0010: break;
    case 0b1100'0011: break;
    case 0b1100'0100: break;
    case 0b1100'0101: break;
    case 0b1100'0110: break;
    case 0b1100'0111: break;
    case 0b1100'1000: break;
    case 0b1100'1001: break;
    case 0b1100'1010: break;
    case 0b1100'1011: break;
    case 0b1100'1100: break;
    case 0b1100'1101: break;
    case 0b1100'1110: break;
    case 0b1100'1111: break;
    case 0b1101'0000: break;
    case 0b1101'0001: break;
    case 0b1101'0010: break;
    case 0b1101'0011: break;
    case 0b1101'0100: break;
    case 0b1101'0101: break;
    case 0b1101'0110: break;
    case 0b1101'0111: break;
    case 0b1101'1000: break;
    case 0b1101'1001: break;
    case 0b1101'1010: break;
    case 0b1101'1011: break;
    case 0b1101'1100: break;
    case 0b1101'1101: break;
    case 0b1101'1110: break;
    case 0b1101'1111: break;
    case 0b1110'0000: break;
    case 0b1110'0001: break;
    case 0b1110'0010: break;
    case 0b1110'0011: break;
    case 0b1110'0100: break;
    case 0b1110'0101: break;
    case 0b1110'0110: break;
    case 0b1110'0111: break;
    case 0b1110'1000: break;
    case 0b1110'1001: break;
    case 0b1110'1010: break;
    case 0b1110'1011: break;
    case 0b1110'1100: break;
    case 0b1110'1101: break;
    case 0b1110'1110: break;
    case 0b1110'1111: break;
    case 0b1111'0000: break;
    case 0b1111'0001: break;
    case 0b1111'0010: break;
    case 0b1111'0011: break;
    case 0b1111'0100: break;
    case 0b1111'0101: break;
    case 0b1111'0110: break;
    case 0b1111'0111: break;
    case 0b1111'1000: break;
    case 0b1111'1001: break;
    case 0b1111'1010: break;
    case 0b1111'1011: break;
    case 0b1111'1100: break;
    case 0b1111'1101: break;
    case 0b1111'1110: break;
    case 0b1111'1111: break;
    default:          throw std::runtime_error("Invalid instruction nibble 0");
    }
    return "";
}

/*
0001'010d'dddd'0111: ROR
0001'01rd'dddd'rrrr: CP
0001'11dd'dddd'dddd: ROL
0001'11rd'dddd'rrrr: ADC
0010'00dd'dddd'dddd: TST
0010'00rd'dddd'rrrr: AND
0010'01dd'dddd'dddd: CLR
0010'01rd'dddd'rrrr: EOR
0010'10rd'dddd'rrrr: OR
0010'11rd'dddd'rrrr: MOV
0100'KKKK'dddd'KKKK: SBCI
0101'KKKK'dddd'KKKK: SUBI
0110'KKKK'dddd'KKKK: ORI
0110'KKKK'dddd'KKKK: SBR
0111'KKKK'dddd'KKKK: ANDI
0111'KKKK'dddd'KKKK: CBR
1000'000d'dddd'0000: LD(LDD)
1000'000d'dddd'1000: LD(LDD)
1000'001d'dddd'0000: ST(STD)
1000'001d'dddd'1000: ST(STD)
1001'000d'dddd'0001: LD(LDD)
1001'000d'dddd'0010: LD(LDD)
1001'000d'dddd'1001: LD(LDD)
1001'000d'dddd'1010: LD(LDD)
1001'000d'dddd'1100: LD
1001'000d'dddd'1101: LD
1001'000d'dddd'1110: LD
1001'000d'dddd'1111: POP
1001'001d'dddd'0001: ST(STD)
1001'001d'dddd'0010: ST(STD)
1001'001d'dddd'1001: ST(STD)
1001'001d'dddd'1010: ST(STD)
1001'001d'dddd'1111: PUSH
1001'001r'rrrr'0100: XCH
1001'001r'rrrr'0101: LAS
1001'001r'rrrr'0110: LAC
1001'001r'rrrr'0111: LAT
1001'001r'rrrr'1100: ST
1001'001r'rrrr'1101: ST
1001'001r'rrrr'1110: ST
1001'0100'0000'1000: SEC
1001'0100'0000'1001: IJMP
1001'0100'0001'1000: SEZ
1001'0100'0001'1001: EIJMP
1001'0100'0010'1000: SEN
1001'0100'0011'1000: SEV
1001'0100'0100'1000: SES
1001'0100'0101'1000: SEH
1001'0100'0110'1000: SET
1001'0100'0111'1000: SEI
1001'0100'0sss'1000: BSET
1001'0100'1000'1000: CLC
1001'0100'1001'1000: CLZ
1001'0100'1010'1000: CLN
1001'0100'1011'1000: CLV
1001'0100'1100'1000: CLS
1001'0100'1101'1000: CLH
1001'0100'1110'1000: CLT
1001'0100'1111'1000: CLI
1001'0100'1sss'1000: BCLR
1001'0100'KKKK'1011: DES
1001'0101'0000'1000: RET
1001'0101'0000'1001: ICALL
1001'0101'0001'1000: RETI
1001'0101'0001'1001: EICALL
1001'0101'1000'1000: SLEEP
1001'0101'1001'1000: BREAK
1001'0101'1010'1000: WDR
1001'0101'1100'1000: LPM
1001'0101'1101'1000: ELPM
1001'0101'1110'1000: SPM
1001'010d'dddd'0000: COM
1001'010d'dddd'0000: LDS
1001'010d'dddd'0001: NEG
1001'010d'dddd'0010: SWAP
1001'010d'dddd'0011: INC
1001'010d'dddd'0100: LPM
1001'010d'dddd'0101: ASR
1001'010d'dddd'0101: LPM
1001'010d'dddd'0110: ELPM
1001'010d'dddd'0110: LSR
1001'010d'dddd'0111: ELPM
1001'010d'dddd'1010: DEC
1001'010k'kkkk'110k: JMP
1001'010k'kkkk'111k: CALL
1001'0110'KKdd'KKKK: ADIW
1001'0111'KKdd'KKKK: SBIW
1001'1000'AAAA'Abbb: CBI
1001'1001'AAAA'Abbb: SBIC
1001'1010'AAAA'Abbb: SBI
1001'1011'AAAA'Abbb: SBIS
1001'11rd'dddd'rrrr: MUL
1011'0AAd'dddd'AAAA: IN
1011'1AAr'rrrr'AAAA: OUT
10q0'qq0d'dddd'0qqq: LD(LDD)
10q0'qq0d'dddd'1qqq: LD(LDD)
10q0'qq1d'dddd'0qqq: ST(STD)
10q0'qq1d'dddd'1qqq: ST(STD)
1100'kkkk'kkkk'kkkk: RJMP
1101'001d'dddd'0000: STS
1101'kkkk'kkkk'kkkk: RCALL
1110'1111'dddd'1111: SER
1110'KKKK'dddd'KKKK: LDI
1111'00kk'kkkk'k000: BRCS
1111'00kk'kkkk'k000: BRLO
1111'00kk'kkkk'k001: BREQ
1111'00kk'kkkk'k010: BRMI
1111'00kk'kkkk'k011: BRVS
1111'00kk'kkkk'k100: BRLT
1111'00kk'kkkk'k101: BRHS
1111'00kk'kkkk'k110: BRTS
1111'00kk'kkkk'k111: BRIE
1111'00kk'kkkk'ksss: BRBS
1111'01kk'kkkk'k000: BRCC
1111'01kk'kkkk'k000: BRSH
1111'01kk'kkkk'k001: BRNE
1111'01kk'kkkk'k010: BRPL
1111'01kk'kkkk'k011: BRVC
1111'01kk'kkkk'k100: BRGE
1111'01kk'kkkk'k101: BRHC
1111'01kk'kkkk'k110: BRTC
1111'01kk'kkkk'k111: BRID
1111'01kk'kkkk'ksss: BRBC
1111'100d'dddd'0bbb: BLD
1111'101d'dddd'0bbb: BST
1111'110r'rrrr'0bbb: SBRC
1111'111r'rrrr'0bbb: SBRS
 */
