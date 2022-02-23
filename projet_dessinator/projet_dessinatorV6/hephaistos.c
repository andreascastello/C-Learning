#include "affichageTexte.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{


Figure2D* tab [5] = {
                        { creerPoint        (10,  20,               BLANC)  },
                        { creerSegment      (30,  40,  50,  60,     ROUGE)  },
                        { creerRectangle    (70,  80,  90, 100, 50, VERT)   },
                        { creerCercle       (130, 140, 50,          BLEU)   },
                        { creerArcDeCercle  (160, 170, 50,   0, 45, JAUNE)  }};


/*
tab[0]      = creerPoint        (10,  20,               BLANC);
tab[1]      = creerSegment      (30,  40,  50,  60,     ROUGE);
tab[2]      = creerRectangle    (70,  80,  90, 100, 50, VERT);
tab[3]      = creerCercle       (130, 140, 50,          BLEU);
tab[4]      = creerArcDeCercle  (160, 170, 50,   0, 45, JAUNE);
*/



    printf ("Choisir une forme geometrique :\n - 1 : Point\n - 2 : Segment\n - 3 : Rectangle\n - 4 : Cercle\n - 5 : Arc de Cercle\n");
    printf ("\n");

    for (int i = 0;i<5;i++)
    {
        printf_Figure2D(tab[i]);
    }

    for (int i = 0;i<5;i++)
    {
        supprimerFigure (tab[i]);
    }

    return 0;
}
