#include "affichageTexte.h"

int main(int argc, char* argv[])
{
    Figure2D tab [5] =   {
                        { .point        = { POINT,          { BLANC },                 10, 20 }},
                        { .segment      = { SEGMENT,        { ROUGE },       30,  40,  50, 60 }},
                        { .rectangle    = { RECTANGLE,      { VERT  },  70,  80,  90, 100, 50 }},
                        { .cercle       = { CERCLE,         { BLEU  },           130, 140, 50 }},
                        { .arcDeCercle  = { ARC_DE_CERCLE,  { JAUNE }, 160, 170,  50,   0, 45 }}};

    printf ("Choisir une forme geometrique :\n - 1 : Point\n - 2 : Segment\n - 3 : Rectangle\n - 4 : Cercle\n - 5 : Arc de Cercle\n");
    printf ("\n");

    for (int i = 0;i<5;i++)
    {
        printf_Figure2D(tab[i]);
    }
    return 0;
}
