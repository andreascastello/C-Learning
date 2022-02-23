#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

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
                                            "###..J#" ,
                                            "S  .#  " ,
                                            "#######" }};

  int xJoueur;
  int yJoueur;
  int score = 0;
  int numLab = 0;
  int cle = 0;

  // On recherche le J pour initialiser les valeurs de xJoueur et yJoueur

  for ( int y = 0 ; y < DIMY; y++ )
   for ( int x = 0 ; x < DIMX; x++ )
    switch (labyrinthe[numLab][y][x])
     {
      case 'J' : xJoueur = x;
                 yJoueur = y;
     }

  printf ("Au debut, xJoueur=%d et yJoueur=%d\n", xJoueur, yJoueur);

  int touche;

  do
   {
    printf("Votre score est de : %d \n", score);
    for ( int y = 0 ; y < DIMY; y++ )
     {
      for ( int x = 0 ; x < DIMX; x++ )
       {
        if ( x == xJoueur && y == yJoueur )
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
      case 5 : if ( labyrinthe[numLab][yJoueur-1][xJoueur  ] != '#' ) yJoueur--; break;
      case 1 : if ( labyrinthe[numLab][yJoueur  ][xJoueur-1] != '#' ) xJoueur--; break;
      case 3 : if ( labyrinthe[numLab][yJoueur  ][xJoueur+1] != '#' ) xJoueur++; break;
      case 2 : if ( labyrinthe[numLab][yJoueur+1][xJoueur  ] != '#' ) yJoueur++; break;
     }


     if (labyrinthe[numLab][yJoueur][xJoueur] == '.')
     {
        labyrinthe[numLab][yJoueur][xJoueur] = ' ';
        score = score +100;
     }

     if (labyrinthe[numLab][yJoueur][xJoueur] == 'c')
     {
         labyrinthe[numLab][yJoueur][xJoueur] = ' ';
         cle = 1;
     }

     if (labyrinthe[numLab][yJoueur][xJoueur] == 'S')
     {
        numLab ++;
     }
    }
   while ( touche != 8 );

  printf ("On quitte le programme...\n");

  return 0;
 }
