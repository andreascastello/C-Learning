#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct
{
    char nom[10];
    int resistance;
}
Classe;


typedef struct
{
    char composant[10];
}
Matiere;

typedef struct
{
    float masse;
}
Poids;

typedef struct
{
    int PE;
}
Energie;

typedef union
{
    Matiere matiere;
    Poids poids;
}
Arme;





/////////////////////////////////////////////////////////////////CREATION DES PERSONNAGES//////////////////////////////////////////////////////////////////////



typedef struct
{
    Classe classe;
    int fleches;
    Arme arme;
}
Guerrier;


typedef struct
{
    Classe classe;
    char culinaire[10];
    char boucher[10];
}
Cuisinier;

typedef struct
{
    Classe classe;
    int exp;
    int heal;
}
Medecin;

typedef struct
{
    Classe classe;
    int exp;
    char categorie[10];
}
Magicien;

///////////////////////////////////////////////////////////////Fin de création des personnages/////////////////////////////////////////////////////////////////


int main()
{
if (!SetConsoleOutputCP(65001))
printf ("ERREUR\n");

    Magicien Mage;

    Mage.exp = 9;
    Mage.categorie[6] = "Sorts";

    printf("Voici votre mage : Exp : %d  Specialise en : %c", Mage.exp, Mage.categorie[6]);

}
