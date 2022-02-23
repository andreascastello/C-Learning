#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab [10] = {0,0,0,0,0,0,0,0,0,0};
     int i;

    for (i = 0; i < 10; i++)
    {
        printf ("choisir le numero %d : ", i);
        scanf ("%d", &(tab[i]) );
    }
    for (i = 9;i > 0; i--)
        tab[i] = tab[i-1];
}
