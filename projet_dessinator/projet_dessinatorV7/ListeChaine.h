#ifndef LISTECHAINE_H_INCLUDED
#define LISTECHAINE_H_INCLUDED
#include "types.h"
typedef struct strNoeud Noeud;

struct strNoeud
{
    Figure2D* contenu;
    Noeud* suivant;
    Noeud* precedent;
};

typedef struct
{
    Noeud* premier;
    Noeud* dernier;
    unsigned int taille;
    char nom[50];
}
listeChainee;


#endif // LISTECHAINE_H_INCLUDED
