#ifndef GAME_H
#define	GAME_H

typedef struct brick brick;
struct brick
{
    unsigned char life;
    unsigned char posX;
    unsigned char posY;
    unsigned char length;
    unsigned char width;
    unsigned char state;
    unsigned char power;
};

typedef struct paddle paddle;
struct paddle
{
    char movX;
    unsigned char size;
    unsigned char posX;
    unsigned char posY;
    unsigned char sticky;
    unsigned char wide;
    unsigned char narrow;
};

typedef struct ball ball;
struct ball
{
    unsigned char life;
    char movX;
    char movY;
    unsigned char posX;
    unsigned char posY;
    unsigned char limit_state;
    unsigned char super_power;
};

//GAME FUNCTIONS DEFINITION
paddle init_paddle();
ball init_ball(unsigned char life, paddle p);
paddle move_paddle(paddle p, ball * b);
ball move_ball(ball b, brick* tab, unsigned char level, paddle p, unsigned char * score);
ball ball_fall(ball b, paddle p);
void refresh_objects(ball b, paddle p, unsigned char score, unsigned char set_reset);
void reset_power_ups(ball * b, paddle * p, unsigned char kind);
unsigned char button_power_ups();
void power_ups(ball * b, paddle * p, unsigned char pwrup);
unsigned char game_loop(brick * tab, unsigned char level, unsigned char * score, unsigned char * life);

#endif	/* GAME_H */

