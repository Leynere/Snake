#include"sur.h"


//###################################
//#   FONCTIONS DE VERIFICATION :   #
//###################################


/* Vérifie si un point est sur un obstacle */
int surObstacle(COORDONNEES a, int b)
{
  int i=0,j;
  if(b==0)
    {
      for(i=0;obstacle[i].x!=SENT;i++)
	if(obstacle[i].x==a.x && obstacle[i].y==a.y)
	  return FALSE;
      return TRUE;
    }
  if(b==1)
    {
      j=i;
      for(i=0;i<j;i++)
	if(obstacle[i].x==a.x && obstacle[i].y==a.y)
	  return FALSE;
      return TRUE;
    }
  return 0;
}


/* Vérifie si un point est sur un autre */
int surPoint(COORDONNEES point1, COORDONNEES point2)
{
      if(point1.x==point2.x && point1.y==point2.y)
	return FALSE;
    return TRUE;
}


/* Vérifie si la tête serpent est dans l'aire de jeu (renvoie FALSE si ce n'est pas le cas) */
int horsAire(COORDONNEES snakeHead)
{
    if (snakeHead.x==1 || snakeHead.x==62 || snakeHead.y==2 || snakeHead.y==21)
       return FALSE;
    return TRUE;
}


/* Vérifie si un point de l'aire de jeu fait parti du serpent ou non (renvoie TRUE c'est pas le cas) */
int surSerpent(COORDONNEES *snake, COORDONNEES point, int longueurSnake)
{
    int i=1;
    for(i=2;i<=longueurSnake;i++)
      if(snake[i].x==point.x && snake[i].y==point.y)
	return FALSE;
    return TRUE;
}


