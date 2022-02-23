#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int nbLignes;
    int nbColonnes;
    double element;
    char nom [50];
    double** tab2D;
}
Matrice;
#define NULLE 0
#define IDENTITE 1
#define HASARD 2

Matrice* creeMatrice (char* nom, int nbLignes, int nbColonnes, unsigned int type)
{
    srand (time (NULL));

    Matrice* mat = (Matrice*)calloc(1, sizeof(Matrice));
    mat->tab2D = (double**)calloc(nbLignes, sizeof(double*));


    for(int l=0; l<nbLignes; l++)
    {
        mat->tab2D [l] = (double*)calloc(nbColonnes, sizeof (double));
    }
    if (mat)
    {
        switch (type)
        {
        case IDENTITE   :   for (int p = 0; p<nbLignes; p++)
                            {
                                mat->tab2D [p][p] = 1;
                            }
                            break;

        case HASARD     :   for (int l = 0; l<nbLignes; l++)
                            {
                                for(int c = 0; c<nbColonnes; c++)
                                {
                                    mat->tab2D [l][c] = rand()%101;
                                }
                            }
                            break;
        }
    }
    return mat;
}

void detruireMatrice (Matrice* mat)
{
    if(mat)
    {
        if (mat->tab2D)
        {
            for (int l = 0; l < mat->nbLignes; l++)
            {
                free (mat->tab2D[l]);
            }
            free (mat->tab2D);
        }
        free (mat);
    }
}
int main()
{
    srand (time (NULL));
    printf("Hello world!\n");
    return 0;
}
