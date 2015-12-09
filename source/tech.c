#include"tech.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

//#####################
//#   UTILITAIRES :   #
//#####################


/* Permet le passage en mode brut / normal du terminal */
void brut(int option)
{
  if (option==0)
    tcsetattr(0,TCSANOW,&initial); //passage en mode "normal"(ou "cooked") du terminal
  if (option==1)
    {
      tcgetattr(0,&initial);   //stockage du mode du terminal avant modification
      cfmakeraw(&modif);        //creation de la structure "brut"
      modif.c_oflag=initial.c_oflag; //restauration de la sortie standard en "initial"
      tcsetattr(0,TCSANOW,&modif);   //passage du terminal en mode "brut"
    }

}

int foo()
{
  int a;
  struct timeval bla={0,0};             //intialisation de l'interval d'attente a 0
  fd_set memtamp;                       //creation d'un ensemble de descripteur memtemp
  FD_ZERO(&memtamp);                    //remet a zero l'ensemble memtamp
  FD_SET(0,&memtamp);                   //ajoute un descipteur de stdin a l'ensemble  memtamp
  a=select(1,&memtamp,NULL,NULL,&bla);  //renvoie la verification de la memoire tampon(ou buffer)de stdin
  return a;
}


/* Permet de mettre un certain temps avant d'afficher le serpent (celui-ci ne s'affiche donc plus instantément) */
void attente( float a)
{
 usleep(a);
 fflush(stdout);
}



/* Permet de créer un repère dans le terminal et de s'y déplacer */
void goto_x_y(unsigned y, unsigned x)
{
    printf("\033[%u;%uH", y, x);
}

