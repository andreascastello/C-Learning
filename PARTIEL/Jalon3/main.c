#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int valeur;
    int cache;
}
Position;

int main()
{
    srand (time(NULL));
    int colonne;
    int ligne;
    int nBombe;
    int c;
    int l;
    int temp;
//                                                                      ECRITURE DU DEBUT
    printf  ("Choisir les dimensions du tableau : \n");

    printf  ("Colonne : ");
    scanf   ("%d", &colonne);

    printf  ("Ligne : ");
    scanf   ("%d", &ligne);


    printf  ("Choisir le nombre de bombe souhaitees : ");
    scanf   ("%d", &nBombe);
//                                                                      INCREMENTATION TAB
    Position tab [colonne][ligne];
    temp = nBombe;
do
{
    nBombe = temp;
    for (c = 0; c < colonne; c++)
    {
        for (l = 0; l < ligne; l++)
        {
            tab[c][l] = (Position) {0,1};
            if (nBombe == rand()%44 && nBombe > 0)
            {
                tab [c][l].valeur = 9;
                nBombe --;
            }
            else
            {
                tab [c][l].valeur = 0;
            }
        }
    }
}
    while (nBombe != 0);
//                                                                      ECRITURE DES NOMBRES
    for (c = 0; c < colonne; c++)
    {
        for (l = 0; l < ligne; l++)
        {
            if (tab [c][l].valeur >= 9)
            {
                tab [c+1][l].valeur    ++;
                tab [c-1][l].valeur    ++;

                if (l > 0)
                {
                    tab [c][l-1].valeur    ++;
                    tab [c-1][l-1].valeur  ++;
                    tab [c+1][l-1].valeur  ++;
                }

                if (l+1 < ligne)
                {
                    tab [c][l+1].valeur    ++;
                    tab [c+1][l+1].valeur  ++;
                    tab [c-1][l+1].valeur  ++;
                }
            }
        }
    }


//                                                                      ECRITURE TAB
    for (c = 0; c < colonne; c++)
    {
        for (l = 0; l < ligne; l++)
        {
            if (tab [c][l].valeur > 9)
            {
                tab [c][l].valeur = 9;
            }
            printf ("%d", tab [c][l].valeur);
        }
        printf ("\n");
    }
    return 0;
}
