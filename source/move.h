#ifndef __MOVE__
#define __MOVE__

#include "coor.h"
#include "tech.h"

//##################################
//#   FONCTIONS DE DEPLACEMENT :   #
//##################################


/* Les commandes du jeu : */
#define UP 'z' // '122' fichier move
#define DOWN 's' // '115'
#define LEFT 'q'// '113'
#define RIGHT 'd' //'100'

char dir;
int dir2;
char touche;


char deplacement(int x,char a);
void mouvement(COORDONNEES *b);
void calculCoor(COORDONNEES *b);
int calculTete(COORDONNEES *b,int i);
int directionTete(char direction);

#endif
