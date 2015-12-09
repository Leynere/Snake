#ifndef __SUR__
#define __SUR__

#include "coor.h"
#define TRUE 1  // fichier d'affichage
#define FALSE 0 // pareil

//###################################
//#   FONCTIONS DE VERIFICATION :   #
//###################################


COORDONNEES obstacle[200];

int horsAire(COORDONNEES snakeHead);
int surSerpent(COORDONNEES *snake, COORDONNEES point, int longueurSnake);
int surPoint(COORDONNEES point1, COORDONNEES point2);
int surObstacle(COORDONNEES a,int b);

#endif
