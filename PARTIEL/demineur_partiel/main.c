#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand (time(NULL));
    int colonne;
    int ligne;
    int nBombe;
    int c;
    int l;
    int temp;

    printf  ("Choisir les dimensions du tableau : \n");

    printf  ("Colonne : ");
    scanf   ("%d", &colonne);

    printf  ("Ligne : ");
    scanf   ("%d", &ligne);


    printf  ("Choisir le nombre de bombe souhaitees : ");
    scanf   ("%d", &nBombe);

    int tab [colonne][ligne];
    temp = nBombe;
do
{
    nBombe = temp;
    for (c = 0; c < colonne; c++)
    {
        for (l = 0; l < ligne; l++)
        {
            if (nBombe == rand()%20 && nBombe > 0)
            {
                tab [c][l] = 9;
                nBombe --;
            }
            else
            {
                tab [c][l] = 0;
            }
        }
    }
}
    while (nBombe != 0);
    for (c = 0; c < colonne; c++)
    {
        for (l = 0; l < ligne; l++)
        {
            printf ("%d", tab [c][l]);
        }
        printf ("\n");
    }

    return 0;
}
