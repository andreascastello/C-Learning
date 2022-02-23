#include <stdio.h>
#include <stdlib.h>

void tri_selection(int tab[], int taille)
{
    int i, j;
    for (i = 0; i < taille; i++)
    {
        int cookie = i;

        for (j = i; j < taille; j++)
        {
            if (tab[cookie] > tab[j])
            {
                cookie = j;
            }
        }
        if (cookie != i) // echange entre tab [i] et tab [cookie] (cookie == min)
        {
          int temp = tab[i];
          tab[i] = tab[cookie];
          tab[cookie] = temp;
        }
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

    tri_selection (cookie, 5);
    printf ("\n");

    printf ("Tableau apres le tri : ");
    for (int c = 0; c < 5; c++)
    {
        printf ("%d ", cookie [c]);
    }
    return 0;
}
