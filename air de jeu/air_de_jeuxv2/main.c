#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
if (!SetConsoleOutputCP(65001))  printf ("ERREUR\n");
    srand(time(NULL));

    int fin = 0;
    char tab [4][7] = {     "#######",
                            "#J#   #",
                            "#   # S",
                            "#######"   };
int bouge,y,x,PY,PX;
do
{
    for (y = 0; y <4; y++)
    {
        for (x = 0; x <7; x++)
        {
            if (tab [y][x]=='j')
            {
                PY = y;
                PX = x;
            }
            printf ("%c", tab [y][x]);
        }
        printf ("\n");
    }

    printf ("Bouger le personnage afin d'atteindre la la sortie S : \n");
        printf ("HAUT   : 5 \n");
        printf ("BAS    : 2 \n");
        printf ("GAUCHE : 1 \n");
        printf ("DROITE : 3 \n");
        scanf  ("%d", &bouge);
    switch (bouge)
    {
        case 1 : if (tab[PY][PX -1]!= '#') PX -=1;break;
        case 2 : if (tab[PY +1][PX]!= '#') PY +=1;break;
        case 3 : if (tab[PY][PX +1]!= '#') PX +=1;break;
        case 5 : if (tab[PY -1][PX]!= '#') PY -=1;break;
        case 8 : fin = 1;break;
    default : return 0;
    }

}
    while(fin == 0);
    return 0;
}
