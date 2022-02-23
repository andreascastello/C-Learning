#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


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

int cookie (int X, int Y)
{
    if (tab [X][Y].valeur == 9)return 1;
    else if (tab [X][Y].valeur > 0 && tab[X][Y].valeur < 9)return 0;
    else if (tab [X][Y].valeur == 0)
    {

                if (tab [X+1][Y].valeur > 0 && tab[X+1][Y].valeur < 9 && tab[X+1][Y].cache == 1)
                {
                    tab [X+1][Y].cache = 0;
                }
                if (tab[X+1][Y].valeur == 0 && tab [X+1][Y].cache == 1)
                {
                    tab [X+1][Y].cache = 0;
                    cookie (X+1, Y);
                }

                if (tab [X-1][Y].valeur > 0 && tab[X-1][Y].valeur < 9 && tab[X-1][Y].cache == 1)
                {
                    tab [X-1][Y].cache = 0;
                }
                if (tab [X-1][Y].valeur == 0 && tab [X-1][Y].cache == 1)
                {
                    tab [X-1][Y].cache = 0;
                    cookie (X-1, Y);
                }

            if(Y > 0)
            {
                if (tab [X][Y-1].valeur > 0 && tab[X][Y-1].valeur < 9 && tab[X][Y-1].cache == 1)
                {
                    tab [X][Y-1].cache = 0;
                }
                if (tab [X][Y-1].valeur == 0 && tab [X][Y-1].cache == 1)
                {
                    tab [X][Y-1].cache = 0;
                    cookie (X, Y-1);
                }

                if (tab [X-1][Y-1].valeur > 0 && tab[X-1][Y-1].valeur < 9 && tab[X-1][Y-1].cache == 1)
                {
                    tab [X-1][Y-1].cache = 0;
                }
                if (tab [X-1][Y-1].valeur == 0 && tab [X-1][Y-1].cache == 1)
                {
                    tab [X-1][Y-1].cache = 0;
                    cookie (X-1, Y-1);
                }

                if (tab [X+1][Y-1].valeur > 0 && tab[X+1][Y-1].valeur < 9 && tab[X+1][Y-1].cache == 1)
                {
                    tab [X+1][Y-1].cache = 0;
                }
                if (tab [X+1][Y-1].valeur == 0 && tab [X+1][Y-1].cache == 1)
                {
                    tab [X+1][Y-1].cache = 0;
                    cookie (X+1, Y-1);
                }
            }

            if(Y + 1 < L)
            {
                if (tab [X][Y+1].valeur > 0 && tab[X][Y+1].valeur < 9 && tab[X][Y+1].cache == 1)
                {
                    tab [X][Y+1].cache = 0;
                }
                if (tab [X][Y+1].valeur == 0 && tab [X][Y+1].cache == 1)
                {
                    tab [X][Y+1].cache = 0;
                    cookie (X, Y+1);
                }

                if (tab [X+1][Y+1].valeur > 0 && tab[X+1][Y+1].valeur < 9 && tab[X+1][Y+1].cache == 1)
                {
                    tab [X+1][Y+1].cache = 0;
                }
                if (tab [X+1][Y+1].valeur == 0 && tab [X+1][Y+1].cache == 1)
                {
                    tab [X+1][Y+1].cache = 0;
                    cookie (X+1, Y+1);
                }

                if (tab [X-1][Y+1].valeur > 0 && tab[X-1][Y+1].valeur < 9 && tab[X-1][Y+1].cache == 1)
                {
                    tab [X-1][Y+1].cache = 0;
                }
                if (tab [X-1][Y+1].valeur == 0 && tab [X-1][Y+1].cache == 1)
                {
                    tab [X-1][Y+1].cache = 0;
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
    int nbCoup = 0;
    int fin = 0;
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
do
{
    printf  ("X : ");
    scanf   ("%d", &x);

    printf  ("Y : ");
    scanf   ("%d", &y);

    if (x > C || y > L || tab [x][y].cache == 0)
    printf ("Veuillez verifier vos coordonnee !\nPS : On ne peut decouvrir une case deja decouverte \n");
}
while (x > C || y > L || tab [x][y].cache == 0);

    switch (cookie (x, y))
    {
        case 0 : tab [x][y].cache = 0;break;
        case 1 : fin = 1;break;
    }
        nbCoup ++;
        if (nbCoup == C * L - rBombe)
        {
            fin = 2;
            if (fin == 2)
            {
                printf ("Bravo !!!");
                return 0;
            }
        }
}
while (fin == 0);
    printf ("Dommage tu es tombe sur une bombe \n");
    return 0;
}
