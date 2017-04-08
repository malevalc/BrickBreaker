#include <stdio.h>
#include <stdlib.h>
#include <timers.h>
#include "data.h"
#include "display.h"
#include "game.h"
#include "ks108.h"

paddle init_paddle()
{
    paddle p;
    p.movX = NO;//the paddle doesn't move at first
    p.posX = POS_PADDLE_BALL_X;
    p.posY = POS_PADDLE_BALL_Y;
    p.size = 7;
    //power-ups reset settings
    p.sticky = NO;
    p.wide   = NO;
    p.narrow = NO;
    return p;
}

ball init_ball(unsigned char life, paddle p)
{
    ball b;
    b.life = life;
    b.movX = NO;//the ball doesn't 
    b.movY = NO;//move at first
    b.posX = p.posX;
    b.posY = POS_PADDLE_BALL_Y-1;
    b.super_power = NO;
    return b;
}

paddle move_paddle(paddle p, ball * b)
{
    if(PORTCbits.RC7 == YES)
    //if left pressed
        p.movX = LEFT;

    else if(PORTCbits.RC6 == YES)
   //if right pressed
        p.movX = RIGHT;

    else//if nothing is pressed
        p.movX = NO;

    //if the paddle is not touching a wall,
    //we change the position(left or right)
    if (((p.posX + 1 - (p.size/2)) + p.movX > 0) && ((p.posX + (p.size/2)) + p.movX < MENU_LIMIT))
    {
        p.posX += p.movX;
        if ((b->movX == NO)&&(b->movY == NO))//if the ball is on the paddle
            b->posX = p.posX;//the ball follows the paddle
    }
    
    return p;
}

ball move_ball(ball b, brick * tab, unsigned char level, paddle p, unsigned char * score)
{
    char i;
    
    if((b.movX > 1 || b.movX < -1))     //this cheats and fixes the ball moving vector
    {                                   //so that it's 1by1 when it hits a brick
       if(b.movX > 0)
            b.movX--;
        else
            b.movX++;
    }
        
    //collision with the top
    if (b.posY == TOP)
        b.movY = - b.movY;
    
    //collision with the floor line
    if (b.posY == FLOOR_LIMIT)
    {
        b.movX = NO; //doesn't move anymore
        b.movY = NO; //doesn't move anymore
        b=ball_fall(b,p);
    }
    
    //collision with the left or right border
    if(b.posX <= LEFT_LIMIT)
        b.movX = - b.movX;
    
    if (b.posX >= MENU_LIMIT)
    {
        b.movX = - b.movX;
        b.limit_state = 2;
    }
    
    //collision with the paddle
    for(i=0;i<=((p.size/2));i++)
    {
        if(((b.posX == (p.posX - i))&&((b.posY == p.posY)))||((b.posX == (p.posX + i))&&(b.posY == p.posY)))
        {
            if(p.sticky==YES)
            {//the ball sticks to the paddle if the stickiness factor is on
               b.posY--;
               b.movY = NO;
               b.movX = NO;
            }
            else//the ball bounces off the paddle with the corresponding vector
            {
                     if((b.posX == (p.posX - i))&&((b.posY == p.posY)))
                    b.movX = - i;
                else if((b.posX == (p.posX + i))&&((b.posY == p.posY)))
                    b.movX = + i;
                b.movY = - b.movY;
            }
        }
    }
    
    //collision with the bricks
    for (i=0;i<=level;i++)
    {
        if(tab[i].life!=0)
        {   //Check if the ball meets one of the bricks:
            if ((((b.posY >= tab[i].posY) && (b.posY <= tab[i].posY+tab[i].width-1)) && (((b.posX == tab[i].posX) || (b.posX == tab[i].posX+tab[i].length-1))))
             ||((((b.posY == tab[i].posY) || (b.posY == tab[i].posY+tab[i].width-1))) && ((b.posX >= tab[i].posX) && (b.posX <= tab[i].posX+tab[i].length-1))))
            {   
                if(b.super_power == NO)
                {
                    //Check if the ball meets a vertical line of a brick
                         if (((b.posY >= tab[i].posY+1) && (b.posY <= tab[i].posY+tab[i].width-2)) && ((b.posX == tab[i].posX) || (b.posX == tab[i].posX+tab[i].length-1)))
                        b.movX = - b.movX;
                    //Check if the ball meets a horizonal line of a brick
                    else if (((b.posX >= tab[i].posX+1) && (b.posX <= tab[i].posX+tab[i].length-2)) && ((b.posY == tab[i].posY) || (b.posY == tab[i].posY+tab[i].width-1)))
                        b.movY = - b.movY;
                    //Check if the ball meets the top left corner
                    else if ((b.posY == tab[i].posY)&&(b.posX == tab[i].posX))
                    {
                             if ((b.movX == RIGHT)&&(b.movY == DOWN))
                        {
                            b.movX = -b.movX;
                            b.movY = -b.movY;
                        }
                        else if ((b.movX == RIGHT)&&(b.movY == UP))
                            b.movX = -b.movX;
                        else if ((b.movX == LEFT)&&(b.movY == DOWN))
                            b.movY = -b.movY;
                    }
                    //Check if the ball meets the bottom left corner
                    else if ((b.posY == tab[i].posY+tab[i].width-1)&&(b.posX == tab[i].posX))
                    {
                             if ((b.movX == RIGHT)&&(b.movY == UP))
                        {
                            b.movX = -b.movX;
                            b.movY = -b.movY;
                        }
                        else if ((b.movX == RIGHT)&&(b.movY == DOWN))
                            b.movX = -b.movX;
                        else if ((b.movX == LEFT)&&(b.movY == UP))
                            b.movY = -b.movY;
                        else if (b.movX == NO)
                            b.movY = -b.movY;
                    }
                    //Check if the ball meets the top right corner
                    else if (((b.posY == tab[i].posY)&&(b.posX == tab[i].posX+tab[i].length-1)))
                    {
                             if ((b.movX == LEFT)&&(b.movY == DOWN))
                        {
                            b.movX = -b.movX;
                            b.movY = -b.movY;
                        }
                        else if ((b.movX == LEFT)&&(b.movY == UP))
                            b.movX = -b.movX;
                        else if ((b.movX == RIGHT)&&(b.movY == DOWN))
                            b.movY = -b.movY;
                    }
                    //Check if the ball meets the bottom right corner
                    else if ((b.posY == tab[i].posY+tab[i].width-1)&&(b.posX == tab[i].posX+tab[i].length-1))
                    {
                             if ((b.movX == LEFT)&&(b.movY == UP))
                        {
                            b.movX = -b.movX;
                            b.movY = -b.movY;
                        }
                        else if ((b.movX == LEFT)&&(b.movY == DOWN))
                            b.movX = -b.movX;
                        else if ((b.movX == RIGHT)&&(b.movY == UP))
                            b.movY = -b.movY;
                        else if (b.movX == NO)
                            b.movY = -b.movY;
                    }
                    *score += tab[i].life;
                    tab[i].life--;
                    tab[i].state = 2;
                }
                else if (b.super_power == YES)
                {
                    switch (tab[i].life)
                    {
                        case 1:
                            *score += 1;
                            break;
                        case 2:
                            *score += 3;
                            break;
                        case 3:
                            *score += 6;
                            break;
                    }
                    tab[i].life=0;
                    tab[i].state = YES;
                }
            }
        }
    }

    //ball launching
    if((PORTCbits.RC0 == YES) && (b.posY == p.posY-1))
    {
        if(p.sticky==YES)//check if the stickiness factor is on
        {//send the ball with the corresponding angle
            for(i=0;i<=((p.size/2));i++)
            {
                if(b.posX == (p.posX - i))
                    b.movX = - i;
                else if (b.posX == (p.posX + i))
                    b.movX = + i;
            }
        }
        else
            b.movX = NO;
        b.movY = UP;
    }
    
    //we make the changes effective
    b.posX += b.movX;
    b.posY += b.movY;

    return b;
}

ball ball_fall (ball b, paddle p)
{
    display_floor(RESET);
    b.life--;
    reset_power_ups(&b,&p,RESET);
    b=init_ball(b.life,p);
    display_floor(SET);
    return b;
}

void refresh_objects(ball b, paddle p, unsigned char score, unsigned char set_reset)
{
    display_paddle(p.posX,p.posY,set_reset,p.size);
    display_ball(b.posX,b.posY,set_reset);
    write_score_number(score,MENU_LIMIT+11,POS_SCORE_N,set_reset);

    if (set_reset == SET)
        display_heart(MENU_LIMIT+9,POS_HEART,set_reset,b.life);//displays the heart
}

void reset_power_ups(ball * b, paddle * p, unsigned char kind)
{
    draw_power_up_paddle_wider      (POSX_POWER_UPS, POSY_POWER_UPS, RESET);
    draw_power_up_paddle_narrower   (POSX_POWER_UPS, POSY_POWER_UPS, RESET);
    draw_power_up_stickiness        (POSX_POWER_UPS, POSY_POWER_UPS, RESET);
    draw_power_up_ball_superpower   (POSX_POWER_UPS, POSY_POWER_UPS, RESET);
    switch(kind)
    {
        case RESET:
            p->sticky = NO;
            if (p->wide == YES)
            {
                p->wide = NO;
                p->size -= 2;
            }
            if (p->narrow == YES)
            {
                p->narrow = NO;
                p->size += 2;
            }
            b->super_power = NO;
            break;
        case STICKINESS:
            if (p->wide == YES)
            {
                p->wide = NO;
                p->size -= 2;
            }
            if (p->narrow == YES)
            {
                p->narrow = NO;
                p->size += 2;
            }
            b->super_power = NO;
            break;
        case PADDLE_WIDE:
            p->sticky = NO;
            b->super_power = NO;
            if (p->narrow == YES)
            {
                p->narrow = NO;
                p->size += 2;
            }
            break;
        case PADDLE_NARROW:
            p->sticky = NO;
            b->super_power = NO;
            if (p->wide == YES)
            {
                p->wide = NO;
                p->size -= 2;
            }
            break;
        case BALL_SUPERPOWER:
            p->sticky = NO;
            if (p->wide == YES)
            {
                p->wide = NO;
                p->size -= 2;
            }
            if (p->narrow == YES)
            {
                p->narrow = NO;
                p->size += 2;
            }
            break;
    } 
}

unsigned char button_power_ups()//POWER-UPS SIMULATION WITH THE PUSH BUTTONS
{
    if(PORTAbits.RA0 == YES)
        return STICKINESS;

    if(PORTAbits.RA2 == YES)
        return PADDLE_WIDE;

    if(PORTAbits.RA3 == YES)
        return PADDLE_NARROW;

    if(PORTAbits.RA5 == YES)
        return BALL_SUPERPOWER;
}

void power_ups(ball * b, paddle * p, unsigned char pwrup)
{
    //POWER-UPS 
    switch(pwrup)
    {
        case STICKINESS:
            reset_power_ups(b,p,STICKINESS);
            if(p->sticky == YES)
                p->sticky=NO;
            else if(p->sticky == NO)
                p->sticky=YES;
            draw_power_up_stickiness(POSX_POWER_UPS, POSY_POWER_UPS,p->sticky);
            break;
        case PADDLE_WIDE:
            reset_power_ups(b,p,PADDLE_WIDE);
            if (p->wide == NO)
            {
                p->size += 2;
                p->wide = YES;
            }
            else if (p->wide == YES)
            {
                p->size -= 2;
                p->wide = NO;
            }
            draw_power_up_paddle_wider(POSX_POWER_UPS, POSY_POWER_UPS, p->wide);
            break;
        case PADDLE_NARROW:
            reset_power_ups(b,p,PADDLE_NARROW);
            if(p->narrow == NO)
            {
                p->size -= 2;
                p->narrow = YES;
            }
            else if (p->narrow == YES)
            {
                p->size += 2;
                p->narrow = NO;
            }
            draw_power_up_paddle_narrower(POSX_POWER_UPS, POSY_POWER_UPS, p->narrow);
            break;
        case BALL_SUPERPOWER:
            reset_power_ups(b,p,BALL_SUPERPOWER);
            if(b->super_power == NO)
                b->super_power = YES;
            else if (b->super_power == YES)
                b->super_power = NO;
            draw_power_up_ball_superpower(POSX_POWER_UPS, POSY_POWER_UPS, b->super_power);
            break;
    }
}

unsigned char game_loop(brick * tab, unsigned char level, unsigned char * score, unsigned char * life)
{
    unsigned char i;
    short int pwrup = 0;
    unsigned char counter = 0;//counter to count the number of broken bricks

    //set the 2 main objects needed to play the game
    paddle p = init_paddle();
    ball b = init_ball(*life,p);
    
    reset_power_ups(&b,&p,RESET);
    
    while(b.life>0)//we want to play while we can...
    {
        *life = b.life;//
        
        //reset every object so that it get displayed again soon to its new position
        refresh_objects(b,p,*score,RESET);
            
        //calls the function that handles each object
        p = move_paddle(p,&b);
        b = move_ball(b,tab,level,p,score);

        pwrup = button_power_ups();

        for(i=0;i<level;i++)//we're gonna check if one of the bricks has been hit during this clock cycle
        {
            if(tab[i].state == 1)
            {
                if (tab[i].life==0) //every time a brick is completely broken, counter incremented
                    counter ++;
                if(tab[i].life == NO && tab[i].power == YES)
                {
                         if ((b.movX == RIGHT)&&(b.movY == DOWN))
                        pwrup = PADDLE_WIDE;
                    else if ((b.movX == RIGHT)&&(b.movY == UP  ))
                        pwrup = BALL_SUPERPOWER;
                    else if ((b.movX == LEFT )&&(b.movY == DOWN))
                        pwrup = PADDLE_NARROW;
                    else if ((b.movX == LEFT )&&(b.movY == UP  ))
                        pwrup = STICKINESS;
                    else if ((b.movX ==   0  )&&(b.movY == DOWN))
                        pwrup = PADDLE_WIDE;
                    tab[i].power = NO;
                }
            }
            if((tab[i].state > 0)&&(tab[i].state <= 2))//to display the brick is an inferior level
            {
                display_bricks(tab[i].posX,tab[i].posY,tab[i].life+1,tab[i].length,tab[i].width,RESET);
                tab[i].state--;
                display_bricks(tab[i].posX,tab[i].posY,tab[i].life,tab[i].length,tab[i].width,SET);
            }
        }

        power_ups(&b,&p,pwrup);

        if((b.limit_state > 0)&&(b.limit_state <= 2))//every time the right limit is met, it displays again
        {
            display_limit();
            b.limit_state--;
        }
            
        if (counter == level)//if the counter is equal to the number of bricks
            return (((level - 6)/2)+2); //return the number of the next level so that it can be incremented in the main

        //displays back the objects
        refresh_objects(b,p,*score,SET);

        if (b.life==0)
            return 0;
        
        Delay10KTCYx(1);
    }
}