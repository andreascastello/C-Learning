#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int* contenu;
    unsigned long taille;
}
Vecteur;

Vecteur* creerVecteur (int taille)
{
    Vecteur* cookie = (Vecteur*) calloc (1, sizeof (Vecteur));

    if (cookie)
    {
        if (taille == 0)
        {
            cookie->contenu = NULL;
            cookie->taille  = 0;
        }
        else
        {
            cookie->contenu = (int*)calloc(taille, sizeof(int));

            if (cookie->contenu)
            {
            free (cookie);
            cookie = NULL;
            }
        }
    }

    return cookie;
}

int main()
{
    int taille = 5;
    Vecteur* p = creerVecteur (taille);

    if (p)
    for (int i = 0; i<taille; i++)
    {
        printf ("%d ", p[i]->contenu);
    }
    else
        printf ("non.");
    return 0;
}
