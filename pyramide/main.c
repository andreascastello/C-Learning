#include <stdio.h>
#include <stdlib.h>

int dessinerTriangle (int h, char symb)
{
    for (int nbLigne=1; nbLigne <= h; nbLigne++)
    {
        int nbEspace = (h - nbLigne);
        int nbEtoile = (nbLigne * 2) - 1;

        for (int i = 1; i<=nbEspace; i++)
        {
            printf(" ");
        }
        for (int i = 1; i<=nbEtoile; i++)
        {
            printf("%c", symb);
        }
        printf("\n");
    }
}

int main()
{
    dessinerTriangle(5, '*');
    printf("\n");
    dessinerTriangle(10, 'Φ');
}
