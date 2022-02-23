#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "structure.h"

#define DIMX 7
#define DIMY 4


int main()
 {

  if (!SetConsoleOutputCP(65001))
   printf ("ERREUR\n");

  char labyrinthe [2][DIMY][DIMX+1] =  {{   "#######" ,      // Ne pas oublier le '\0' terminal
                                            "#J#. c#" ,
                                            "#  .  S" ,
                                            "#######" },

                                        {   "#######" ,
                                            "###.. #" ,
                                            "S  .c J" ,
                                            "#######" }};

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

  Coordonnees Joueur;
  Coordonnees Porte;
  int score = 0;
  int numLab = 0;
  int cle = 0;
  int tDebut = time(NULL);

  // On recherche le J pour initialiser les valeurs de Joueur.x et Joueur.y

  for ( int y = 0 ; y < DIMY; y++ )
   for ( int x = 0 ; x < DIMX; x++ )
    switch (labyrinthe[numLab][y][x])
     {
        case 'J' :  Joueur.x = x;
                    Joueur.y = y;
        case 'S' :  Porte.x  = x;
                    Porte.y  = y;
     }

  printf ("Au debut, Joueur X = %d et Joueur Y = %d\n", Joueur.x, Joueur.y);

  int touche;

  do
   {
    printf("Votre score est de : %d \n", score);
    for ( int y = 0 ; y < DIMY; y++ )
     {
      for ( int x = 0 ; x < DIMX; x++ )
       {
        if ( x == Joueur.x && y == Joueur.y )
              {
               printf ("☺");
              }
         else {
               switch (labyrinthe[numLab][y][x])
                {
                 case  '#' : printf ("█"); break;
                 case  '.' : printf ("…"); break;
                 case  ' ' :
                 case  'J' : printf (" "); break;
                 case  'S' : printf ("¦"); break;
                 case  'c' : printf ("€"); break;
                }
              }
       }

      printf ("\n");
     }

    printf ("\n");
    printf ("5 : vers le haut\n");
    printf ("1 : vers la gauche\n");
    printf ("3 : vers la droite\n");
    printf ("2 : vers le bas\n");
    printf ("8 : sortir du programme\n");
    printf ("\n");

    printf ("Votre choix : ");

    scanf ("%d", &touche);

    printf ("\n\n");

    switch ( touche )
     {
      case 5 : if ( labyrinthe[numLab][Joueur.y-1][Joueur.x  ] != '#' ) Joueur.y--; break;
      case 1 : if ( labyrinthe[numLab][Joueur.y  ][Joueur.x-1] != '#' ) Joueur.x--; break;
      case 3 : if ( labyrinthe[numLab][Joueur.y  ][Joueur.x+1] != '#' ) Joueur.x++; break;
      case 2 : if ( labyrinthe[numLab][Joueur.y+1][Joueur.x  ] != '#' ) Joueur.y++; break;
     }


     if (labyrinthe[numLab][Joueur.y][Joueur.x] == '.')
     {
        labyrinthe[numLab][Joueur.y][Joueur.x] = ' ';
        score = score +100;
     }

     if (labyrinthe[numLab][Joueur.y][Joueur.x] == 'c')
     {
         labyrinthe[numLab][Joueur.y][Joueur.x] = ' ';
         cle = 1;
     }
     if (labyrinthe[numLab][Joueur.y][Joueur.x] == 'S' && cle == 1)
     {
        cle = 0;
        numLab ++;
     }
     else
     {
         if (labyrinthe[numLab][Joueur.y][Joueur.x] == 'S' && cle == 0)
         {
            printf ("Vous avez besoin de la clé\n");
         }
     }

    int tFin = time(NULL);
    int temps;

    temps = tFin - tDebut;
     if (numLab == 2)
     {
        printf ("Bravo tu as gagner en %d secondes\n", temps);
        return 0;
     }
     else
     {
        if (temps > 15)
        {
            printf ("Tu as mit trop de temps a reagir\n");
            return 0;
        }
     }

    }
   while ( touche != 8 );

  printf ("On quitte le programme...\n");

  return 0;
 }
