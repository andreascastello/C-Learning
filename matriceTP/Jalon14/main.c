#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int nbLignes;
    int nbColonnes;
    double element;
    char nom[50];
    double** tab2D;
}
Matrice;
#define NULLE 0
#define IDENTITE 1
#define HASARD 2

Matrice* creeMatrice (char* matNom, int matLignes, int matColonnes, unsigned int type)
{


    Matrice* mat = (Matrice*)calloc(1, sizeof(Matrice));
    mat->tab2D = (double**)calloc(matLignes, sizeof(double*));


    for(int l=0; l<matLignes; l++)
    {
        mat->tab2D [l] = (double*)calloc(matColonnes, sizeof (double));
    }
    if (mat)
    {
        switch (type)
        {
        case IDENTITE   :   for (int p = 0; p<matLignes; p++)
                            {
                                mat->tab2D [p][p] = 1;
                            }
                            break;

        case HASARD     :   for (int l = 0; l<matLignes; l++)
                            {
                                for(int c = 0; c<matColonnes; c++)
                                {
                                    mat->tab2D [l][c] = rand()%101;
                                }
                            }
                            break;
        }

        setNom (mat, matNom);
        mat->nbColonnes = matColonnes;
        mat->nbLignes   = matLignes;
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

void afficherMatrice (Matrice* mat, int format)
{
    if (mat)
    {
        if (mat->tab2D)
        {
            printf ("la matrice s appelle : %s\n", mat->nom);

            for (int l = 0; l < mat->nbLignes; l++)
            {
                for (int c = 0; c < mat->nbColonnes; c++)
                {
                    printf ("%.*lf ", format, mat->tab2D [l][c]);
                }
                printf("\n");
            }
        }
        else
        {
            printf ("Le vecteur est vide\n");
        }
    }
}

char* getNom (Matrice* mat)
{
    return (mat->nom);
}


void setNom (Matrice* mat, char* matNom)
{
    int i = 0;
    while (matNom[i])
    {
        mat->nom[i] = matNom[i];
        i++;
    }
}

int getDimX (Matrice* mat)
{
    return (mat->nbColonnes);
}

int getDimY (Matrice* mat)
{
    return (mat->nbLignes);
}

int getElement (Matrice* mat, int x, int y, double* nbRecherche)
{
    if (mat)
    {
        if (mat->tab2D)
        {
            if (getDimX(mat) < x || getDimY(mat) < y )
            {
                return 0;
            }
            else
            {
                nbRecherche = &mat->tab2D[y][x];
                return 1;
            }
        }
    }
}

int setElement (Matrice* mat, int x, int y, double valeur)
{
    if (mat)
    {
        if (mat->tab2D)
        {
            if (getDimX(mat) < x || getDimY(mat) < y )
            {
                return 0;
            }
            else
            {
                mat->tab2D[y][x] = valeur;
                return 1;
            }
        }
    }
}

void setDimX (Matrice* mat, unsigned int x)
{
    unsigned int dimY = getDimY(mat);
    char* name = getNom(mat);
    char name2[50];

    for (int i = 0; i<50; i++)
    {
        name2[i] = name[i];
    }
    free(mat);
    mat = creeMatrice (name2, dimY, x, 0);
}

void setDimY (Matrice* mat, unsigned int y)
{
    unsigned int dimX = getDimX(mat);
    char* name = getNom(mat);
    char name2[50];


    for (int i = 0; i<50; i++)
    {
        name2[i] = name[i];
    }

    free(mat);
    mat = creeMatrice (name2, y, dimX, 0);
}

Matrice* transposerMatrice (Matrice* mat, char* nom)
{
    Matrice* mat1 = creeMatrice ("A'", getDimX(mat), getDimY(mat), 0);
    for (int i = 0; i < getDimY(mat); i++)
    {
        for (int j = 0; j < getDimX(mat); j++)
        {
            mat1->tab2D[j][i] = mat->tab2D[i][j];
        }
    }
    setNom (mat1, nom);
    return mat1;
}

Matrice* additionnerMatrice (Matrice* mat, Matrice* mat1, char* nom)
{
    Matrice* mat2 = creeMatrice ("A ", getDimY(mat), getDimX(mat), 0);
    if(getDimX (mat) == getDimX (mat1) && getDimY (mat) == getDimY (mat1))
    {
        for (int i = 0; i < getDimY(mat); i++)
        {
            for (int j = 0; j < getDimX(mat); j++)
            {
                mat2->tab2D[i][j] = mat->tab2D[i][j] + mat1->tab2D[i][j];
            }
        }
        setNom (mat2, nom);
        return mat2;
    }
    else
    {
        printf ("Addition impossible");
    }
}

Matrice* soustraireMatrice (Matrice* mat, Matrice* mat1, char* nom)
{
    Matrice* mat2 = creeMatrice ("A ", getDimY(mat), getDimX(mat), 0);
    if(getDimX (mat) == getDimX (mat1) && getDimY (mat) == getDimY (mat1))
    {
        for (int i = 0; i < getDimY(mat); i++)
        {
            for (int j = 0; j < getDimX(mat); j++)
            {
                mat2->tab2D[i][j] = mat->tab2D[i][j] - mat1->tab2D[i][j];
            }
        }
        setNom (mat2, nom);
        return mat2;
    }
    else
    {
        printf ("Soustraction impossible");
    }
}

Matrice* multiplierMatriceParUnReel (Matrice* mat, double nbReel, char* nom)
{
    for (int i = 0; i < getDimY(mat); i++)
    {
        for (int j = 0; j < getDimX(mat); j++)
        {
            mat->tab2D[i][j] = mat->tab2D[i][j] * nbReel;
        }
    }
    setNom (mat, nom);
    return mat;
}

int main()
{
    srand (time (NULL));

    Matrice* mat = creeMatrice ("Cookie", 2,3,1);
    //afficherMatrice (mat, 0);

/*  printf ("%d", getElement (mat, 2, 2, NULL));*/

    setElement (mat, 0, 0, 8);
    afficherMatrice (mat, 0);
/*
    setDimX (mat, 8);
    setDimY (mat, 8);
    afficherMatrice (mat, 0);
*/
/*
    Matrice* mat1 = transposerMatrice(mat, "CookieV2");
    afficherMatrice (mat1, 0);
*/
    Matrice* mat1 = creeMatrice ("Cookie2", 2,3,1);
    afficherMatrice (mat1, 0);
/*
    Matrice* mat2 = additionnerMatrice (mat, mat1, "Cookie + Cookie2");
    afficherMatrice (mat2, 0);
*/
/*
    Matrice* mat2 = soustraireMatrice (mat, mat1, "Cookie - Cookie2");
    afficherMatrice (mat2, 0);
*/
    multiplierMatriceParUnReel (mat, 8,"Multiplication par nbReel");
    afficherMatrice (mat, 0);
    return 0;
}
