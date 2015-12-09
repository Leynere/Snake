#include"affichage.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//###############################
//#   FONCTIONS D'AFFICHAGE :   #
//###############################

/* Fonction qui permet d'afficher l'aire de jeu */
void aireJeu()
{
    int i=0;
    for(i=0;i<62;i++)
    {
       printf("#");
    }
    printf("\n");
    for(i=0;i<18;i++)
    {
       int j=0;
       printf("#");
       for(j=0;j<60;j++)
           printf(" ");
       printf("#\n");
    }
    for(i=0;i<62;i++)
    {
       printf("#");
    }
    printf("\n");


}



/* Affiche la tête du serpent */
void afficheTete(COORDONNEES snake)
{
    goto_x_y(snake.y, snake.x);
    printf("0");
}


/* Permet de créer de la nourriture à un emplacement aléatoire */
void  afficheNourri(COORDONNEES *snake, int longueur)
{

     do
       {
       nourriture.x=rand()%58+1;
       nourriture.y=rand()%17+1;


       }while(surSerpent(snake, nourriture, longueur)!=1 || nourriture.x<2 || nourriture.y<3 ||surPoint(nourriture,nourbonus)!=1|| surObstacle(nourriture,0)!=1);
    goto_x_y(nourriture.y, nourriture.x);
    printf(".");
}


/* Affiche la queue */
void afficheQueue(COORDONNEES snake)
{
    goto_x_y(snake.y, snake.x);
    printf("o");
}



/* Efface la queue du serpent lors de son déplacement (le serpent ne laisse ainsi aucune trace derrière lui) */
void efface( COORDONNEES snake)
{

  goto_x_y(snake.y, snake.x);
  printf(" ");
}




//###########################
//#       LES BONUS :       #
//###########################
/* Affiche le score et les touches pour stopper / abandonner le jeu */
void afficheScore(int score)
{
  goto_x_y(22, 0);
  printf("Score : %d\nAppuyez sur P pour stopper ou reprendre le jeu\nAppuyez sur A pour abandonner ", score);
}

/* Affiche la nourriture bonus */
void afficheNourriBonus(COORDONNEES *snake, int longueur)
{
     do
       {
	 nourbonus.x=rand()%58+1;
	 nourbonus.y=rand()%17+1;


       }while(surSerpent(snake, nourbonus, longueur)!=1 || nourbonus.x<2 || nourbonus.y<3 || surPoint(nourriture,nourbonus)!=1|| surObstacle(nourbonus,0)!=1);
    goto_x_y(nourbonus.y, nourbonus.x);
    printf("B");

}


/* Affiche un obstacle dans l'aire de jeu */
void afficheObstacle(COORDONNEES *snake, int longueur)
{
  int i;
  for(i=0;obstacle[i].x!=SENT;i++);
  obstacle[i+1]=obstacle[i];
  do
       {
	 obstacle[i].x=rand()%58+1;
	 obstacle[i].y=rand()%17+1;

       }while(surSerpent(snake, obstacle[i], longueur)!=1 ||obstacle[i].x<2 || obstacle[i].y<3 || surPoint(obstacle[i],nourbonus)!=1|| surObstacle(obstacle[i],1)!=1 || surPoint(obstacle[i],nourriture)!=1);
  goto_x_y(obstacle[i].y, obstacle[i].x);
  printf("H");
}

/*Permet de stocker le score s'il fait partie des 10 meilleur et ensuite d'afficher ces derniers*/
void fopen_score(int a)
{
  FILE *score=fopen("./data/score.txt","r+");
  FILE *pseudo=fopen("./data/pseudo.txt","r+");
  char ** pseud;
  int *scor;
  int *scor2;
  char **pseud2;
  int i;
  if((scor=(int *)calloc(10,sizeof(int)))==NULL)
    {
      printf("Erreur");
      return;
    }

  if((scor2=(int *)calloc(10,sizeof(int)))==NULL)
    {
      printf("Erreur");
      return;
    }
  
  if((pseud=(char**)malloc(10 *sizeof(char *)))==NULL)
    {
      printf("Erreur");
      return;
    }

  if((pseud2=(char**)malloc(10 *sizeof(char *)))==NULL)
    {
      printf("Erreur");
      return;
    }
  
  for(i=0;i<10;i++)
    {
      if((pseud[i]=(char*)malloc(80 *sizeof(char)))==NULL)
	{
	  printf("Erreur");
	return;
	}
      if((pseud2[i]=(char*)malloc(80 *sizeof(char)))==NULL)
	{
	  printf("Erreur");
	  return;
	}
    }
      
  for(i=0;i<10;i++)
    {
      fscanf(score,"%d",&scor[i]);
      fscanf(pseudo,"%s",pseud[i]);
    }
  if(a>scor[9])
    {
      for(i=0;scor[i]>a;i++)
	{
	  scor2[i]=scor[i];
	  strcpy(pseud2[i],pseud[i]);
	}
      scor2[i]=a;
      printf("Entrez votre pseudo:");
      scanf("%s",pseud2[i]);
      for(i++;i<10;i++)
	{
	  scor2[i]=scor[i-1];
	  strcpy(pseud2[i],pseud[i-1]);
	}

      rewind(score);
      rewind(pseudo);

      for(i=0;i<10;i++)
	{
	  fprintf(score,"%d\n",scor2[i]);
	  fprintf(pseudo,"%s\n",pseud2[i]);
	}
      
    }
  else
    for(i=0;i<10;i++)
      {
	scor2[i]=scor[i];
	strcpy(pseud2[i],pseud[i]);
      }
    
      for(i=0;i<10;i++)
	printf("%s....%d\n",pseud2[i],scor2[i]);

      free(scor);
      scor=NULL;
      free(scor2);
      scor2=NULL;


      for(i=0;i<10;i++)
	{
	  free(pseud[i]);
	  pseud[i]=NULL;
	  free(pseud2[i]);
	  pseud2[i]=NULL;

	}
      free(pseud);
      pseud=NULL;
      free(pseud2);
      pseud2=NULL; 
      
      fclose(score);
      score=NULL;
      fclose(pseudo);
      pseudo=NULL;

}
