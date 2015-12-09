#ifndef __AFFICHAGE__
#define __AFFICHAGE__

#include"move.h"
#include"sur.h"



//###############################
//#   FONCTIONS D'AFFICHAGE :   #
//###############################


COORDONNEES nourriture;
COORDONNEES nourbonus;


void efface( COORDONNEES snake);
void afficheQueue(COORDONNEES snake);
void afficheObstacle(COORDONNEES *snake, int longueur);
void afficheScore(int score);
void afficheNourriBonus(COORDONNEES *snake, int longueur);
void aireJeu();
void afficheNourri(COORDONNEES *snake, int longueur);
void afficheTete(COORDONNEES snake);
void fopen_score(int a);

#endif
