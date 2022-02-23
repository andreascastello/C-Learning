#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <time.h>

#define C 8
#define L 8

//----------------------------------------------------------------------STRUCTURE ET FONCTION-------------------------------------------------------------//
typedef struct
{
    int valeur;
    int cache;
}
Position;

Position tab [C][L];
unsigned int victoire = C*L;
int cookie (int X, int Y)
{
    if (tab [X][Y].valeur == 9)return 1;
    else if (tab [X][Y].valeur > 0 && tab[X][Y].valeur < 9){victoire--;return 0;}
    else if (tab [X][Y].valeur == 0)
    {

                if (tab [X+1][Y].valeur > 0 && tab[X+1][Y].valeur < 9 && tab[X+1][Y].cache == 1)
                {
                    tab [X+1][Y].cache = 0;
                    victoire--;
                }
                if (tab[X+1][Y].valeur == 0 && tab [X+1][Y].cache == 1)
                {
                    tab [X+1][Y].cache = 0;
                    victoire --;
                    cookie (X+1, Y);
                }

                if (tab [X-1][Y].valeur > 0 && tab[X-1][Y].valeur < 9 && tab[X-1][Y].cache == 1)
                {
                    tab [X-1][Y].cache = 0;
                    victoire--;
                }
                if (tab [X-1][Y].valeur == 0 && tab [X-1][Y].cache == 1)
                {
                    tab [X-1][Y].cache = 0;
                    victoire --;
                    cookie (X-1, Y);
                }

            if(Y > 0)
            {
                if (tab [X][Y-1].valeur > 0 && tab[X][Y-1].valeur < 9 && tab[X][Y-1].cache == 1)
                {
                    tab [X][Y-1].cache = 0;
                    victoire--;
                }
                if (tab [X][Y-1].valeur == 0 && tab [X][Y-1].cache == 1)
                {
                    tab [X][Y-1].cache = 0;
                    victoire --;
                    cookie (X, Y-1);
                }

                if (tab [X-1][Y-1].valeur > 0 && tab[X-1][Y-1].valeur < 9 && tab[X-1][Y-1].cache == 1)
                {
                    tab [X-1][Y-1].cache = 0;
                    victoire--;
                }
                if (tab [X-1][Y-1].valeur == 0 && tab [X-1][Y-1].cache == 1)
                {
                    tab [X-1][Y-1].cache = 0;
                    victoire --;
                    cookie (X-1, Y-1);
                }

                if (tab [X+1][Y-1].valeur > 0 && tab[X+1][Y-1].valeur < 9 && tab[X+1][Y-1].cache == 1)
                {
                    tab [X+1][Y-1].cache = 0;
                    victoire--;
                }
                if (tab [X+1][Y-1].valeur == 0 && tab [X+1][Y-1].cache == 1)
                {
                    tab [X+1][Y-1].cache = 0;
                    victoire --;
                    cookie (X+1, Y-1);
                }
            }

            if(Y + 1 < L)
            {
                if (tab [X][Y+1].valeur > 0 && tab[X][Y+1].valeur < 9 && tab[X][Y+1].cache == 1)
                {
                    tab [X][Y+1].cache = 0;
                    victoire--;
                }
                if (tab [X][Y+1].valeur == 0 && tab [X][Y+1].cache == 1)
                {
                    tab [X][Y+1].cache = 0;
                    victoire --;
                    cookie (X, Y+1);
                }

                if (tab [X+1][Y+1].valeur > 0 && tab[X+1][Y+1].valeur < 9 && tab[X+1][Y+1].cache == 1)
                {
                    tab [X+1][Y+1].cache = 0;
                    victoire--;
                }
                if (tab [X+1][Y+1].valeur == 0 && tab [X+1][Y+1].cache == 1)
                {
                    tab [X+1][Y+1].cache = 0;
                    victoire --;
                    cookie (X+1, Y+1);
                }

                if (tab [X-1][Y+1].valeur > 0 && tab[X-1][Y+1].valeur < 9 && tab[X-1][Y+1].cache == 1)
                {
                    tab [X-1][Y+1].cache = 0;
                    victoire--;
                }
                if (tab [X-1][Y+1].valeur == 0 && tab [X-1][Y+1].cache == 1)
                {
                    tab [X-1][Y+1].cache = 0;
                    victoire --;
                    cookie (X-1, Y+1);
                }
            }
        return 0;
    }
    return 20;
}

//----------------------------------------------------------------------MAIN,VARIABLE...------------------------------------------------------------------//
int main()
{
    if (!SetConsoleOutputCP(65001))
    printf ("ERREUR\n");

    srand (time(NULL));
    int x;
    int y;
    int nBombe;
    int c;
    int l;
    int temp;
    int rBombe;
    int fin = 0;
    int tDebut = time(NULL);

//----------------------------------------------------------------------ECRITURE DU DEBUT-----------------------------------------------------------------//
    printf  ("Choisir le nombre de bombe souhaitees : ");
    scanf   ("%d", &nBombe);
    rBombe = nBombe;

//----------------------------------------------------------------------INITIALISATION TAB----------------------------------------------------------------//

    temp = nBombe;
do
{
    nBombe = temp;
    for (c = 0; c < C; c++)
    {
        for (l = 0; l < L; l++)
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
    for (c = 0; c < C; c++)
    {
        for (l = 0; l < L; l++)
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

                if (l+1 < L)
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
    for (c = 0; c < C; c++)
    {
        for (l = 0; l < L; l++)
        {
            if (tab [c][l].valeur > 9)
            {
                tab [c][l].valeur = 9;
            }
            if (tab [c][l].cache == 1)
            {
                printf ("[ ]");
            }
            else
            printf ("[%d]", tab [c][l].valeur);
        }
        printf ("\n");
    }

//----------------------------------------------------------------------CONDITIONS------------------------------------------------------------------------//
    printf ("Veuillez choisir les coordonees de la case a decouvrir : \n");
    int tFin;
    int temps;
    int record [5];
do
{
    printf  ("X : ");
    scanf   ("%d", &x);

    printf  ("Y : ");
    scanf   ("%d", &y);

    if (x > C || y > L || tab [x][y].cache == 0)
    {
        printf ("Veuillez verifier vos coordonnee !\nPS : On ne peut decouvrir une case deja decouverte \n");
    }

    tFin = time(NULL);
    temps = tFin - tDebut;

    record [0] = 30;
    record [1] = 10;
    record [2] = 90;
    record [3] = 60;
    record [4] = temps;

}
while (x > C || y > L || tab [x][y].cache == 0);

    switch (cookie (x, y))
    {
        case 0 : tab [x][y].cache = 0;break;
        case 1 : fin = 1;break;
    }

//----------------------------------------------------------------------CONDITIONS DE VICTOIRE------------------------------------------------------------//
    if (victoire == rBombe)
    {
        printf ("Bravo, tu as gagner en %d secondes\n", temps);
        printf ("Affichage du tableau des scores : ");

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (record[j] > record[i])
                {
                    int temp = record[j];
                    record[j] = record[i];
                    record[i] = temp;
                }
            }
        }

        for (c = 0; c < 5; c++)
        {
            printf ("%d, ", record [c]);
        }

        if (temps == record[0])
        {
            printf ("\nC'est un nouveau record !!!");
        }
        else if (temps != record[0])
        {
            printf ("\nDommage tu aurais pu mieux faire...");
        }
        printf ("\n");
        return 667;
    }
}
while (fin == 0);
    printf ("Dommage tu es tombe sur une bombe \n");

    return 0;
}
