#include <stdio.h>
#include <stdlib.h>

/*

class Vecteur
 {
  private :

  int*          contenu;
  unsigned long taille;

  public :

          Vecteur ( unsigned long taille );  // constructeur
         ~Vecteur ();  // destructeur

  void afficherVecteur ( )
  void trierVecteur (  int sens )
  void ajouterDansVecteur (  int valeur )
  int supprimerDansVecteur (  )

 };

Vecteur::~Vecteur ()
  {
     if ( v->contenu )
      {
       free ( v->contenu );
      }
  }

 void Vecteur::afficherVecteur ( )
 {
    if ( v.contenu )
          {
           printf ("Le vecteur contient %lu elements : ", v.taille);

           for ( unsigned long i=0 ; i<v.taille ; i++ )
            {
             printf ("%d ", v.contenu[i]);
            }

           printf ("\n");
          }
     else {
           printf ("Le vecteur est vide\n");
          }
 }


  Vecteur v ( 10 );     // Equivalent d'un constructeur en POO

   v.afficherVecteur();

*/




typedef struct
 {
  int*          contenu;
  unsigned long taille;
 }
 Vecteur;

Vecteur* creerVecteur ( unsigned long taille )
 {
  Vecteur* v = (Vecteur*) calloc ( 1 , sizeof (Vecteur) );

  if ( v )   // ( v != NULL )
   {
    if ( taille == 0 )
          {
           v->contenu = NULL;
           v->taille  = 0;
          }
     else {
           v->contenu = (int*) calloc ( taille , sizeof (int) );

           if ( v->contenu )
                {
                 v->taille = taille;
                }
           else {
                 // Comme on n'a pas pu allouer la mémoire pour le tableau de int,
                 // on désalloue la mémoire utilisée par v, car la structure est
                 // devenue inutile. On remet v à NULL, pour signifier l'erreur à
                 // l'extérieur de la fonction

                 free (v);
                 v = NULL;
                }
          }
   }

  return v;
 }

 void detruireVecteur ( Vecteur* v )
  {
   if ( v )
    {
     // On essaye d'abord de détruire le tableau de int (contenu) avant
     // de détruire la structure

     if ( v->contenu )
      {
       free ( v->contenu );
      }

     free ( v );
    }
  }

void afficherVecteur ( Vecteur* v )
 {
  if ( v )
   {
    if ( v->contenu )
          {
           printf ("Le vecteur contient %lu elements : ", v->taille);

           for ( unsigned long i=0 ; i<v->taille ; i++ )
            {
             printf ("%d ", v->contenu[i]);
            }

           printf ("\n");
          }
     else {
           printf ("Le vecteur est vide\n");
          }
   }
 }

#define CROISSANT   1
#define DECROISSANT 2

void trierVecteur ( Vecteur* v , int sens )
 {
  if ( v && v->contenu && ( sens == CROISSANT || sens == DECROISSANT ) )
   {
    int temp;
    int permutation = 0;

    do
     {
      permutation = 0;

      for ( unsigned long i=0 ; i<v->taille-1 ; i++)
       if ( ( ( *(v->contenu+i) > *(v->contenu+i+1) ) && ( sens ==   CROISSANT ) ) ||
            ( ( *(v->contenu+i) < *(v->contenu+i+1) ) && ( sens == DECROISSANT ) ) )
        {
         temp              = *(v->contenu+i);
         *(v->contenu+i)   = *(v->contenu+i+1);
         *(v->contenu+i+1) = temp;

         permutation = 1;
        }
     }
     while ( permutation );
   }
 }

void ajouterDansVecteur ( Vecteur* v , int valeur )
 {
  if ( v )
   {
    int* temp = (int*) calloc ( v->taille + 1 , sizeof (int) );

    if ( temp )
     {
      for ( unsigned long i = 0 ; i<v->taille ; i++ )
       {
        temp[i] = v->contenu[i];
       }

      temp[v->taille] = valeur;

      if ( v->contenu )
       {
        free ( v->contenu );
       }

      v->contenu = temp;

      v->taille += 1;
     }
   }
 }

int supprimerDansVecteur ( Vecteur* v )
 {
  int valeur = 0;

  if ( v )
   {
    if ( v->taille > 0 )
     {
      int* temp = NULL;

      if ( v->taille > 1 )
       {
        temp = (int*) calloc ( v->taille - 1 , sizeof (int) );

        if ( temp )
         {
          for ( unsigned long i = 0 ; i<v->taille-1 ; i++ )
           {
            temp[i] = v->contenu[i];
           }
         }
       }

      valeur = v->contenu [v->taille-1];

      if ( v->contenu )
       {
        free ( v->contenu );
       }

      v->contenu = temp;

      v->taille -= 1;
     }
   }

  return valeur;
 }

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

  while ( v->taille > 0 )
   {
    printf ( "On retire %d => ", supprimerDansVecteur (v) );
    afficherVecteur (v);
   }

  detruireVecteur ( v );
  printf ("Le vecteur a ete detruit\n");

  return 0;
 }
