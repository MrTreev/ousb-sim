ATMega32A uses the AVRe+ variant of the instruction set

| BITS | BITS | BITS | BITS | Mnemonic |                                    |
|------|------|------|------|----------|------------------------------------|
| 0000 | 0000 | 0000 | 0000 | NOP      |                                    |
| 0000 | 0001 | dddd | rrrr | MOVW     |                                    |
| 0000 | 0010 | dddd | rrrr | MULS     |                                    |
| 0000 | 0011 | 0ddd | 0rrr | MULSU    |                                    |
| 0000 | 0011 | 0ddd | 1rrr | FMUL     |                                    |
| 0000 | 0011 | 1ddd | 0rrr | FMULS    |                                    |
| 0000 | 0011 | 1ddd | 1rrr | FMULSU   |                                    |
| 0000 | 01rd | dddd | rrrr | CPC      |                                    |
| 0000 | 10rd | dddd | rrrr | SBC      |                                    |
| 0000 | 11dd | dddd | dddd | LSL      | (ADD Rd,Rd)                        |
| 0000 | 11rd | dddd | rrrr | ADD      |                                    |
| 0001 | 00rd | dddd | rrrr | CPSE     |                                    |
| 0001 | 010d | dddd | 0111 | ROR      |                                    |
| 0001 | 01rd | dddd | rrrr | CP       |                                    |
| 0001 | 11dd | dddd | dddd | ROL      |                                    |
| 0001 | 11rd | dddd | rrrr | ADC      |                                    |
| 0010 | 00dd | dddd | dddd | TST      | (AND Rd,Rd)                        |
| 0010 | 00rd | dddd | rrrr | AND      |                                    |
| 0010 | 01dd | dddd | dddd | CLR      | (EOR Rd,Rd)                        |
| 0010 | 01rd | dddd | rrrr | EOR      |                                    |
| 0010 | 10rd | dddd | rrrr | OR       |                                    |
| 0010 | 11rd | dddd | rrrr | MOV      |                                    |
| 0100 | KKKK | dddd | KKKK | SBCI     |                                    |
| 0101 | KKKK | dddd | KKKK | SUBI     |                                    |
| 0110 | KKKK | dddd | KKKK | ORI      |                                    |
| 0110 | KKKK | dddd | KKKK | SBR      | (ORI Rd,K)                         |
| 0111 | KKKK | dddd | KKKK | ANDI     |                                    |
| 0111 | KKKK | dddd | KKKK | CBR      | (K Complimented)                   |
| 1000 | 000d | dddd | 0000 | LD(LDD)  | LD  Rd,  Z                         |
| 1000 | 000d | dddd | 1000 | LD(LDD)  | LD  Rd,  Y                         |
| 1000 | 001d | dddd | 0000 | ST(STD)  | ST  Rd,  Z                         |
| 1000 | 001d | dddd | 1000 | ST(STD)  | ST  Rd,  Y                         |
| 1001 | 000d | dddd | 0001 | LD(LDD)  | LD  Rd,  Z+                        |
| 1001 | 000d | dddd | 0010 | LD(LDD)  | LD  Rd, -Z                         |
| 1001 | 000d | dddd | 1001 | LD(LDD)  | LD  Rd,  Y+                        |
| 1001 | 000d | dddd | 1010 | LD(LDD)  | LD  Rd, -Y                         |
| 1001 | 000d | dddd | 1100 | LD       | LD Rd,  X                          |
| 1001 | 000d | dddd | 1101 | LD       | LD Rd,  X+                         |
| 1001 | 000d | dddd | 1110 | LD       | LD Rd, -X                          |
| 1001 | 000d | dddd | 1111 | POP      |                                    |
| 1001 | 001d | dddd | 0001 | ST(STD)  | ST  Rd,  Z+                        |
| 1001 | 001d | dddd | 0010 | ST(STD)  | ST  Rd, -Z                         |
| 1001 | 001d | dddd | 1001 | ST(STD)  | ST  Rd,  Y+                        |
| 1001 | 001d | dddd | 1010 | ST(STD)  | ST  Rd, -Y                         |
| 1001 | 001d | dddd | 1111 | PUSH     |                                    |
| 1001 | 001r | rrrr | 0100 | XCH      |                                    |
| 1001 | 001r | rrrr | 0101 | LAS      | (Not implemented in ATMega32A)     |
| 1001 | 001r | rrrr | 0110 | LAC      | (Not implemented in ATMega32A)     |
| 1001 | 001r | rrrr | 0111 | LAT      | (Not implemented in ATMega32A)     |
| 1001 | 001r | rrrr | 1100 | ST       | ST  X , Rr                         |
| 1001 | 001r | rrrr | 1101 | ST       | ST  X+, Rr                         |
| 1001 | 001r | rrrr | 1110 | ST       | ST -X , Rr                         |
| 1001 | 0100 | 0000 | 1000 | SEC      | (BSET 0)                           |
| 1001 | 0100 | 0000 | 1001 | IJMP     |                                    |
| 1001 | 0100 | 0001 | 1000 | SEZ      | (BSET 1)                           |
| 1001 | 0100 | 0001 | 1001 | EIJMP    | (Not implemented in ATMega32A)     |
| 1001 | 0100 | 0010 | 1000 | SEN      | (BSET 2)                           |
| 1001 | 0100 | 0011 | 1000 | SEV      | (BSET 3)                           |
| 1001 | 0100 | 0100 | 1000 | SES      | (BSET 4)                           |
| 1001 | 0100 | 0101 | 1000 | SEH      | (BSET 5)                           |
| 1001 | 0100 | 0110 | 1000 | SET      | (BSET 6)                           |
| 1001 | 0100 | 0111 | 1000 | SEI      | (BSET 7)                           |
| 1001 | 0100 | 0sss | 1000 | BSET     |                                    |
| 1001 | 0100 | 1000 | 1000 | CLC      | (BCLR 0)                           |
| 1001 | 0100 | 1001 | 1000 | CLZ      | (BCLR 3)                           |
| 1001 | 0100 | 1010 | 1000 | CLN      | (BCLR 2)                           |
| 1001 | 0100 | 1011 | 1000 | CLV      | (BCLR 3)                           |
| 1001 | 0100 | 1100 | 1000 | CLS      | (BCLR 4)                           |
| 1001 | 0100 | 1101 | 1000 | CLH      | (BCLR 5)                           |
| 1001 | 0100 | 1110 | 1000 | CLT      | (BCLR 6)                           |
| 1001 | 0100 | 1111 | 1000 | CLI      | (BCLR 7)                           |
| 1001 | 0100 | 1sss | 1000 | BCLR     |                                    |
| 1001 | 0100 | KKKK | 1011 | DES      | (Not implemented in ATMega32A)     |
| 1001 | 0101 | 0000 | 1000 | RET      |                                    |
| 1001 | 0101 | 0000 | 1001 | ICALL    |                                    |
| 1001 | 0101 | 0001 | 1000 | RETI     |                                    |
| 1001 | 0101 | 0001 | 1001 | EICALL   | (Not implemented in ATMega32A)     |
| 1001 | 0101 | 1000 | 1000 | SLEEP    |                                    |
| 1001 | 0101 | 1001 | 1000 | BREAK    |                                    |
| 1001 | 0101 | 1010 | 1000 | WDR      |                                    |
| 1001 | 0101 | 1100 | 1000 | LPM      | LPM                                |
| 1001 | 0101 | 1101 | 1000 | ELPM     | (Not implemented in ATMega32A)     |
| 1001 | 0101 | 1110 | 1000 | SPM      |                                    |
| 1001 | 010d | dddd | 0000 | COM      |                                    |
| 1001 | 010d | dddd | 0000 | LDS      | kkkk kkkk kkkk kkkk                |
| 1001 | 010d | dddd | 0001 | NEG      |                                    |
| 1001 | 010d | dddd | 0010 | SWAP     |                                    |
| 1001 | 010d | dddd | 0011 | INC      |                                    |
| 1001 | 010d | dddd | 0100 | LPM      | LPM, Z                             |
| 1001 | 010d | dddd | 0101 | ASR      |                                    |
| 1001 | 010d | dddd | 0101 | LPM      | LPM, Z+                            |
| 1001 | 010d | dddd | 0110 | ELPM     | (Not implemented in ATMega32A)     |
| 1001 | 010d | dddd | 0110 | LSR      |                                    |
| 1001 | 010d | dddd | 0111 | ELPM     | (Not implemented in ATMega32A)     |
| 1001 | 010d | dddd | 1010 | DEC      |                                    |
| 1001 | 010k | kkkk | 110k | JMP      | kkkk kkkk kkkk kkkk                |
| 1001 | 010k | kkkk | 111k | CALL     | kkkk kkkk kkkk kkkk                |
| 1001 | 0110 | KKdd | KKKK | ADIW     |                                    |
| 1001 | 0111 | KKdd | KKKK | SBIW     |                                    |
| 1001 | 1000 | AAAA | Abbb | CBI      |                                    |
| 1001 | 1001 | AAAA | Abbb | SBIC     |                                    |
| 1001 | 1010 | AAAA | Abbb | SBI      |                                    |
| 1001 | 1011 | AAAA | Abbb | SBIS     |                                    |
| 1001 | 11rd | dddd | rrrr | MUL      |                                    |
| 1011 | 0AAd | dddd | AAAA | IN       |                                    |
| 1011 | 1AAr | rrrr | AAAA | OUT      |                                    |
| 10q0 | qq0d | dddd | 0qqq | LD(LDD)  | LDD Rd,  Z+q                       |
| 10q0 | qq0d | dddd | 1qqq | LD(LDD)  | LDD Rd,  Y+q                       |
| 10q0 | qq1d | dddd | 0qqq | ST(STD)  | STD Rd,  Z+q                       |
| 10q0 | qq1d | dddd | 1qqq | ST(STD)  | STD Rd,  Y+q                       |
| 1100 | kkkk | kkkk | kkkk | RJMP     |                                    |
| 1101 | 001d | dddd | 0000 | STS      | kkkk kkkk kkkk kkkk                |
| 1101 | kkkk | kkkk | kkkk | RCALL    |                                    |
| 1110 | 1111 | dddd | 1111 | SER      | (LDI Rd,0xFF)                      |
| 1110 | KKKK | dddd | KKKK | LDI      |                                    |
| 1111 | 00kk | kkkk | k000 | BRCS     | (BRBS 0,k)                         |
| 1111 | 00kk | kkkk | k000 | BRLO     | (BRBS 0,k)                         |
| 1111 | 00kk | kkkk | k001 | BREQ     | (BRBS 1,k)                         |
| 1111 | 00kk | kkkk | k010 | BRMI     | (BRBS 2.k)                         |
| 1111 | 00kk | kkkk | k011 | BRVS     | (BRBS 3,k)                         |
| 1111 | 00kk | kkkk | k100 | BRLT     | (BRBS 4,k)                         |
| 1111 | 00kk | kkkk | k101 | BRHS     | (BRBS 5,k)                         |
| 1111 | 00kk | kkkk | k110 | BRTS     | (BRBS 6,k)                         |
| 1111 | 00kk | kkkk | k111 | BRIE     | (BRBS 7,k)                         |
| 1111 | 00kk | kkkk | ksss | BRBS     |                                    |
| 1111 | 01kk | kkkk | k000 | BRCC     | (BRBC 0,k)                         |
| 1111 | 01kk | kkkk | k000 | BRSH     | (BRBC 0,k)                         |
| 1111 | 01kk | kkkk | k001 | BRNE     | (BRBC 1,k)                         |
| 1111 | 01kk | kkkk | k010 | BRPL     | (BRBC 2,k)                         |
| 1111 | 01kk | kkkk | k011 | BRVC     | (BRBC 3,k)                         |
| 1111 | 01kk | kkkk | k100 | BRGE     | (BRBC 4,k)                         |
| 1111 | 01kk | kkkk | k101 | BRHC     | (BRBC 5,k)                         |
| 1111 | 01kk | kkkk | k110 | BRTC     | (BRBC 6,k)                         |
| 1111 | 01kk | kkkk | k111 | BRID     | (BRBC 7,k)                         |
| 1111 | 01kk | kkkk | ksss | BRBC     |                                    |
| 1111 | 100d | dddd | 0bbb | BLD      |                                    |
| 1111 | 101d | dddd | 0bbb | BST      |                                    |
| 1111 | 110r | rrrr | 0bbb | SBRC     |                                    |
| 1111 | 111r | rrrr | 0bbb | SBRS     |                                    |
