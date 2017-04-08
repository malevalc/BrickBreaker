#include "display.h"
#include <p18f4550.h>
#include <delays.h>
#include "ks108.h"
#include "data.h"
#include "alphabet.h"

void display_bricks(unsigned char posX, unsigned char posY, unsigned char life, unsigned char length, unsigned char width, unsigned char set_reset)
{
    unsigned char i,j;
    switch(life/*switch on the life to display the brick according to its level*/) {
        case 0: //Level 0 brick -> no brick!
            for(i=posX; i<posX+length; i++)
                for(j=posY; j<posY+width; j++)
                    glcd_PlotPixel(i,j,RESET);//put a pixel on every line and column from the position to the max
        break;
        case 1: //Level 1 brick -> empty
            for(i=posX; i<posX+length; i++)
            {
                if(i==posX || i==(posX+length-1))//for the first and last column, put a pixel every other line
                    for(j=posY; j<(posY+width); j++)
                        glcd_PlotPixel(i,j,set_reset);
                else//for all the other ones, put a pixel on the first and the last line
                {
                        glcd_PlotPixel(i,posY,set_reset);
                        glcd_PlotPixel(i,posY+width-1,set_reset);
                }
            }
        break;
        case 2: //Level 2 brick -> striped
            for(i=posX; i<posX+length; i++)
            {
                if(i==posX || i==(posX+length-1))//for the first and last column, put a pixel every other line
                    for(j=posY; j<=(posY+width-1); j++)
                        glcd_PlotPixel(i,j,set_reset);
                else if (i!=posX && i!=(posX+length-1) && (i-posX)%2==1) //for the odd columns, display a pixel on every two lines
                {                                               //starting with the first line
                    for(j=posY; j<(posY+width); j=j+2)
                        glcd_PlotPixel(i,j,set_reset);
                    glcd_PlotPixel(i,posY+width-1,set_reset);
                }
                else if (i!=posX && i!=(posX+length-1) && (i-posX)%2==0) //for the even columns, display a pixel on every two lines
                {                                               //starting with the second line
                    glcd_PlotPixel(i,posY,set_reset);
                    for(j=posY+1; j<(posY+width); j=j+2)
                        glcd_PlotPixel(i,j,set_reset);
                    glcd_PlotPixel(i,posY+width-1,set_reset);
                }
            }
        break;
        case 3: //Level 3 brick -> full
            for(i=posX; i<posX+length; i++)
                for(j=posY; j<posY+width; j++)
                    glcd_PlotPixel(i,j,set_reset);//put a pixel on every line and column from the position to the max
        break;
    }
}

void display_paddle(unsigned char posX, unsigned char posY, unsigned char set_reset, unsigned char size)
{
    unsigned char i;
    for(i=posX - (size/2); i<=posX + (size/2); i++)
        glcd_PlotPixel(i,posY,set_reset);//set a paddle with the width that's been received and height 1
    for(i=posX - (size/2)+1; i<=posX + (size/2)-1; i++)
        glcd_PlotPixel(i,posY+1,set_reset);
}

void display_ball(unsigned char posX, unsigned char posY, unsigned char set_reset)
{
    glcd_PlotPixel(posX,posY,set_reset);//the ball is represented by a single pixel (easier to manage collisions and path orientation depending on where it hits the paddle
    glcd_PlotPixel(posX+1,posY,set_reset);
    glcd_PlotPixel(posX-1,posY,set_reset);
    glcd_PlotPixel(posX,posY+1,set_reset);
    glcd_PlotPixel(posX,posY-1,set_reset);
}

void display_floor(unsigned char set_reset) //this function displays a "wave" at the bottom on the screen
{                                           //the player loses a life every time the ball falls underneath the floor
    unsigned char i;

    for(i=0 ; i<MENU_LIMIT ; i=i+2)
        glcd_PlotPixel(i, FLOOR_LIMIT, set_reset);

    for(i=1 ; i<MENU_LIMIT ; i=i+4)
        glcd_PlotPixel(i, FLOOR_LIMIT-1, set_reset);

    for(i=3 ; i<MENU_LIMIT ; i=i+4)
        glcd_PlotPixel(i, FLOOR_LIMIT+1, set_reset);
}

void display_limit()
{
    unsigned char i;
    for(i=0; i<=LCD_WIDTH; i++)
        glcd_PlotPixel(MENU_LIMIT,i,1);//draws a vertical line which shows the limit between the actual game and the menu
}

void display_heart(unsigned char x, unsigned char y, unsigned char set_reset, unsigned char life)
{
    unsigned char i;
    //display an empty heart
    glcd_PlotPixel(x+0, y+2,    set_reset);
    glcd_PlotPixel(x+0, y+3,    set_reset);
    glcd_PlotPixel(x+0, y+4,    set_reset);
    glcd_PlotPixel(x+1, y+1,    set_reset);
    glcd_PlotPixel(x+1, y+5,    set_reset);
    glcd_PlotPixel(x+2, y+0,    set_reset);
    glcd_PlotPixel(x+2, y+6,    set_reset);
    glcd_PlotPixel(x+3, y+0,    set_reset);
    glcd_PlotPixel(x+3, y+7,    set_reset);
    glcd_PlotPixel(x+4, y+0,    set_reset);
    glcd_PlotPixel(x+4, y+8,    set_reset);
    glcd_PlotPixel(x+5, y+1,    set_reset);
    glcd_PlotPixel(x+5, y+9,    set_reset);
    glcd_PlotPixel(x+6, y+2,    set_reset);
    glcd_PlotPixel(x+6, y+3,    set_reset);
    glcd_PlotPixel(x+6, y+10,   set_reset);
    glcd_PlotPixel(x+7, y+1,    set_reset);
    glcd_PlotPixel(x+7, y+9,    set_reset);
    glcd_PlotPixel(x+8, y+0,    set_reset);
    glcd_PlotPixel(x+8, y+8,    set_reset);
    glcd_PlotPixel(x+9, y+0,    set_reset);
    glcd_PlotPixel(x+9, y+7,    set_reset);
    glcd_PlotPixel(x+10,y+0,    set_reset);
    glcd_PlotPixel(x+10,y+6,    set_reset);
    glcd_PlotPixel(x+11,y+1,    set_reset);
    glcd_PlotPixel(x+11,y+5,    set_reset);
    glcd_PlotPixel(x+12,y+2,    set_reset);
    glcd_PlotPixel(x+12,y+3,    set_reset);
    glcd_PlotPixel(x+12,y+4,    set_reset);

    switch (life)
    {
        case 0://clear the inside of the heart
            for (i=2 ; i<11 ; i++)
                if((i>1 && i<5)||(i>7 && i<11))
                    glcd_PlotPixel(x+i, y+1,    RESET);

            for (i=1 ; i<12 ; i++)
                if((i>0 && i<6)||(i>6 && i<12))
                {
                    glcd_PlotPixel(x+i, y+2,    RESET);
                    glcd_PlotPixel(x+i, y+3,    RESET);
                }

            for (i=1 ; i<12 ; i++)
                glcd_PlotPixel(x+i, y+4,    RESET);

            for(i=2 ; i<11 ; i++)
                glcd_PlotPixel(x+i, y+5,    RESET);

            for(i=3 ; i<10 ; i++)
                glcd_PlotPixel(x+i, y+6,    RESET);

            for(i=4 ; i<9 ; i++)
                glcd_PlotPixel(x+i, y+7,    RESET);

            for(i=5 ; i<8 ; i++)
                glcd_PlotPixel(x+i, y+8,    RESET);

            glcd_PlotPixel(x+6, y+9,    RESET);
            break;

        case 1://clear 2/3 of the heart
            for (i=2 ; i<11 ; i++)
                if((i>1 && i<5)||(i>7 && i<11))
                    glcd_PlotPixel(x+i, y+1,    RESET);

            for (i=1 ; i<12 ; i++)
                if((i>0 && i<6)||(i>6 && i<12))
                {
                    glcd_PlotPixel(x+i, y+2,    RESET);
                    glcd_PlotPixel(x+i, y+3,    RESET);
                }

            for (i=1 ; i<12 ; i++)
                glcd_PlotPixel(x+i, y+4,    RESET);

            for(i=2 ; i<11 ; i++)
                glcd_PlotPixel(x+i, y+5,    RESET);

            for(i=3 ; i<10 ; i++)
                glcd_PlotPixel(x+i, y+6,    RESET);

            for(i=4 ; i<9 ; i++)
                glcd_PlotPixel(x+i, y+7,    set_reset);

            for(i=5 ; i<8 ; i++)
                glcd_PlotPixel(x+i, y+8,    set_reset);

            glcd_PlotPixel(x+6, y+9,    set_reset);
            break;

        case 2://clear 1/3 of the heart
            for (i=2 ; i<11 ; i++)
                if((i>1 && i<5)||(i>7 && i<11))
                    glcd_PlotPixel(x+i, y+1,    RESET);

            for (i=1 ; i<12 ; i++)
                if((i>0 && i<6)||(i>6 && i<12))
                {
                    glcd_PlotPixel(x+i, y+2,    RESET);
                    glcd_PlotPixel(x+i, y+3,    RESET);
                }

            for (i=1 ; i<12 ; i++)
                glcd_PlotPixel(x+i, y+4,    set_reset);

            for(i=2 ; i<11 ; i++)
                glcd_PlotPixel(x+i, y+5,    set_reset);

            for(i=3 ; i<10 ; i++)
                glcd_PlotPixel(x+i, y+6,    set_reset);

            for(i=4 ; i<9 ; i++)
                glcd_PlotPixel(x+i, y+7,    set_reset);

            for(i=5 ; i<8 ; i++)
                glcd_PlotPixel(x+i, y+8,    set_reset);

            glcd_PlotPixel(x+6, y+9,    set_reset);
            break;

        case 3://fill the heart
            for (i=2 ; i<11 ; i++)
                if((i>1 && i<5)||(i>7 && i<11))
                    glcd_PlotPixel(x+i, y+1,    set_reset);

            for (i=1 ; i<12 ; i++)
                if((i>0 && i<6)||(i>6 && i<12))
                {
                    glcd_PlotPixel(x+i, y+2,    set_reset); 
                    glcd_PlotPixel(x+i, y+3,    set_reset);
                }

            for (i=1 ; i<12 ; i++)
                glcd_PlotPixel(x+i, y+4,    set_reset);

            for(i=2 ; i<11 ; i++)
                glcd_PlotPixel(x+i, y+5,    set_reset);

            for(i=3 ; i<10 ; i++)
                glcd_PlotPixel(x+i, y+6,    set_reset);

            for(i=4 ; i<9 ; i++)
                glcd_PlotPixel(x+i, y+7,    set_reset);

            for(i=5 ; i<8 ; i++)
                glcd_PlotPixel(x+i, y+8,    set_reset);

            glcd_PlotPixel(x+6, y+9,    set_reset);
            break;
    }
}

void write_numbers_of_score(unsigned char number, unsigned char x, unsigned char y, unsigned char set_reset)
{
    switch (number)//calls the function that matches the number received
    {
        case 0:
            write_0(x,y,set_reset);
            break;
        case 1:
            write_1(x,y,set_reset);
            break;
        case 2:
            write_2(x,y,set_reset);
            break;
        case 3:
            write_3(x,y,set_reset);
            break;
        case 4:
            write_4(x,y,set_reset);
            break;
        case 5:
            write_5(x,y,set_reset);
            break;
        case 6:
            write_6(x,y,set_reset);
            break;
        case 7:
            write_7(x,y,set_reset);
            break;
        case 8:
            write_8(x,y,set_reset);
            break;
        case 9:
            write_9(x,y,set_reset);
            break;
    }
}

void draw_power_up_stickiness(unsigned char x, unsigned char y, unsigned char set_reset)//draws the symbol for the stickiness power-up
{
    unsigned char i;
    for(i=0; i<7; i++)
        glcd_PlotPixel(x+i,y,set_reset);
    glcd_PlotPixel(x+3,y-1,set_reset);
}

void draw_power_up_paddle_narrower(unsigned char x, unsigned char y, unsigned char set_reset)//draws the symbol for the narrower paddle power-up
{
    unsigned char i;
    for(i=0; i<7; i++)
        glcd_PlotPixel(x+i,y,set_reset);
    for(i=0;i<5;i++)
    {
        glcd_PlotPixel(x-3-i,y,set_reset);
        glcd_PlotPixel(x+9+i,y,set_reset);
    }
    glcd_PlotPixel(x-4, y+1,set_reset);
    glcd_PlotPixel(x-4, y-1,set_reset);
    glcd_PlotPixel(x+10,y+1,set_reset);
    glcd_PlotPixel(x+10,y-1,set_reset);
    glcd_PlotPixel(x-5, y+2,set_reset);
    glcd_PlotPixel(x-5, y-2,set_reset);
    glcd_PlotPixel(x+11,y+2,set_reset);
    glcd_PlotPixel(x+11,y-2,set_reset);
}

void draw_power_up_paddle_wider(unsigned char x, unsigned char y, unsigned char set_reset)//draws the symbol for the wider paddle power-up
{
    unsigned char i;
    for(i=0; i<7; i++)
        glcd_PlotPixel(x+i,y,set_reset);
    for(i=0;i<5;i++)
    {
       glcd_PlotPixel(x-3-i,y,set_reset);
       glcd_PlotPixel(x+9+i,y,set_reset);
    }
    glcd_PlotPixel(x-6, y-1,set_reset);
    glcd_PlotPixel(x-6, y+1,set_reset);
    glcd_PlotPixel(x+12,y-1,set_reset);
    glcd_PlotPixel(x+12,y+1,set_reset);
    glcd_PlotPixel(x-5, y+2,set_reset);
    glcd_PlotPixel(x-5, y-2,set_reset);
    glcd_PlotPixel(x+11,y+2,set_reset);
    glcd_PlotPixel(x+11,y-2,set_reset);
}

void draw_power_up_ball_superpower(unsigned char x, unsigned char y, unsigned char set_reset)//draws the symbol for the powerful ball power-up
{
    unsigned char i,j;
    for (i=0 ; i<3 ; i++)
        for (j=0 ; j<3 ; j++)
            glcd_PlotPixel(x+2+i,y-1+j,set_reset);
    
    glcd_PlotPixel(x-1,y-4,set_reset);
    glcd_PlotPixel(x-1,y,  set_reset);
    glcd_PlotPixel(x-1,y+4,set_reset);
    glcd_PlotPixel(x,  y-3,set_reset);
    glcd_PlotPixel(x,  y,  set_reset);
    glcd_PlotPixel(x,  y+3,set_reset);
    glcd_PlotPixel(x+3,y-4,set_reset);
    glcd_PlotPixel(x+3,y-3,set_reset);
    glcd_PlotPixel(x+3,y+3,set_reset);
    glcd_PlotPixel(x+3,y+4,set_reset);
    glcd_PlotPixel(x+6,y-3,set_reset);
    glcd_PlotPixel(x+6,y,  set_reset);
    glcd_PlotPixel(x+6,y+3,set_reset);
    glcd_PlotPixel(x+7,y-4,set_reset);
    glcd_PlotPixel(x+7,y,  set_reset);
    glcd_PlotPixel(x+7,y+4,set_reset);
}

void write_score_number(short int score, unsigned char x, unsigned char y, unsigned char set_reset)
{//first, we test if the number is less than 10, between 10 and 99 or greater than 100
    if (score < 10)
        write_numbers_of_score(score,x+3,y,set_reset);//calls the number writing function for the whole number
    else if (score > 9 && score < 100)
    {
        write_numbers_of_score(score%10,x+6,y,set_reset);//calls the number writing function for the units part
        write_numbers_of_score((score - score%10)/10,x,y,set_reset);//calls the number writing function for the tens part
    }
    else
    {
        write_numbers_of_score((score%100)%10,x+8,y,set_reset);//calls the number writing function for the units part
        write_numbers_of_score(((score%100) - (score%100)%10)/10,x+3,y,set_reset);//calls the number writing function for the tens part
        write_numbers_of_score(((score - score%100)/100),x-2,y,set_reset);//calls the number writing function for the hundreds part
    }
}

void write_score(unsigned char x, unsigned char y)
{
    write_s(x+(5*0),y);
    write_c(x+(5*1),y);
    write_o(x+(5*2),y);
    write_r(x+(5*3),y);
    write_e(x+(5*4),y);
}

void write_lives(unsigned char x, unsigned char y)
{
    write_l(x+(5*0),y);
    write_i(x+(5*1),y);
    write_v(x+(5*2),y);
    write_e(x+(5*3),y);
    write_s(x+(5*4),y);
}

void write_power_ups(unsigned char x, unsigned char y)
{
    write_p(x+(5*0),y);
    write_o(x+(5*1),y);
    write_w(x+(5*2),y);
    write_e(x+(5*3),y);
    write_r(x+(5*4),y);
    write_u(x+(5*1),y+7);
    write_p(x+(5*2),y+7);
    write_s(x+(5*3),y+7);
}

void init_menu()
{
    display_limit();
    write_score(MENU_LIMIT+4,POS_SCORE);//writes "score"
    //write_score_number(0,MENU_LIMIT+11,POS_SCORE_N, SET);//writes the number that represents the player's score
    write_lives(MENU_LIMIT+4,POS_LIVES);//writes the number of lives left
    //display_heart(MENU_LIMIT+9,POS_HEART,SET,3);//displays the heart
    write_power_ups(MENU_LIMIT+4,POS_POWER_UPS);//writes "power-ups"
    display_floor(SET);
}

void init_screen(brick *tab, unsigned char level_received)
{
	unsigned char i;

    for(i=0;i<level_received;i++)
        display_bricks(tab[i].posX,tab[i].posY,tab[i].life,tab[i].length,tab[i].width,SET);

    init_menu();
}