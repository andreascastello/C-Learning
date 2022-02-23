#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Structures.h"

#define DIMX 20
#define DIMY 9



int main()
 {
  if (!SetConsoleOutputCP(65001))
   printf ("ERREUR\n");

  char labyrinthe [2][DIMY][DIMX+1]  = {{ "####################" ,      // Ne pas oublier le '\0' terminal
                                          "#J   ############# #" ,
                                          "#### #           # #" ,
                                          "#    # ####### # # #" ,
                                          "# ##   #       # # #" ,
                                          "#C################ #" ,
                                          "#..................#" ,
                                          "##########S#########" ,
                                        },

                                        {
                                          "####################" ,
                                          "#J      #          #" ,
                                          "# ##    # ######## #" ,
                                          "# ##   ## ######## #" ,
                                          "# #####       #### #" ,
                                          "# #######  ####### #" ,
                                          "# ################ #" ,
                                          "#..................#" ,
                                          "#########S##########" ,
                                          }};
/*
 ####################
 #J   #############p#
 #### #           # #
 #    # ####### # # #
 # ##   #P      # # #
 # ################ #
 #..................#
 ####################

 ####################
 #       #          #
 # ##   r# ######## #
 # ##q  ## ######## #
 # #####P     Q#### #
 # ####### R####### #
 # ################ #
 #..................#
 ####################

 ####################
 #Q                 #
 ################## #
 #..................#
 # ##################
 #                  #
 ################## #
 #..................#
 ####################

 ####################
 # #############    #
 #               ## #
 # ############# ## #
 # ##         ## ## #
 # ## ####### ## ####
 # ## ## #### ##   R#
 #    ##..... #######
 ####################
*/
  Coordonnees joueur;
  Coordonnees porte;
  int score = 0;
  int numLab = 0;
  int cle = 0;
  int Tdebut = time(NULL);

  printf("Vous avez 15 secondes pour finir le niveau, bonne chance !\n");

  // On recherche le J pour initialiser les valeurs de xJoueur et yJoueur

  for ( int y = 0 ; y < DIMY; y++ )
   for ( int x = 0 ; x < DIMX; x++ )
    switch (labyrinthe[numLab][y][x])
     {
      case 'J' : joueur.x = x;
                 joueur.y = y; break;
      case 'S' : porte.x = x;
                 porte.y = y;break;
     }


  int touche;

  do
   {


   printf("Votre score est de : %d \n", score);

    for ( int y = 0 ; y < DIMY; y++ )
     {
      for ( int x = 0 ; x < DIMX; x++ )
       {
        if ( x == joueur.x && y == joueur.y )
              {
               printf ("☺");
              }
        else {
               switch (labyrinthe[numLab][y][x])
                {
                 case  '#' : if (y == 0)
                                {
                                    printf("▄");
                                    break;
                                }
                                else if (y == DIMY - 1)
                                {
                                    printf("▀");
                                    break;
                                }
                else
                             printf ("█"); break;
                 case  '.' : printf ("◊"); break;
                 case  ' ' :
                 case  'J' : printf (" "); break;
                 case  'S' : printf ("¦"); break;
                 case  'C' : printf ("©"); break;
                }
              }

       }

      printf ("\n");
     }

    printf ("\n");
    printf ("1 : vers le haut\n");
    printf ("2 : vers la gauche\n");
    printf ("3 : vers la droite\n");
    printf ("4 : vers le bas\n");
    printf ("5 : sortir du programme\n");
    printf ("\n");

    printf ("Votre choix : ");

    scanf ("%d", &touche);

    printf ("\n\n");

    switch ( touche )
     {
      case 5 : if ( labyrinthe[numLab][joueur.y-1][joueur.x   ] != '#' ) joueur.y--;break;
      case 1 : if ( labyrinthe[numLab][joueur.y  ][joueur.x -1] != '#' ) joueur.x--; break;
      case 3 : if ( labyrinthe[numLab][joueur.y  ][joueur.x +1] != '#' ) joueur.x++;break;
      case 2 : if ( labyrinthe[numLab][joueur.y+1][joueur.x   ] != '#' ) joueur.y++; break;
     }

    if (labyrinthe[numLab][joueur.y][joueur.x]=='.')
    {
        labyrinthe[numLab][joueur.y][joueur.x] = ' ';
        score = score + 100;
    }
    if (labyrinthe[numLab][joueur.y][joueur.x]=='C')
    {
        labyrinthe[numLab][joueur.y][joueur.x] =' ';
        cle = 1;
    }

    if (labyrinthe[numLab][joueur.y][joueur.x]=='S' && cle == 1)
    {
        cle = 0;
        numLab++;
    }
    else if (labyrinthe[numLab][joueur.y][joueur.x]=='S' && cle == 0)
    {
        joueur.x--;
    }

    int Tfin = time(NULL);
    int secondes = Tfin - Tdebut;

    if (numLab == 2)
    {
        printf("Vous avez mis %d s à terminer le niveau, Bravo !\n", secondes);
        touche = 8;
    }
    else if (secondes > 300)
    {
        printf("Vous n'avez pas fini le niveau a temps, reessayez...\n");
        touche = 8;
    }
   }
   while ( touche != 8 );

   printf ("On quitte le programme...\n");

  return 0;
 }
