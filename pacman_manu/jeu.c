#include "jeu.h"

#include <stdio.h>
#include <stdlib.h>
#include "interfaceGraphique.h"

char* labyrinthe [] = { "##########" ,
                        "#JOa#O F #" ,
                        "#a# # #  #" ,
                        "# #   #  #" ,
                        "# #####  #" ,
                        "# #   #  #" ,
                        "#   # #  #" ,
                        "#O#a#a a #" ,
                        "#        #" ,
                        "##########" };

int dimx = 10;
int dimy = 10;

int xJoueur;
int yJoueur;

int xFantome;
int yFantome;

int initP = 0 ;
int initF = 0 ;

void afficherMur (int x, int y)
 {
/*
  dessinerRectangle ( x    * TAILLE ,  y    * TAILLE, // Abscisse et ordonnée du coin supérieur gauche
                     (x+1) * TAILLE , (y+1) * TAILLE, // Abscisse et ordonnée du coin inférieur droit
                      0,                                  // Proportion de rouge pour le trait de délimitation (entre 0 et 1)
                      0,                                  // Proportion de vert  pour le trait de délimitation (entre 0 et 1)
                      1,                                  // Proportion de bleu  pour le trait de délimitation (entre 0 et 1)
                      0,                                  // Proportion de rouge pour l'intérieur du rectangle (-1 signifie pas de remplissage)
                      0,                                  // Proportion de vert  pour l'intérieur du rectangle (-1 signifie pas de remplissage)
                      1);                                 // Proportion de bleu  pour l'intérieur du rectangle (-1 signifie pas de remplissage)
*/

  dessinerImage (  x    * TAILLE ,       // Abscisse du coin inférieur gauche (inversé a cause des limites)
                  (y+1) * TAILLE ,       // Ordonnee du coin inférieur gauche (inversé a cause des limites)
                   1, 1 ,
                   1             );      // Numero de l'image
 }

void afficherSol (int x, int y)
 {
  dessinerRectangle ( x    * TAILLE ,    y  * TAILLE, // Abscisse et ordonnée du coin supérieur gauche
                     (x+1) * TAILLE , (y+1) * TAILLE, // Abscisse et ordonnée du coin inférieur droit
                      0,                                  // Proportion de rouge pour le trait de délimitation (entre 0 et 1)
                      0,                                  // Proportion de vert  pour le trait de délimitation (entre 0 et 1)
                      0,                                  // Proportion de bleu  pour le trait de délimitation (entre 0 et 1)
                      0,                                  // Proportion de rouge pour l'intérieur du rectangle (entre 0 et 1)
                      0,                                  // Proportion de vert  pour l'intérieur du rectangle (entre 0 et 1)
                      0);                                 // Proportion de bleu  pour l'intérieur du rectangle (entre 0 et 1)

}

void afficherJoueur (int x, int y)
 {
  afficherSol(x,y);
/*
  dessinerArcDeCercle ( (x+0.5) * TAILLE , (y+0.5) * TAILLE,      // Abscisse et ordonnée du centre
                         0.4*TAILLE,                                // Rayon du cercle
                         45, 315,                                     // Angle de début et de fin (exprimes en degres)
                         1,                                           // Proportion de rouge pour le trait de délimitation (entre 0 et 1)
                         1,                                           // Proportion de vert  pour le trait de délimitation (entre 0 et 1)
                         0,                                           // Proportion de bleu  pour le trait de délimitation (entre 0 et 1)
                         1,                                           // Proportion de rouge pour l'intérieur du rectangle (entre 0 et 1)
                         1,                                           // Proportion de vert  pour l'intérieur du rectangle (entre 0 et 1)
                         0);                                          // Proportion de bleu  pour l'intérieur du rectangle (entre 0 et 1)
*/

  dessinerImage (  x    * TAILLE ,       // Abscisse du coin inférieur gauche (inversé a cause des limites)
                  (y+1) * TAILLE ,       // Ordonnee du coin inférieur gauche (inversé a cause des limites)
                   1, 1 ,
                   0             );      // Numero de l'image
 }

void afficherPacgomme (int x, int y)
 {
  // TODO
 }

void afficherPastille (int x, int y)
 {
  // TODO
 }

void afficherFantome (int x, int y)
 {
  dessinerImage (  x    * TAILLE ,       // Abscisse du coin inférieur gauche (inversé a cause des limites)
                  (y+1) * TAILLE ,       // Ordonnee du coin inférieur gauche (inversé a cause des limites)
                   1, 1 ,
                   2             );      // Numero de l'image
 }

void afficherJeu ()
 {
  int x, y;

  effacerDessin ();

  for(x=0; x<dimx; x++)
   for (y=0; y<dimy; y++)
    {
     switch (labyrinthe[y][x])
      {
       case '#': afficherMur(x,y);
                 break;

       case ' ': afficherSol (x,y);
                 break;

       case 'J': afficherSol (x,y);
                 if (!initP)
                  {
                   xJoueur = x;
                   yJoueur = y;
                   initP=1;
                   chargerImageBMP ( "./pacman.bmp" );
                   chargerImageBMP ( "./mur.bmp" );
                   chargerImageBMP ( "./fantome.bmp" );
                  }
                 break;

       case 'F': afficherSol(x,y);
                 if (!initF)
                  {
                   xFantome = x;
                   yFantome = y;
                   initF=1;
                  }
                 break;

       case 'O': afficherPacgomme (x,y);
                 break;

       case 'a': afficherPastille (x,y);
      }
    }

   afficherJoueur  ( xJoueur  , yJoueur  );
   afficherFantome ( xFantome , yFantome );
  }

void deplacerFantome (int dir)
 {
  switch (dir)
   {
    case NORD  : if (labyrinthe[yFantome+1][xFantome] != '#') yFantome ++;
                 break;

    case EST   : if (labyrinthe[yFantome][xFantome+1] != '#') xFantome ++;
                 break;

    case SUD   : if (labyrinthe[yFantome-1][xFantome] != '#') yFantome --;
                 break;

    case OUEST : if (labyrinthe[yFantome][xFantome-1] != '#') xFantome --;
                 break;
   }

  afficherJeu ();
 }

void deplacerJoueur (int dir)
 {
  switch (dir)
   {
    case NORD  : if (labyrinthe[yJoueur+1][xJoueur] != '#') yJoueur ++;
                 break;

    case EST   : if (labyrinthe[yJoueur][xJoueur+1] != '#') xJoueur ++;
                 break;

    case SUD   : if (labyrinthe[yJoueur-1][xJoueur] != '#') yJoueur --;
                 break;

    case OUEST : if (labyrinthe[yJoueur][xJoueur-1] != '#')xJoueur --;
                 break;
   }

  afficherJeu ();
 }



long date1 = 0;
long date2 = 0;

void fonctionPeriodique ( uint64_t a , uint64_t b , uint64_t c)
 {
   date1 = a; //nbNanosecondes

   if ( date1 - date2 > 100000000 )
    {
   //  printf ("PERIODIQUE %ld\n", (date1 - date2));
     date2 = date1;
     deplacerFantome(rand()%4);
    }
 }

void toucheEnfoncee ( uint64_t a , uint64_t b , uint64_t c)
 {
  printf ("toucheEnfoncee      => a=%lu, b=%lu et c=%lu\n" , a, b, c);

  switch (a)
   {
    case 111 : deplacerJoueur (SUD);
               break;

    case 114 : deplacerJoueur (EST);
               break;

    case 116 : deplacerJoueur (NORD);
               break;

    case 113 : deplacerJoueur (OUEST);
               break;

    case  65 : printf ("On a appuyé sur la touche espace !!\n");
               break;

    case   9 : printf ("On a appuyé sur la touche echap !!\n");

               arreterGestionEvenements ();

               break;
   }
 }

// a correspond au code de la touche relâchée
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void toucheRelachee ( uint64_t a , uint64_t b , uint64_t c)
 {
  printf ("toucheRelachee      => a=%lu, b=%lu et c=%lu\n" , a, b, c);
 }

// a correspond au code du bouton de la souris, qui est enfoncé
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void boutonSourisEnfonce ( uint64_t a , uint64_t b , uint64_t c)
 {
  printf ("boutonSourisEnfonce => a=%lu, b=%lu et c=%lu\n" , a, b, c);
 }

// a correspond au code du bouton de la souris, qui est relâchée
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void boutonSourisRelache ( uint64_t a , uint64_t b , uint64_t c)
 {
  printf ("boutonSourisRelache => a=%lu, b=%lu et c=%lu\n" , a, b, c);
 }

// a n'a pas de signification et est mis à 0
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void mouvementSouris ( uint64_t a , uint64_t b , uint64_t c)
 {
  printf ("mouvementSouris     => a=%lu, b=%lu et c=%lu\n" , a, b, c);
 }


