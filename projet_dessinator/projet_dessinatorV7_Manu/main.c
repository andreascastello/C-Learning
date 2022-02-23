/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module            : dessinator.c                                    */
/* Numéro de version : 0.7                                             */
/* Date              : 08/05/2021                                      */
/* Auteur            : Emmanuel Romagnoli                              */
/***********************************************************************/

#include "listeChainee.h"

int main (int argc, char* argv[])
 {
  ListeChainee* dessin = creerListe ("Essai");

  ajouterPoint       ( dessin ,  10 ,  20 ,                 ROUGE  );
  ajouterSegment     ( dessin ,  30 ,  40 , 50 ,  60 ,      VERT   );
  ajouterRectangle   ( dessin ,  70 ,  80 , 90 , 100 , 50 , BLEU   );
  ajouterCercle      ( dessin , 130 , 140 , 50 ,            BLANC  );
  ajouterArcDeCercle ( dessin , 160 , 170 , 50 ,   0 , 45 , MAGENTA);

  afficherListe (dessin);

  supprimerDansListe (dessin, 1);   // On supprime le segment

  afficherListe (dessin);

  detruireListe (dessin);

  return 0;
 }
