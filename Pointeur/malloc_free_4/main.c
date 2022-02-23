#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"

int main()
 {
  Vecteur* v = creerVecteur ( 10 );     // Equivalent d'un constructeur en POO


  printf ("Apres la creation de v                => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 10 );
  printf ("Apres l'ajout de 10                   => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 0 );
  printf ("Apres l'ajout de 0                    => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 8 );
  printf ("Apres l'ajout de 8                    => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 14 );
  printf ("Apres l'ajout de 14                   => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 11 );
  printf ("Apres l'ajout de 11                   => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 3 );
  printf ("Apres l'ajout de 3                    => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 7 );
  printf ("Apres l'ajout de 7                    => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 2 );
  printf ("Apres l'ajout de 2                    => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 4 );
  printf ("Apres l'ajout de 4                    => ");
  afficherVecteur ( v );

  ajouterDansVecteur ( v , 10 );
  printf ("Apres l'ajout de 10                   => ");
  afficherVecteur ( v );

  trierVecteur ( v , CROISSANT );
  printf ("Apres le tri dans l'ordre croissant   => ");
  afficherVecteur ( v );

  trierVecteur ( v , DECROISSANT );
  printf ("Apres le tri dans l'ordre decroissant => ");
  afficherVecteur ( v );


  insererDansVecteur (v, 76, 3);
  printf ("Apres insertion de 76 dans la case 3  => ");
  afficherVecteur ( v );


  while ( v->taille > 0 )
   {
    printf ( "On retire %d => ", supprimerDansVecteur (v) );
    afficherVecteur (v);
   }

  detruireVecteur ( v );
  printf ("Le vecteur a ete detruit\n");



  return 0;
 }
