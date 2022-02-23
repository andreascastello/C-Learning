#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
#include "types.h"
#include "affichageTexte.h"

int main(int argc, char* argv[])
{
    Point2D p   = { 10, 20 };
    printf_Point2D (p);


    Segment2D s;
    s.depart.x  = 30;
    s.depart.y  = 40;
    s.arrive.x  = 50;
    s.arrive.y  = 60;
    printf_Segment2D (s);

    Rectangle2D r;
    r.B.x       = 90;
    r.B.y       = 100;
    r.A.x       = 70;
    r.A.y       = 80;
    r.dimension = 50;
    printf_Rectangle2D (r);

    Cercle2D c;
    c.centre.x  = 130;
    c.centre.y  = 140;
    c.rayon     = 50;
    printf_Cercle2D (c);

    ArcDeCercle2D a;
    a.centre.x  = 160;
    a.centre.y  = 170;
    a.rayon     = 50;
    a.debut     = 0;
    a.fin       = 45;
    printf_ArcDeCercle2D (a);
}
