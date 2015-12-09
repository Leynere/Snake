#include"move.h"
#include<stdio.h>


//##################################
//#   FONCTIONS DE DEPLACEMENT :   #
//##################################

/* permet de changer la direction de la tête du serpent */
int directionTete(char direction)
{

    if (direction == UP)
       return -1;
    if (direction == DOWN)
     return 1;
    if (direction == LEFT)
       return -2;
    if (direction == RIGHT)
     return 2;
    else
      return 0;
}

/* Calcule les coordonnées des parties du corps du serpent lorsqu'il est en déplacement */
void calculCoor(COORDONNEES *b) // le parametre *b est celui obtenu par la fonction calculTete donc se fera après l'execution de calculTete
{
  int i,c;
  COORDONNEES temp,temp2;
  temp=b[0];
  c=0;
  for(i=0;b[i].x!=SENT;i++)
    {
      if (c%2==0)
	{
	  temp2=b[i];
	  b[i]=temp;
	}
      if(c%2==1)
	{
	   temp=b[i];
	   b[i]=temp2;
	}
       c++;
    }
}

/* Calcule les coordonnées de la tête du serpent en fonction de sa direction */
int calculTete(COORDONNEES *b,int i) //le parametre sera le resultat retourné par directionTete et coordonnees b le tableau contenant le corps du serpent
{
 if(i==1)
    {b[0].y++;
     return 1;}
 if(i==-1)
    {b[0].y--;
     return 1;}
 if(i==-2)
    {b[0].x--;
     return 0;}
 if(i==2)
    {b[0].x++;
     return 0;}
 return 2;
}

/* Permet de savoir quelle touche le joueur a tapé et la stocke en fonction de la direction du serpent */
char deplacement(int x,char a)
{
  if(foo()!=1)
    return a;
  touche=getchar();
  if(x==1)
    if(touche==RIGHT || touche==LEFT)
      return touche;
  if(x==0)
    if(touche==UP || touche==DOWN)
      return touche;
  return a;
}



/*
  Etape des appel fonction:
  -deplacement;
  -directionTete;
  -calculTete;
  -calculCoor;
  -deplacement(<variable_qui_a_recu_le_resultat_de_calcul_tete>,<variable_char_dir>);

*/


/* Permet le bon déplacement du serpent dans l'aire de jeu, en fonction de la touche stcké dans la variable dir */
void mouvement(COORDONNEES *b)
{
  int a;
  dir=deplacement(dir2,dir);            //char dir et int dir2 definie avant main:variable global
  a=directionTete(dir);
  dir2=calculTete(b,a);
  calculCoor(b);

}

