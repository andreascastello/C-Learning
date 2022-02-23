#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct
{
    int x;
    int y;
}
Coordonnees;

typedef struct
{
    Coordonnees porte;
    Coordonnees clee;
    int laby;
    int iDpassage;
    int verrouille;
}
Passage;
#endif // STRUCTURE_H_INCLUDED
