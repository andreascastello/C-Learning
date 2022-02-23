#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main()
{
    if (!SetConsoleOutputCP(65001))  printf ("ERREUR\n");
    srand(time(NULL));

    int hauteur,largeur,bouge,i,j;
    int PY = 3;
    int PX = 5;
        printf("Choisir une hauteur : ");
        scanf("%d", &hauteur);

        printf("\n Choisir une largeur : ");
        scanf("%d", &largeur);
    if (hauteur <= 2 || largeur <= 2)
    {
        printf ("IMPOSSIBLE de choisir 2");
        return 0;
    }
    int RL = rand()%largeur +1;
    int RH = rand()%hauteur +1;
    int biscuit1 = rand()%largeur +1;
    int biscuit2 = rand()%hauteur +1;
    while (bouge != 8)
    {
        for (i = 0; i < hauteur; i++)
        {
            for (j = 0; j < largeur; j++)
            {
                if (i == 0 || i == hauteur -1)/*affichage de la premiere ligne*/
                    printf("═");
                else
                {
                    if (i == PY && j == PX)/*affichage du joueur*/
                        printf("0");
                    else
                    {
                        if (j == largeur -1 && i == 1)/*affichage de la sortie*/
                            printf("S");
                        else
                        {
                            if(RL == j && RH == i) /*affichage des biscuits*/
                                printf (".");
                            else
                            {
                                if (j == 0 || j == largeur -1)/*affichage des bordures*/
                                    printf("║");
                                else
                                    printf(" ");
                            }
                        }
                    }
                }
            }
            printf("\n");
        }
        printf ("Bouger le personnage afin d'atteindre la la sortie S : \n");
        printf ("HAUT   : 5 \n");
        printf ("BAS    : 2 \n");
        printf ("GAUCHE : 1 \n");
        printf ("DROITE : 3 \n");
        scanf  ("%d", &bouge);

        switch (bouge)
        {
            case 1 : PX--;
                if (PX == 0)
                    PX++;break;

            case 2 : PY++;
                if (PY == hauteur -1)
                    PY--;break;

            case 3 : PX++;
                    if (PX == largeur -1 && PY == 1)
                    {
                        printf ("VICTOIRE !\n");return 0;
                    }
                    else
                    {
                        if (PX ==  largeur -1)
                            PX--;
                    }break;

            case 5 : PY--;
                if (PY == 0)
                    PY++;break;

            default : return 0;
        }
    }
    return 0;
}
