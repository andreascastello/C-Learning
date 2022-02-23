#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab [5] = { 2, 9, 5, 15, 1};
    ////////////////////////////////////////////////Affichage du tableau avant le tri////////////////////////////////////////////////
    printf ("Tableau avant le tri : ");
    for (int c = 0; c < 5; c++)
    {
        printf ("%d ", tab [c]);
    }
    //////////////////////////////////////////////////////////////Tri////////////////////////////////////////////////////////////////
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tab[j] > tab[i])
            {
                int temp = tab[j];
                tab[j] = tab[i];
                tab[i] = temp;
            }
        }
    }
    printf ("\n\n");
    ////////////////////////////////////////////////Affichage du tableau apres le tri////////////////////////////////////////////////
    printf ("Tableau apres le tri : ");
    for (int c = 0; c < 5; c++)
    {
        printf ("%d ", tab [c]);
    }
    return 0;
}
