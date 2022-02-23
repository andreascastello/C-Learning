#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h> //perror

int* creerTableau (int taille)
{
    int* tab = (int*)calloc(taille, sizeof(int));

    return tab;
}

int main()
{
    srand (time (NULL));
    int i;
    int taille = 6000000000000000000;
    int* cookie = creerTableau(taille);

if(cookie)
{

    for (i = 0; i<taille; i++)
    {
        printf ("%d ", *(cookie+i));
    }
    printf ("\n");

    for (i = 0; i<taille; i++)
    {
        *(cookie + i) = rand()%100+1;
        printf ("%d ", *(cookie+i));
    }

    free (cookie);

}
else
    perror ("error");
    return 0;
}
