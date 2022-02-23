#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    int valeur [10];
    int* index [10];
}
Tableau;

Tableau initialiser()
{
    srand (time(NULL));
    Tableau cookie;
    for (int i = 0; i < 10; i++)
    {
        cookie.valeur[i] = rand()%50+1;
        cookie.index[i] = cookie.valeur[i];
    }
    return cookie;
}

void afficher (Tableau oui)
{
    for (int j = 0; j < 10; j++)
    {
        printf ("%d ",oui.valeur[j]);
    }

    printf ("\n");

        for (int j = 0; j < 10; j++)
    {
        printf ("%d ",oui.index[j]);
    }
}

Tableau trier (Tableau bulle)
{
    int perm = 0;
    int* temp;

    do
    {
            for (int j = 0; j < 9; j++)
            {
                if (*(bulle.index[j]) > *(bulle.index[j+1]))
                {
                    temp = bulle.index[j];
                    bulle.index[j] = bulle.index[j+1];
                    bulle.index[j] = temp;
                    perm = 1;

                    printf ("On permute les adresses %d (%p => %2d)\n", j, bulle.index[j], *(bulle.index[j +1]),
                                                                        j+1, bulle.index[j+1], *(bulle.index[j+1]));
                }
            }
    }
    while (perm);
        return bulle;
}

int main()
{
    srand( time( NULL ) );
    Tableau tab = initialiser();

    trier(tab);
    afficher(tab);

    return 0;
}
