#define TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#ifndef __TOTO__
#define __TOTO__

typedef struct
{
    double rouge;
    double vert;
    double bleu;
}
Couleur;

typedef struct str_Point2D
{
    unsigned int type;
    Couleur couleur;
    double x;
    double y;
}
Point2D;

typedef struct str_Segment2D
{
    unsigned int type;
    Couleur couleur;
    double departX;
    double departY;
    double arriveeX;
    double arriveeY;
}
Segment2D;

typedef struct str_Rectangle2D
{
    unsigned int type;
    Couleur couleur;
    double AX;
    double AY;
    double BX;
    double BY;
    float dimension;
}
Rectangle2D;

typedef struct str_Cercle2D
{
    unsigned int type;
    Couleur couleur;
    double centreX;
    double centreY;
    double rayon;
}
Cercle2D;

typedef struct str_ArcDeCercle2D
{
    unsigned int type;
    Couleur couleur;
    double centreX;
    double centreY;
    double rayon;
    double debut;
    double fin;
}
ArcDeCercle2D;

typedef union
{
    unsigned int type;
    Point2D point;
    Segment2D segment;
    Rectangle2D rectangle;
    Cercle2D cercle;
    ArcDeCercle2D arcDeCercle;
}
Figure2D;
#define ROUGE   1.0f,0.0f,0.0f
#define VERT    0.0f,1.0f,0.0f
#define BLEU    0.0f,0.0f,1.0f
#define MAGENTA 1.0f,0.0f,1.0f
#define CYAN    0.0f,1.0f,1.0f
#define JAUNE   1.0f,1.0f,0.0f
#define BLANC   1.0f,1.0f,1.0f
#define GRIS    0.5f,0.5f,0.5f
#define NOIR    0.0f,0.0f,0.0f

#define FIGURE 0
#define POINT 1
#define SEGMENT 2
#define RECTANGLE 3
#define CERCLE 4
#define ARC_DE_CERCLE 5

#endif // TYPES_H_INCLUDED
