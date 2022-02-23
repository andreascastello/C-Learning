#include <stdio.h>
#include <time.h>

void attendre(float temps);

int main(void)
{
    int compteur;

    for(compteur=10;compteur>0;compteur--){
        printf("%d...\n", compteur);

        attendre(1);
    }

    puts("BONNE ANNEE !!!\n");

    return 0;
}

void attendre(float temps)
{
    clock_t arrivee=clock()+(temps*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter

    while(clock()<arrivee);
}
