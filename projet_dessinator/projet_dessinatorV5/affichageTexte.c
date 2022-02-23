#include "affichageTexte.h"
#include <stdio.h>
#define  PI 3.14159
#include <math.h>

void printf_Point2D (Point2D p)
{
    printf ("Point 2D\n");
    printf (" - abscisse : %.3lf\n", p.x);
    printf (" - ordonnee : %.3lf\n", p.y);
    printf (" - rouge    : %.3lf\n", p.couleur.rouge);
    printf (" - vert     : %.3lf\n", p.couleur.vert);
    printf (" - bleu     : %.3lf\n", p.couleur.bleu);
    printf ("\n");
}

void printf_Segment2D (Segment2D s)
{
    printf ("Segment 2D : \n");
    printf (" - Point de depart : (%.3f , %.3f)\n", s.departX, s.departY);
    printf (" - Point d'arrivee : (%.3f , %.3f)\n", s.arriveeX, s.arriveeY);
    printf (" - rouge           : %.3lf\n", s.couleur.rouge);
    printf (" - vert            : %.3lf\n", s.couleur.vert);
    printf (" - bleu            : %.3lf\n", s.couleur.bleu);
    printf ("\n");
}

void printf_Rectangle2D (Rectangle2D r)
{
    printf ("Rectangle 2D : \n");
    printf (" - Point A         : (%.3f , %.3f)\n", r.AX, r.AY);
    printf (" - Point B         : (%.3f , %.3f)\n", r.BX, r.BY);
    printf (" - rouge           : %.3lf\n", r.couleur.rouge);
    printf (" - vert            : %.3lf\n", r.couleur.vert);
    printf (" - bleu            : %.3lf\n", r.couleur.bleu);
/*
    Point2D c;
    c.x = r.AX + r.dimension * cos(atan(angle)-PI/2);
    c.y = r.AY + r.dimension * sin(atan(angle)-PI/2);

    float angle = (r.BY - r.AY) / (r.BX - r.AX);

    Point2D d;
    d.x = r.BX - r.AX + c.X;
    d.y = r.BY - r.AY + c.y;
    printf (" - Autre dimension : %.3f\n", r.dimension);*/
    printf ("\n");
}

void printf_Cercle2D (Cercle2D c)
{
    printf ("Cercle 2D : \n");
    printf (" - Centre : (%.3f , %.3f)\n", c.centreX, c.centreY);
    printf (" - Rayon  : %.3f\n", c.rayon);
    printf (" - rouge  : %.3lf\n", c.couleur.rouge);
    printf (" - vert   : %.3lf\n", c.couleur.vert);
    printf (" - bleu   : %.3lf\n", c.couleur.bleu);
    printf ("\n");
}

void printf_ArcDeCercle2D (ArcDeCercle2D a)
{
    printf ("Arc de cercle 2D :\n");
    printf (" - Centre          : (%.3f , %.3f)\n", a.centreX, a.centreY);
    printf (" - Rayon           : %.3f\n", a.rayon);
    printf (" - Angle de depart : %.3f\n", a.debut);
    printf (" - Angle d'arrivee : %.3f\n", a.fin);
    printf (" - rouge           : %.3lf\n", a.couleur.rouge);
    printf (" - vert            : %.3lf\n", a.couleur.vert);
    printf (" - bleu            : %.3lf\n", a.couleur.bleu);
}
void printf_Figure2D (Figure2D f)
{
    switch (f.type)
    {
        case 1 : printf_Point2D         (f.point);      break;
        case 2 : printf_Segment2D       (f.segment);    break;
        case 3 : printf_Rectangle2D     (f.rectangle);  break;
        case 4 : printf_Cercle2D        (f.cercle);     break;
        case 5 : printf_ArcDeCercle2D   (f.arcDeCercle);break;
    }
}
