#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef int bool;

#define VRAI 1
#define FAUX 0
//----------------------------------------------------------------------STRUCTURE-------------------------------------------------------------------------//
typedef struct
{
    int x;
    int y;
}
Coordonnee;

typedef struct
{
    int valeur;
    int cache;
}
Position;
//----------------------------------------------------------------------MAIN,VARIABLE...------------------------------------------------------------------//
int main()
{
    if (!SetConsoleOutputCP(65001))
    printf ("ERREUR\n");

    srand (time(NULL));
    int colonne;
    int ligne;
    int nBombe;
    int c;
    int l;
    int temp;
    int rBombe;
    Coordonnee decouvrir;
    int nbCoup = 0;
    bool victoire = FAUX;
//----------------------------------------------------------------------ECRITURE DU DEBUT-----------------------------------------------------------------//
    printf  ("Choisir les dimensions du tableau : \n");

    printf  ("Colonne : ");
    scanf   ("%d", &colonne);

    printf  ("Ligne : ");
    scanf   ("%d", &ligne);


    printf  ("Choisir le nombre de bombe souhaitees : ");
    scanf   ("%d", &nBombe);
    rBombe = nBombe;
//----------------------------------------------------------------------INITIALISATION TAB----------------------------------------------------------------//
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
//----------------------------------------------------------------------ECRITURE DES NOMBRES--------------------------------------------------------------//
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


//----------------------------------------------------------------------ECRITURE TAB----------------------------------------------------------------------//
do
{
    for (c = 0; c < colonne; c++)
    {
        for (l = 0; l < ligne; l++)
        {
            if (tab [c][l].valeur > 9)
            {
                tab [c][l].valeur = 9;
            }
            printf ("%d ", tab [c][l].valeur);
        }
        printf ("\n");
    }
//----------------------------------------------------------------------CONDITIONS------------------------------------------------------------------------//
    printf ("Veuillez choisir les coordonees de la case a decouvrir : \n");
do
{
    printf  ("X : ");
    scanf   ("%d", &decouvrir.x);

    printf  ("Y : ");
    scanf   ("%d", &decouvrir.y);

    if (decouvrir.x > colonne || decouvrir.y > ligne || tab [decouvrir.x][decouvrir.y].cache == 0)
    printf ("Veuillez verifier vos coordonnee !\nPS : On ne peut decouvrir une case deja decouverte \n");
}
while (decouvrir.x > colonne || decouvrir.y > ligne || tab [decouvrir.x][decouvrir.y].cache == 0);

        nbCoup ++;

        if (tab [decouvrir.x][decouvrir.y].valeur == 9)
        {
            printf ("Dommage tu es tombe sur une bombe :( \n");
            return 0;
        }
        else
        {
            tab [decouvrir.x][decouvrir.y].cache = 0;
        }

        if (nbCoup == colonne * ligne - rBombe)
            victoire = 1;

}
while (victoire == 0);
    printf ("Bravo tu as gagner !");

    return 0;
}
