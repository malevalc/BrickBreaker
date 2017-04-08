#include "main.h"
#include "display.h"
#include "ks108.h"
#include "data.h"
#include "game.h"

const unsigned char levels[LEVEL_NUMBER][BRICKS_NO_5][ATTRIBUTES_NUMBER]=
{{{2,3,3},  {2,37,3},   {2,71,3},   {1,3,27},   {1,37,27},   {1,71,27},  {0,0,0},
    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0}},   //level 1
 {{2,3,3},  {3,37,3},   {2,71,3},   {1,20,16},  {1,54,16},   {2,3,29},   {1,37,29},
    {2,71,29},  {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0}},   //level 2
 {{2,3,3},  {3,28,3},   {3,53,3},   {2,78,3},   {1,3,16},    {2,28,16},  {2,53,16},
    {1,78,16},  {1,28,29},  {1,53,29},  {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0}},   //level 3
 {{1,3,3},  {3,22,3},   {2,41,3},   {3,60,3},   {1,79,3},    {3,10,16},  {2,29,16},
    {2,53,16},  {3,72,16},  {2,22,29},  {2,41,29},  {2,60,29},  {0,0,0},    {0,0,0}},   //level 4
 {{3,3,3},  {2,22,3},   {3,41,3},   {2,60,3},   {3,79,3},    {1,10,16},  {3,29,16},
    {3,53,16},  {1,72,16},  {2,3,29},   {1,22,29},  {3,41,29},  {1,60,29},  {2,79,29}}};//level 5

void init_PIC()
{
    ADCON1 = 0x0F;
    TRISA  = 0xff;    PORTA = 0;
    TRISB  = 0;       PORTB = 0;
    TRISC  = 0xff;    PORTC = 0;
    TRISC  = 0xff;    PORTC = 0;
    TRISE  = 0xff;    PORTE = 0;
    glcd_Init(1);
}

void display(unsigned char choice, unsigned char number_of_seconds)
{
    glcd_FillScreen(0);
    glcd_Image(choice);
    wait_for(number_of_seconds);
}

void wait_for(unsigned char number_of_seconds)
{
    unsigned char i=0;
    for(i = 0 ; i < number_of_seconds ; i++)
        Delay10KTCYx(50);
}

void main(void)
{
    unsigned char i = 0;
    unsigned char score = 0;//the score is first reset
    unsigned char life  = DEFAULT_LIFE;
    brick tab[BRICKS_NO_5];
    unsigned char level = STARTING_LEVEL;
    unsigned char game  = YES;

    //calls the function that sets the PIC correctly according to what we need it to do
    init_PIC();
    
    //MULTIPLE SCREENS DISPLAYING
    display(HOME,2);
    display(DEVELOP,4);
    display(RULES_1,10);
    display(RULES_2,15);
    display(RULES_3,8);
    glcd_FillScreen(0);

    while(game)
    {
        switch(level)
        {
        //sets every level
            case 1 :
                for (i=0;i<BRICKS_NO_1;i++)
                {
                    tab[i].life = levels[0][i][0];
                    tab[i].posX = levels[0][i][1];
                    tab[i].posY = levels[0][i][2];
                    tab[i].length = LENGTH_1_2;
                    tab[i].width  = WIDTH_1;
                    tab[i].state  = NO;
                    tab[i].power  = NO;
                    level = BRICKS_NO_1;
                }
                tab[4].power = YES;
                break;
            case 2:
                for (i=0;i<BRICKS_NO_2;i++)
                {
                    tab[i].life = levels[1][i][0];
                    tab[i].posX = levels[1][i][1];
                    tab[i].posY = levels[1][i][2];
                    tab[i].length = LENGTH_1_2;
                    tab[i].width  = WIDTH_2_3_4_5;
                    tab[i].state  = NO;
                    tab[i].power  = NO;
                    level = BRICKS_NO_2;
                }
                tab[1].power = YES;
                tab[3].power = YES;
                tab[4].power = YES;
                break;
            case 3:
                for (i=0;i<BRICKS_NO_3;i++)
                {
                    tab[i].life = levels[2][i][0];
                    tab[i].posX = levels[2][i][1];
                    tab[i].posY = levels[2][i][2];
                    tab[i].length = LENGTH_3;
                    tab[i].width  = WIDTH_2_3_4_5;
                    tab[i].state  = NO;
                    tab[i].power  = NO;
                    level = BRICKS_NO_3;
                }
                tab[0].power = YES;
                tab[3].power = YES;
                tab[5].power = YES;
                tab[6].power = YES;
                break;
            case 4:
                for (i=0;i<BRICKS_NO_4;i++)
                {
                    tab[i].life = levels[3][i][0];
                    tab[i].posX = levels[3][i][1];
                    tab[i].posY = levels[3][i][2];
                    tab[i].length = LENGTH_4_5;
                    tab[i].width  = WIDTH_2_3_4_5;
                    tab[i].state  = NO;
                    tab[i].power  = NO;
                    level = BRICKS_NO_4;
                }
                tab[2].power = YES;
                tab[6].power = YES;
                tab[7].power = YES;
                tab[9].power = YES;
                tab[11].power = YES;
                break;
            case 5:
                for (i=0;i<BRICKS_NO_5;i++)
                {
                    tab[i].life = levels[4][i][0];
                    tab[i].posX = levels[4][i][1];
                    tab[i].posY = levels[4][i][2];
                    tab[i].length = LENGTH_4_5;
                    tab[i].width  = WIDTH_2_3_4_5;
                    tab[i].state  = NO;
                    tab[i].power  = NO;
                    level = BRICKS_NO_5;
                }
                tab[0].power = YES;
                tab[2].power = YES;
                tab[4].power = YES;
                tab[6].power = YES;
                tab[7].power = YES;
                tab[11].power = YES;
                break;
        }
        
        Delay10KTCYx(100);
        
        if(level!=0)
        {
            //set the GLCD ready to play
            init_screen(tab,level);
            //start the game
            if(life!=3)
                life++;
            level = game_loop(tab,level,&score,&life);
            glcd_FillScreen(0);
            if(level != 0 && level < 6)
            {
                glcd_Image(LVL_COMPLT);//displays the congrats on a level win
                wait_for(2);
            }
            if (level == 6)
            {
                while(PORTEbits.RE0 == NO)
                {
                    score = 0;//the score is first reset
                    life = DEFAULT_LIFE;
                    level = STARTING_LEVEL;
                    glcd_Image(YOU_WIN);//displays the game over screen
                }
            }
        }

        if (level == 0)
            while (PORTEbits.RE0 == NO)
            {
                score = 0;//the score is first reset
                life = DEFAULT_LIFE;
                level = STARTING_LEVEL;
                glcd_Image(GAME_OVER);//displays the game over screen
            }
        glcd_FillScreen(0);
    }
}