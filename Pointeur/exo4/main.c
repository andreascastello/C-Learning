#include <stdio.h>
#include <stdlib.h>

void cookie (int* tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        *tab=0;
        tab++;
    }
}

void trier (int* tab, int taille)
{
    int temp;
    int permutation = 0;

    do
    {
        permutation = 0;

        for (int i = 0;  i<taille-1; i++)
        {
            if (*(tab+i) < *(tab+i+1))
            {
                temp        = *(tab+i);
                *(tab+i)    = *(tab+i+1);
                *(tab+i+1)  = temp;

                permutation = 1;
            }
        }
    }
            while(permutation);
}

void afficher (int* tab, int taille)
{
    printf ("Tableau = { ");

    for (int i = 0; i<taille; i++)
    {
        printf ("%2d ", *(tab+i));

    printf ("}\n");
    }
}

int main()
{
    int tab[10];

    cookie (tab, 10);
    printf ("Après initialiser : "); afficher (tab, 10);

    tab[0] = 10;
    tab[1] = 1;
    tab[2] = 5;
    tab[3] = 7;
    tab[4] = 3;
    tab[5] = 3;
    tab[6] = 5;
    tab[7] = 6;
    tab[8] = 8;
    tab[9] = 9;

    printf ("Après initialisation : "); afficher (tab, 10);

    trier (tab, 10);
    printf ("Après tri  :"); afficher (tab, 10);

    cookie (tab, 10);
    printf ("apres initialisation :"); afficher (tab, 10);
    return 0;
}
