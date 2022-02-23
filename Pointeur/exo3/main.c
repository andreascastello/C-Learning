#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cookie (int* tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        *tab=0;
        tab++;
    }
}

void afficher (int tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf ("%d ", tab[i]);
    }
    printf ("\n");
}
int main()
{
    int tab [5] = {4,6,5,8,7};

    afficher (tab, 5);
    cookie   (tab, 5);
    afficher (tab, 5);
    return 0;
}
