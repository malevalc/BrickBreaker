#ifndef DATA_H
#define	DATA_H

#include <p18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <delays.h>

//DEFINES CONSTANTS NEEDED TO PRE-IMPLEMENT LEVELS
#define LEVEL_NUMBER      5
#define ATTRIBUTES_NUMBER 3
#define DEFAULT_LIFE      3
#define STARTING_LEVEL    1

//DEFINITION FOR BITMAP CHOICES
#define HOME        1
#define DEVELOP     2
#define RULES_1     3
#define RULES_2     4
#define RULES_3     5
#define LVL_COMPLT  6
#define GAME_OVER   7
#define YOU_WIN     8

//LOGIC DEFINITION
#define SET   1
#define RESET 0
#define YES   1
#define NO    0

//MOVEMENT DEFINITION
#define UP   -1
#define LEFT -1
#define DOWN  1
#define RIGHT 1

//DEFINES POSITIONS FOR THE GLCD INIT
#define TOP               0
#define LEFT_LIMIT        0
#define POS_SCORE         1
#define POS_SCORE_N       8
#define POS_LIVES         18
#define POS_HEART         25
#define POS_POWER_UPS     42
#define POS_PADDLE_BALL_Y 57
#define FLOOR_LIMIT       61
#define POS_PADDLE_BALL_X 50
#define MENU_LIMIT        98

//DEFINES THE NUMBER OF BRICKS FOR EACH LEVEL
#define BRICKS_NO_1 6
#define BRICKS_NO_2 8
#define BRICKS_NO_3 10
#define BRICKS_NO_4 12
#define BRICKS_NO_5 14

//DEFINES POSITIONS FOR THE POWER-UPS
#define POSX_POWER_UPS 110
#define POSY_POWER_UPS 59

//POWER-UPS DEFINITIONS
#define PADDLE_WIDE     1
#define PADDLE_NARROW   2
#define STICKINESS      3
#define BALL_SUPERPOWER 4

//DEFINES VARIABLE USEFUL TO BUILD EACH LEVEL
#define LENGTH_1_2    24
#define WIDTH_1       12
#define WIDTH_2_3_4_5 10
#define LENGTH_3      17
#define LENGTH_4_5    16

#endif	/* DATA_H */
