#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

#define REGISTER_SIZE 8

#define SET_BIT(Reg,BitNo)  (  (Reg) |=  (1<<BitNo) )

#define CLR_BIT(Reg,BitNo)  (  (Reg) &= ~(1<<BitNo) )

#define TOG_BIT(Reg,BitNo)  (  (Reg) ^=  (1<<BitNo) )

#define GET_BIT(Reg,BitNo)  ( ((Reg)>> BitNo) & 0x01)

#define ROR_BIT(reg,BitNo)         reg=(reg<<(REGISTER_SIZE-BitNo))|(reg>>(BitNo))

#define ROL_BIT(reg,BitNo)         reg=(reg>>(REGISTER_SIZE-BitNo))|(reg<<(BitNo))

#endif // BIT_MATH_H_INCLUDED
