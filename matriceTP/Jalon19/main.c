#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
                                    mat->tab2D [l][c] = rand()%11;
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

Matrice* multiplierMatrice (Matrice* mat, Matrice* mat1, char* nom)
{
    double temp;
    double mat3 = 0;
    if(getDimY (mat) == getDimX (mat1))
    {
        Matrice* mat2 = creeMatrice (nom, getDimY(mat), getDimX(mat1), 0);
        for (int k = 0; k < getDimX(mat1); k++)
        {
            for (int i = 0; i < getDimY(mat); i++)
            {
                for (int j = 0; j < getDimX(mat); j++)
                {
                    temp = mat->tab2D[i][j] * mat1->tab2D[j][k];
                    mat3 += temp;
                }
                mat2->tab2D[k][i] = mat3;
                mat3 = 0;
            }
        }
            setNom(mat, nom);
            return mat2;
    }
    else
    {
        printf ("Multiplication impossible");
    }
}

Matrice* sousMatrice2 ( Matrice* mat, int l, int c)
{
    Matrice* mat2 = creeMatrice ("sousmatrice", getDimY(mat)-1, getDimX(mat)-1, 0);
    int dimX =0;
    int dimY =0;
    double test;
    for (int i =0; i < getDimY(mat); i++)
    {
        for (int j =0; j < getDimX(mat); j++)
        {
            if (j == l || i == c){}
            else
            {
                mat2->tab2D[dimY][dimX] = mat->tab2D[i][j];
                dimX++;
            }
        }
        if (i == c){}
        else
        {
            dimY++;
        }
        dimX = 0;
    }
    return mat2;
}

double calculerDeterminantMatrice (Matrice* mat)
{
    double temp;
    double res=0;
    if (getDimX(mat) == getDimY(mat))
    {
        if (getDimX(mat) == 1)
        {
            return mat->tab2D[0][0];
        }
        if (getDimX (mat)==2)
        {
            res = (mat->tab2D[0][0])*(mat->tab2D[1][1])-(mat->tab2D[1][0])*(mat->tab2D[0][1]);
            return res;
        }
        else
        {
            for (int i=0; i<getDimX(mat); i++)
            {
                temp = mat->tab2D[0][i] * calculerDeterminantMatrice(sousMatrice2 (mat, i, 0));
                if (i%2 == 0)
                {
                    res += temp;
                }
                else
                {
                    res -= temp;
                }
            }
        return res;
        }
    }
    else
    {
        printf ("\nLa matrice n est pas carre !!");
    }
}

Matrice* coMatrice (Matrice* mat1)
{
    Matrice* mat2 = creeMatrice ("coMatrice", getDimY(mat1), getDimX(mat1), 0);

    for (int i =0; i < getDimY(mat2); i++)
    {
        for (int j =0; j < getDimX(mat2); j++)
        {
            mat2->tab2D[j][i] = pow (-1, i+j) * calculerDeterminantMatrice (sousMatrice2 (mat1, i, j));
        }
    }
    return mat2;
}

Matrice* inverserMatrice (Matrice* mat1, char* nom)
{
    if (getDimX (mat1) == getDimY (mat1) && calculerDeterminantMatrice (mat1)!=0)
    {
        Matrice* mat2 = transposerMatrice (coMatrice (mat1), nom);
        double d = calculerDeterminantMatrice (mat1);


        for (int i =0; i < getDimY(mat2); i++)
        {
            for (int j =0; j < getDimX(mat2); j++)
            {
                mat2->tab2D[i][j] = mat2->tab2D[i][j] * (1/d);
            }
        }
        return mat2;
    }
    else
    {
        printf ("\nIversion impossible");
    }
}

Matrice* diviserMatrice (Matrice* mat, Matrice* mat1, char* nom)
{
    double temp;
    double mat3 = 0;
    if (getDimY (mat1) == getDimX (mat1))
    {


        if(getDimY (mat) == getDimX (mat1))
        {
            mat1 = inverserMatrice (mat1, "oui");
            Matrice* mat2 = creeMatrice (nom, getDimY(mat), getDimX(mat1), 0);
            for (int k = 0; k < getDimY(mat); k++)
            {
                for (int i = 0; i < getDimY(mat1); i++)
                {
                    for (int j = 0; j < getDimX(mat1); j++)
                    {
                        mat2->tab2D[i][k] += mat->tab2D[i][j] * mat1->tab2D[k][j];
                    }
                }
            }
            return mat2;
        }
    }
    else
    {
        printf ("division impossible");
    }
}

void ecrireDansFichierMatrice (Matrice* mat, FILE* fichier)
{
    fputc ('[', fichier);
    fprintf(fichier, "\n%s\n", mat->nom);
    fprintf(fichier, "%d\n", mat->nbLignes);
    fprintf(fichier, "%d\n", mat->nbColonnes);

    for (int i =0; i < getDimY(mat); i++)
    {
        for (int j =0; j < getDimX(mat); j++)
        {
            fprintf (fichier, "%lf ", mat->tab2D[i][j]);
        }
        fprintf (fichier, "\n");
    }
    fputc (']', fichier);

}
int main()
{
    srand (time (NULL));

    Matrice* mat = creeMatrice ("Cookie", 2,2,2);
    afficherMatrice (mat, 0);

/*  printf ("%d", getElement (mat, 2, 2, NULL));*/

    //setElement (mat, 0, 0, 8);
    //afficherMatrice (mat, 0);
/*
    afficherMatrice (mat, 0);
*/

    Matrice* mat1 = creeMatrice ("Cookie2", 2,2,2);
    afficherMatrice (mat1, 0);

/*
    Matrice* mat1 = transposerMatrice(mat, "CookieV2");
    afficherMatrice (mat1, 0);
*/

/*
    Matrice* mat2 = additionnerMatrice (mat, mat1, "Cookie + Cookie2");
    afficherMatrice (mat2, 0);
*/
/*
    Matrice* mat2 = soustraireMatrice (mat, mat1, "Cookie - Cookie2");
    afficherMatrice (mat2, 0);
*/
/*
    multiplierMatriceParUnReel (mat, 8,"Multiplication par nbReel");
    afficherMatrice (mat, 0);
*/
/*
    Matrice* mat2 = multiplierMatrice (mat1, mat, "Cookie * Cookie2");
    afficherMatrice (mat2, 0);
*/
/*
    printf ("%lf", calculerDeterminantMatrice(mat1));
*/
/*
    Matrice* mat2 = inverserMatrice (mat1, "Inverse cookie");
    afficherMatrice (mat2, 5);
*/
/*
    Matrice* mat2 = diviserMatrice (mat, mat1, "Cookie / Cookie2");
    afficherMatrice (mat2, 2);
*/

    FILE* fichier1 = fopen ("Matrice.txt", "wb");
    ecrireDansFichierMatrice (mat, fichier1);
    return 0;
}
