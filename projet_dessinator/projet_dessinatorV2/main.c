#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
typedef struct str_Point2D
{
    double x;
    double y;
}
Point2D;

typedef struct str_Segment2D
{
    Point2D depart;
    Point2D arrive;
}
Segment2D;

typedef struct str_Rectangle2D
{
    Point2D A;
    Point2D B;
    float dimension;
}
Rectangle2D;

typedef struct str_Cercle2D
{
    Point2D centre;
    double rayon;
}
Cercle2D;

typedef struct str_ArcDeCercle2D
{
    Point2D centre;
    double rayon;
    double debut;
    double fin;
}
ArcDeCercle2D;

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

int main()
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
