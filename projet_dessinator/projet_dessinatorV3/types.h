#define TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#ifndef __TOTO__
#define __TOTO__
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


#endif // TYPES_H_INCLUDED
