#define TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#ifndef __TOTO__
#define __TOTO__
#define ROUGE   1.0f,0.0f,0.0f
#define VERT    0.0f,1.0f,0.0f
#define BLEU    0.0f,0.0f,1.0f
#define MAGENTA 1.0f,0.0f,1.0f
#define CYAN    0.0f,1.0f,1.0f
#define JAUNE   1.0f,1.0f,0.0f
#define BLANC   1.0f,1.0f,1.0f
#define GRIS    0.5f,0.5f,0.5f
#define NOIR    0.0f,0.0f,0.0f

typedef struct
{
    double rouge;
    double vert;
    double bleu;
}
Couleur;

typedef struct str_Point2D
{
    double x;
    double y;
    Couleur couleur;
}
Point2D;

typedef struct str_Segment2D
{
    double departX;
    double departY;
    double arriveeX;
    double arriveeY;
    Couleur couleur;
}
Segment2D;

typedef struct str_Rectangle2D
{
    double AX;
    double AY;
    double BX;
    double BY;
    float dimension;
    Couleur couleur;
}
Rectangle2D;

typedef struct str_Cercle2D
{
    double centreX;
    double centreY;
    double rayon;
    Couleur couleur;
}
Cercle2D;

typedef struct str_ArcDeCercle2D
{
    double centreX;
    double centreY;
    double rayon;
    double debut;
    double fin;
    Couleur couleur;
}
ArcDeCercle2D;
#endif // TYPES_H_INCLUDED
