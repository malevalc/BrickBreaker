#ifndef MAIN_H
#define	MAIN_H

#include "game.h"
#include <p18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma config FOSC     = HS 		//oscillator HS
#pragma config MCLRE    = ON
#pragma config PBADEN   = OFF
#pragma config WDT      = OFF 		//Disable watchDog
#pragma config LVP      = OFF 		//Disable low voltage programmig
#pragma config DEBUG    = OFF		//Debug ON

#define _XTAL_FREQ 8000000

#define RS  RC0
#define RW  RC1
#define EN  RC2
#define CS1 RC3
#define CS2 RC4
#define RST RC5
#define data PORTB

//MAIN FUNCTIONS DEFINITION
void init_PIC();
void wait_for(unsigned char number_of_seconds);
void display(unsigned char number_of_seconds, unsigned char choice);

#endif	/* MAIN_H */

