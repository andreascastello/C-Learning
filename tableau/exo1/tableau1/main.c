#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    int tab [10];
    int max;
    int min;
    int i;

    for (i = 0; i < 10; i++)
    {
        printf ("choisir le numero %d : ", i);
        scanf ("%d", &(tab[i]) );
        if (max < tab[i])
        max=tab[i];

        if (min > tab[i])
        min=tab[i];
    }

            printf("la valeur max est : %d\n", max);
            printf("la valeur min est : %d\n", min);
}
