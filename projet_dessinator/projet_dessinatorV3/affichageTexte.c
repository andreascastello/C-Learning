#include "affichageTexte.h"
#include <stdio.h>
#define  PI 3.14159
#include <math.h>

void printf_Point2D (Point2D p)
{
    printf ("Point 2D\n");
    printf (" - abscisse : %.3lf\n", p.x);
    printf (" - ordonnee : %.3lf\n", p.y);
    printf ("\n");
}

void printf_Segment2D (Segment2D s)
{
    printf ("Segment 2D : \n");
    printf (" - Point de depart : (%.3f , %.3f)\n", s.depart.x, s.depart.y);
    printf (" - Point d'arrivee : (%.3f , %.3f)\n", s.arrive.x, s.arrive.y);
    printf ("\n");
}

void printf_Rectangle2D (Rectangle2D r)
{
    printf ("Rectangle 2D : \n");
    float angle = (r.B.y - r.A.y) / (r.B.x - r.A.x);
    printf (" - Point A         : (%.3f , %.3f)\n", r.A.x, r.A.y);
    printf (" - Point B         : (%.3f , %.3f)\n", r.B.x, r.B.y);

    Point2D c;
    c.x = r.A.x + r.dimension * cos(atan(angle)-PI/2);
    c.y = r.A.y + r.dimension * sin(atan(angle)-PI/2);

    Point2D d;
    d.x = r.B.x - r.A.x + c.x;
    d.y = r.B.y - r.A.y + c.y;
    printf (" - Autre dimension : %.3f\n", r.dimension);
    printf ("\n");
}

void printf_Cercle2D (Cercle2D c)
{
    printf ("Cercle 2D : \n");
    printf (" - Centre : (%.3f , %.3f)\n", c.centre.x, c.centre.y);
    printf (" - Rayon  : %.3f\n", c.rayon);
    printf ("\n");
}

void printf_ArcDeCercle2D (ArcDeCercle2D a)
{
    printf ("Arc de cercle 2D :\n");
    printf (" - Centre          : (%.3f , %.3f)\n", a.centre.x, a.centre.y);
    printf (" - Rayon           : %.3f\n", a.rayon);
    printf (" - Angle de depart : %.3f\n", a.debut);
    printf (" - Angle d'arrivee : %.3f\n", a.fin);
}
