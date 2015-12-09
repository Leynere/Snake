#include "affichage.h"
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//########################
//#   LES CONSTANTES :   #
//########################
#define CLEARSCREEN "clear"

/* constantes pour le serpent et la nourriture : */
#define MAX 50  //Taille maximale du serpent



//#################################
//#   LA FONCTION PRINCIPALES :   #
//#################################

int main(int argc, char *argv[])
{
  system(CLEARSCREEN);
  brut(1);
  printf("Voici le jeu snake.Les règles sont simples:\n\t-utilsez les touches 'Z','Q','S','D' pour vous deplacer\n\t-lorsque vous vous prenez un mur ou un obstacle, vous êtes morts;\n\t-lorsque vous mangez un '.' vous gagnez un point et vous grandissez de un\n\t-lorsque vous mangez un 'B' vous gagnez 10 points mais un seul obstacle apparait(au lieu de deux) et votre serpent ne grandit que de un;\nAppuyez sur une touche pour commencer");
  getchar();
  
  COORDONNEES tete = {30,12};  //30=axe x et 12=axe y//
  COORDONNEES serpent[MAX];
  COORDONNEES sent={SENT,SENT};
  int i,j=0;
  int temps=150000;
  char rec='n'; //Pseudo sert-à-rien
  int abandon=0;
  int compteurale=0; //Compteur aléatoire
  int nombreale=0; //Nombre aléatoire
  int boolale=0;
  int accel=0; //Accélération
  int obs=0;

  touche='n';
  dir=RIGHT;
  dir2=0;

  system(CLEARSCREEN); //On actualise le terminal
  srand(time(NULL));

  /* Commencement du jeu :
     Le serpent apparaît au milieu de l'aire de jeu
     et sa longueur est de 4*/

  int longueur=7; //IL y a 4 parties du corps + la tête + la fin du corps + la valeur sentinelle = 7
  serpent[0] = tete;


  for(i=0;i<MAX;i++)//On initialise toutes les parties du corps du snake
    {
      serpent[i].y=12;
      serpent[i].x=30-j;
      j++;
    }

  obstacle[0]=sent;

  serpent[i]=sent;

  int score=0;


  printf("=========================== SNAKE !===========================\n");

  int mange=0;//variable pour savoir quand afficher la nourriture (si mange=0, alors il n'y a pas encore de nourriture)

  aireJeu();

  do{
    attente(temps);
    mouvement(serpent);
    afficheScore(score);
    compteurale++;

    while(compteurale==nombreale && boolale==0)        //gestion du temps d'attente avant l'apparition d'une nourriture bonus
      {
	afficheNourriBonus(serpent,longueur);
	compteurale=0;
	boolale=1;
	nombreale=0;
      }

    if(nombreale==0)
      nombreale=rand()%100;

    while(compteurale==nombreale && boolale==1)              //gestion du temps d'apparition de la nourriture bonus
      {
	efface(nourbonus);
	compteurale=0;
	nombreale=0;
	boolale=0;
	nourbonus.x=0;
	nourbonus.y=0;
      }

    if(touche=='p')                  //gestion de la pause
      {
	while((touche=getchar())!='p');
	touche='n';
      }

    if(touche=='a')                  //gestion de l'abandon
      abandon=1;

    if(mange==0) //S'il n'y a pas de nourriture sur l'aire de jeu, on en créer
      {
	afficheNourri(serpent, longueur);

	mange=1;
      }

    if(nourriture.x==serpent[0].x && nourriture.y==serpent[0].y)// S'il y avait déjà de la nourriture, on regarde si la tête su serpent est dessus ou non
      {
	longueur++;
	score++;
	mange=0;
	accel++;
	obs++;
	nourriture.x=100;
	nourriture.y=100;

      }

    if(nourbonus.x==serpent[0].x && nourbonus.y==serpent[0].y)  //gestion de la nourriture bonus
      {
	score=score+10;
	longueur=longueur+1;
	accel=accel+10;
	obs=obs+5;
	nourbonus.x=100;
	nourbonus.y=100;

      }

    if(accel>=10)
      {
	temps=temps-5000;
	accel=accel-10;
      }

    if(obs>=5)
      {
	afficheObstacle(serpent,longueur);
	obs=obs-5;
      }

    for(i=0;i<longueur;i++) //Pour afficher le serpent
      {
	if(i==1) afficheTete(serpent[0]);
	else
	  afficheQueue(serpent[i]);

      }
    efface(serpent[longueur-1]);




  }while(horsAire(serpent[0]) && surSerpent(serpent, serpent[0], longueur) && abandon==0 && surObstacle(serpent[0],0));
  
  goto_x_y(11,25);
  printf("GAME OVER");
  goto_x_y(12,20);
  printf("Appuyez sur E ");
  while((rec=getchar())!='e');
  system(CLEARSCREEN);
  goto_x_y(0,0);
  brut(0);
  fopen_score(score);
  brut(1);
  printf("Appuyer sur 'A pour quitter");
  while((rec=getchar())!='a');
  brut(0);
  system(CLEARSCREEN);


  return 0;
}
