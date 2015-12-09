#ifndef __TECH__
#define __TECH__

#include<termios.h>
struct termios initial;
struct termios modif;

//#####################
//#   UTILITAIRES :   #
//#####################

void brut(int option);
int foo();
void attente( float a);
void goto_x_y(unsigned y, unsigned x);

#endif
