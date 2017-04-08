#ifndef DISPLAY_H
#define	DISPLAY_H

#include <p18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "game.h"

#define _XTAL_FREQ 8000000

//DISPLAY FUNCTION DEFINITION
void display_bricks(unsigned char a, unsigned char b, unsigned char life, unsigned char length, unsigned char width, unsigned char set_reset);
void display_paddle(unsigned char a, unsigned char b, unsigned char set_reset, unsigned char size);
void display_ball(unsigned  char a, unsigned char b, unsigned char set_reset);
void display_floor(unsigned char set_reset);
void display_limit();
void display_heart(unsigned char x, unsigned char y, unsigned char set_reset, unsigned char life);
void write_numbers_of_score(unsigned char number, unsigned char x, unsigned char y, unsigned char life);
void draw_power_up_stickiness(unsigned char x, unsigned char y, unsigned char set_reset);
void draw_power_up_paddle_narrower(unsigned char x, unsigned char y, unsigned char set_reset);
void draw_power_up_paddle_wider(unsigned char x, unsigned char y, unsigned char set_reset);
void draw_power_up_ball_superpower(unsigned char x, unsigned char y, unsigned char set_reset);
void write_score_number(short int score, unsigned char x, unsigned char y, unsigned char set_reset);
void write_score(unsigned char x, unsigned char y);
void write_lives(unsigned char x, unsigned char y);
void write_power_ups(unsigned char x, unsigned char y);
void init_menu();
void init_screen(brick *tab, unsigned char level_received);

#endif	/* DISPLAY_H */

