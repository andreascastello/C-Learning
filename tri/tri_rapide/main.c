#include <stdio.h>
#include <stdlib.h>

void permuter(int tab[], int a, int b)
{
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

void tri_rapide(int tab[], int debut, int fin)
{
    int pivot, i, j;
    if(debut < fin)
    {
        pivot = debut;
        i = debut;
        j = fin;
        while (i < j)//tant que le debut < a la fin alors on effectue l’opération de partition
        {
            while(tab[i] <= tab[pivot] && i < fin)
            {
                i++;
            }
            while(tab[j] > tab[pivot])
            {
                j--;
            }
            if(i < j)
            {
                permuter (tab, i, j);
            }
        }
        permuter (tab, pivot, j);
        tri_rapide(tab, debut, j - 1);//recursivite
        tri_rapide(tab, j + 1, fin);
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


    tri_rapide (cookie, 0, 5-1);
    printf ("\n");

    printf ("Tableau apres le tri : ");
    for (int c = 0; c < 5; c++)
    {
        printf ("%d ", cookie [c]);
    }
    return 0;
}
