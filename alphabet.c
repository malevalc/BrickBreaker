#include "alphabet.h"

//THIS FILE CONTAINS THE FUNCTION NEEDED TO DISPLAY A LETTER OR A NUMBER
void write_c(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes C
    glcd_PlotPixel(x+1 ,y ,1);
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_e(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes E
    glcd_PlotPixel(x+1 ,y ,1);
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+1 ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_i(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x ,y ,1);//Writes I
    glcd_PlotPixel(x+1 ,y ,1);
    glcd_PlotPixel(x+2 ,y ,1);
    glcd_PlotPixel(x+1 ,y+1 ,1);
    glcd_PlotPixel(x+1 ,y+2 ,1);
    glcd_PlotPixel(x+1 ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_l(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x ,y ,1);//Writes L
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_o(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes O
    glcd_PlotPixel(x+1 ,y ,1);
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x+2 ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x+2 ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_p(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes P
    glcd_PlotPixel(x+1 ,y ,1);
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x+2 ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+1 ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
}

void write_r(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes R
    glcd_PlotPixel(x+1 ,y ,1);
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x+2 ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+1 ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x+1 ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_s(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes S
    glcd_PlotPixel(x+1 ,y ,1);
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+1 ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+3 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
}

void write_u(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes U
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x+2 ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x+2 ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_v(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes V
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x+2 ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x+2 ,y+3 ,1);
    glcd_PlotPixel(x+1 ,y+4 ,1);
}

void write_w(unsigned char x, unsigned char y)
{
    glcd_PlotPixel(x+2 ,y ,1);	//Writes W
    glcd_PlotPixel(x ,y ,1);
    glcd_PlotPixel(x ,y+1 ,1);
    glcd_PlotPixel(x+2 ,y+1 ,1);
    glcd_PlotPixel(x ,y+2 ,1);
    glcd_PlotPixel(x+1 ,y+2 ,1);
    glcd_PlotPixel(x+2 ,y+2 ,1);
    glcd_PlotPixel(x ,y+3 ,1);
    glcd_PlotPixel(x+1 ,y+3 ,1);
    glcd_PlotPixel(x+2 ,y+3 ,1);
    glcd_PlotPixel(x ,y+4 ,1);
    glcd_PlotPixel(x+2 ,y+4 ,1);
}

void write_0(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+1 ,y ,set_reset);//Writes 0
    glcd_PlotPixel(x ,y+1 ,set_reset);
    glcd_PlotPixel(x+2 ,y+1 ,set_reset);
    glcd_PlotPixel(x ,y+2 ,set_reset);
    glcd_PlotPixel(x+2 ,y+2 ,set_reset);
    glcd_PlotPixel(x ,y+3 ,set_reset);
    glcd_PlotPixel(x+2 ,y+3 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
}

void write_1(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x,y+1 ,set_reset);//Writes 1
    glcd_PlotPixel(x+1 ,y ,set_reset);
    glcd_PlotPixel(x+1 ,y+1 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
    glcd_PlotPixel(x+1 ,y+3 ,set_reset);
    glcd_PlotPixel(x ,y+4 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
    glcd_PlotPixel(x+2 ,y+4 ,set_reset);
}

void write_2(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+1 ,y ,set_reset);//Writes 2
    glcd_PlotPixel(x ,y ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
    glcd_PlotPixel(x+2 ,y+1 ,set_reset);
    glcd_PlotPixel(x ,y+3 ,set_reset);
    glcd_PlotPixel(x ,y+4 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
    glcd_PlotPixel(x+2 ,y+4 ,set_reset);
}

void write_3(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+1 ,y ,set_reset);//Writes 3
    glcd_PlotPixel(x ,y ,set_reset);
    glcd_PlotPixel(x ,y+2 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
    glcd_PlotPixel(x+2 ,y+1 ,set_reset);
    glcd_PlotPixel(x+2 ,y+3 ,set_reset);
    glcd_PlotPixel(x ,y+4 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
}

void write_4(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+2 ,y ,set_reset);//Writes 4
    glcd_PlotPixel(x ,y ,set_reset);
    glcd_PlotPixel(x ,y+1 ,set_reset);
    glcd_PlotPixel(x+2 ,y+1 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
    glcd_PlotPixel(x+2 ,y+2 ,set_reset);
    glcd_PlotPixel(x+2 ,y+3 ,set_reset);
    glcd_PlotPixel(x+2 ,y+4 ,set_reset);
}

void write_5(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+2 ,y ,set_reset);//Writes 5
    glcd_PlotPixel(x+1 ,y ,set_reset);
    glcd_PlotPixel(x ,y ,set_reset);
    glcd_PlotPixel(x ,y+1 ,set_reset);
    glcd_PlotPixel(x ,y+2 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
    glcd_PlotPixel(x+2 ,y+3 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
    glcd_PlotPixel(x ,y+4 ,set_reset);
}

void write_6(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+2 ,y ,set_reset);	//Writes 6
    glcd_PlotPixel(x+1 ,y ,set_reset);
    glcd_PlotPixel(x ,y+1 ,set_reset);
    glcd_PlotPixel(x ,y+2 ,set_reset);
    glcd_PlotPixel(x ,y+3 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
    glcd_PlotPixel(x+2 ,y+3 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
}

void write_7(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x ,y ,set_reset);//Writes 7
    glcd_PlotPixel(x+1 ,y ,set_reset);
    glcd_PlotPixel(x+2 ,y ,set_reset);
    glcd_PlotPixel(x+2 ,y+1 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
    glcd_PlotPixel(x ,y+3 ,set_reset);
    glcd_PlotPixel(x ,y+4 ,set_reset);
}

void write_8(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+1 ,y ,set_reset);//Writes 8
    glcd_PlotPixel(x ,y+1 ,set_reset);
    glcd_PlotPixel(x+2 ,y+1 ,set_reset);
    glcd_PlotPixel(x ,y+3 ,set_reset);
    glcd_PlotPixel(x+2 ,y+3 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
}

void write_9(unsigned char x, unsigned char y, unsigned char set_reset)
{
    glcd_PlotPixel(x+1 ,y ,set_reset);//Writes 9
    glcd_PlotPixel(x ,y+1 ,set_reset);
    glcd_PlotPixel(x+2 ,y+1 ,set_reset);
    glcd_PlotPixel(x+2 ,y+2 ,set_reset);
    glcd_PlotPixel(x ,y+4 ,set_reset);
    glcd_PlotPixel(x+2 ,y+3 ,set_reset);
    glcd_PlotPixel(x+1 ,y+4 ,set_reset);
    glcd_PlotPixel(x+1 ,y+2 ,set_reset);
}

