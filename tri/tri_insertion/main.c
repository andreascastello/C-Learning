#include <stdio.h>
#include <stdlib.h>

void tri_insertion(int tab[], int taille)
{
    int i, j;
    for (i = 1; i < taille; ++i)
    {
        int tab2 = tab[i];
        for (j = i; j > 0 && tab[j - 1] > tab2; j--)
        {
            tab[j] = tab[j - 1];
        }
        tab[j] = tab2;
    }
}

int main()
{
    int cookie [5] = { 2, 9, 5, 15, 1};

    printf ("Tableau avant le tri : ");
    for (int c = 0; c < 5; c++)
    {
        printf ("%d ", cookie [c]);
    }

    tri_insertion (cookie, 5);
    printf ("\n");

    printf ("Tableau apres le tri : ");
    for (int c = 0; c < 5; c++)
    {
        printf ("%d ", cookie [c]);
    }
    return 0;
}
