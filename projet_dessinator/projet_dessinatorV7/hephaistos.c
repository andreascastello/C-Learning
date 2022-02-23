#include "affichageTexte.h"
#include "ListeChaine.h"
#include <stdlib.h>

int main (int argc, char* argv[])
 {
     listeChainee* dessin = creerListe ("Essai");
/*
     ajouterPoint       (dessin, 10, 20, ROUGE );
     ajouterSegment     (dessin, 30, 40, 50, 60, VERT );
     ajouterRectangle   (dessin, 70, 80, 90, 100, 50, BLEU );
     Figure2D* fig4 = ajouterCercle      (dessin, 130, 140, 50, BLANC );
     ajouterArcDeCercle (dessin, 160, 170, 50, 0, 45, MAGENTA);
*/


Figure2D* fig1 = creerPoint (10, 20, ROUGE);
Figure2D* fig2 = creerSegment (30, 40, 50, 60, VERT);
Figure2D* fig3 = creerRectangle (70, 80, 90, 100, 50, BLEU);
Figure2D* fig4 = creerCercle (130, 140, 50, BLANC);
Figure2D* fig5 = creerArcDeCercle(160, 170, 50, 0, 45, MAGENTA);

insererFin (dessin, fig1);
insererFin (dessin, fig2);
insererFin (dessin, fig3);
insererDansListe (dessin, fig4, 2); //on ajoute le cercle a la position 2
insererFin (dessin, fig5);

     afficherListe (dessin);
     supprimerDansListe (dessin, 2);
     printf ("---------------------------------------------------------------------------------------------------\n");
     printf ("On supprime la figure a la position 2 : \n");
     printf ("---------------------------------------------------------------------------------------------------\n");
     afficherListe (dessin);
     detruireListe (dessin);
    return 0;
 }



