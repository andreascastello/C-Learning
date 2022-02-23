#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define DIMX 7
#define DIMY 4

typedef int bool;

#define VRAI 1
#define FAUX 0


int main()
 {
  if (!SetConsoleOutputCP(65001))
   printf ("ERREUR\n");

  char labyrinthe [2][DIMY][DIMX+1] = {
                                       { "#######" ,      // Ne pas oublier le '\0' terminal
                                         "#C#.  #" ,
                                         "#J .#P#" ,
                                         "#######" } ,
                                       { "#######" ,      // Ne pas oublier le '\0' terminal
                                         "#P .#.#" ,
                                         "# #. .#" ,
                                         "#######" }
                                      };

  int xJoueur;
  int yJoueur;

  int numLaby;

  int xPorte[2];
  int yPorte[2];

  bool possedeCle = FAUX;

  // On recherche le J pour initialiser les valeurs de xJoueur et yJoueur

  for ( int numLaby = 0 ; numLaby < 2; numLaby++ )
   for ( int y = 0 ; y < DIMY; y++ )
    for ( int x = 0 ; x < DIMX; x++ )
     switch (labyrinthe[numLaby][y][x])
      {
       case 'J' : xJoueur = x;
                  yJoueur = y;
                  break;
       case 'P' : xPorte[numLaby] = x;
                  yPorte[numLaby] = y;
      }

  printf ("Au debut, xJoueur=%d et yJoueur=%d dans le premier labyrinthe\n", xJoueur, yJoueur);

  printf ("xPorte[0]=%d et yPorte[0]=%d dans le premier labyrinthe\n", xPorte[0], yPorte[0]);
  printf ("xPorte[1]=%d et yPorte[1]=%d dans le second  labyrinthe\n", xPorte[1], yPorte[1]);

  int touche;

  int score = 0;

  do
   {
    printf ("\nSCORE : %d - ", score);

    printf ("%s labyrinthe - ", ( numLaby==0 ? "Premier" : "Second" ));

    printf ("Clé : %s\n\n", ( possedeCle ? "OUI" : "NON" ));

    for ( int y = 0 ; y < DIMY; y++ )
     {
      for ( int x = 0 ; x < DIMX; x++ )
       {
        if ( x == xJoueur && y == yJoueur )
              {
               printf ("☺");
              }
         else {
               switch (labyrinthe[numLaby][y][x])
                {
                 case  '#' : printf ("█"); break;
                 case  '.' : printf ("░"); break;
                 case  ' ' :
                 case  'J' : printf (" "); break;
                 case  'P' : printf ("◊"); break;
                 case  'C' : printf ("♪"); break;
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
      case 1 : if ( labyrinthe[numLaby][yJoueur-1][xJoueur  ] != '#' ) yJoueur--; break;
      case 2 : if ( labyrinthe[numLaby][yJoueur  ][xJoueur-1] != '#' ) xJoueur--; break;
      case 3 : if ( labyrinthe[numLaby][yJoueur  ][xJoueur+1] != '#' ) xJoueur++; break;
      case 4 : if ( labyrinthe[numLaby][yJoueur+1][xJoueur  ] != '#' ) yJoueur++; break;
     }

    if ( labyrinthe[numLaby][yJoueur][xJoueur] == '.' )
     {
      score++;
      labyrinthe[numLaby][yJoueur][xJoueur] = ' ';
     }

    if ( labyrinthe[numLaby][yJoueur][xJoueur] == 'C' )
     {
      possedeCle = 1;
      labyrinthe[numLaby][yJoueur][xJoueur] = ' ';
     }

    if ( labyrinthe[numLaby][yJoueur][xJoueur] == 'P' )
     {
      if ( possedeCle == 1 )
       {
        switch (numLaby)
         {
          case 0 : xJoueur = xPorte[1];
                   yJoueur = yPorte[1];
                   numLaby = 1;
                   break;

          case 1 : xJoueur = xPorte[0];
                   yJoueur = yPorte[0];
                   numLaby = 0;
         }
       }
     }
   }
   while ( touche != 5 );

  printf ("On quitte le programme...\n");

  return 0;
 }
