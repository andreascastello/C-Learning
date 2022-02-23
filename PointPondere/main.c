#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double x;
    double y;
}
Coordonnees;

typedef struct
{
    Coordonnees coord;
    double poids;
}
PointPondere;

PointPondere barycentre ( PointPondere cookie[],int taille)
{
    float sommex;
    float sommey;
    float sommeX;
    float sommeY;
    float sommePoids;
    for (int i = 0; i< taille; i++)
    {
        printf("x = %.2lf | y = %.2lf | poids = %.2lf\n", cookie[i].coord.x, cookie[i].coord.y, cookie[i].poids);
        sommePoids += cookie[i].poids;
        sommex += (cookie[i].coord.x)*(cookie[i].poids);
        sommey += (cookie[i].coord.y)*(cookie[i].poids);
    }
        sommeX = sommex/sommePoids;
        sommeY = sommey/sommePoids;
        printf("\nLe barycentre a pour coordonnees : \n");
        printf("x = %.2f\n", sommeX);
        printf("y = %.2f\n", sommeY);

}

int main()
{
    PointPondere tab [] = { {   {1,1},2     } ,
                            {   {3,2},5     } ,
                            {   {4,1},3     } ,
                            {   {8,1},4     } ,
                            {   {3,2},6     } };
    barycentre (tab, 5);
}
