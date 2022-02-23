#include <stdio.h>
#include <stdlib.h>

int CalculerMoyenne (int m [])
{
    float somme = 0;
    for (int i = 0; i < 4; i++)
    {
        somme += m[i];
    }
    float moy = somme / 4;
    printf ("%.2f", moy);
    return moy;
}

int CalculerVariance (int v[])
{
    for (int j = 0; j <=4; j++)
    {

    }
}

int main()
{
    int tab [] = {8, 13, 2, 7};
    CalculerMoyenne (tab);
}
