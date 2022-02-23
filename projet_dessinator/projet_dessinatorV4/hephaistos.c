#include "affichageTexte.h"

int main(int argc, char* argv[])
{
    Point2D p   = { 10, 20, {BLANC} };
    printf_Point2D (p);


    Segment2D s = { 30, 40, 50, 60, {ROUGE}};
    printf_Segment2D (s);

    Rectangle2D r = { 90, 100, 70, 80, 50, {VERT} };
    printf_Rectangle2D (r);

    Cercle2D c = { 130, 140, 50, {BLEU} };
    printf_Cercle2D (c);

    ArcDeCercle2D a = { 160, 170, 50, 0, 45, {JAUNE} };
    printf_ArcDeCercle2D (a);
}
