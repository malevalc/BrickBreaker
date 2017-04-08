#ifndef ALPHABET_H
#define	ALPHABET_H

#include <p18f4550.h>
#include <delays.h>
#include "ks108.h"
#include "data.h"

void write_c(unsigned char x, unsigned char y);
void write_e(unsigned char x, unsigned char y);
void write_i(unsigned char x, unsigned char y);
void write_l(unsigned char x, unsigned char y);
void write_o(unsigned char x, unsigned char y);
void write_p(unsigned char x, unsigned char y);
void write_r(unsigned char x, unsigned char y);
void write_s(unsigned char x, unsigned char y);
void write_u(unsigned char x, unsigned char y);
void write_v(unsigned char x, unsigned char y);
void write_w(unsigned char x, unsigned char y);
void write_0(unsigned char x, unsigned char y, unsigned char set_reset);
void write_1(unsigned char x, unsigned char y, unsigned char set_reset);
void write_2(unsigned char x, unsigned char y, unsigned char set_reset);
void write_3(unsigned char x, unsigned char y, unsigned char set_reset);
void write_4(unsigned char x, unsigned char y, unsigned char set_reset);
void write_5(unsigned char x, unsigned char y, unsigned char set_reset);
void write_6(unsigned char x, unsigned char y, unsigned char set_reset);
void write_7(unsigned char x, unsigned char y, unsigned char set_reset);
void write_8(unsigned char x, unsigned char y, unsigned char set_reset);
void write_9(unsigned char x, unsigned char y, unsigned char set_reset);

#endif	/* ALPHABET_H */

