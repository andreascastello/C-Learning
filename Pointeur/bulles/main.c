#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
 {
  int  valeur [10];
  int* index  [10];
 }
 Tableau;

Tableau initialiser ()
 {
  Tableau t;  // C'est créé en local de la fonction initialiser

  for ( int i=0 ; i<10 ; i++ )
   {
    t.valeur [i] = rand() % 51;   // rand() renvoie un nombre entre 0 et RAND_MAX
                                  // Pour avoir des valeurs entre 0 et 50, j'utilise le reste
                                  // de la division par 51  => %51;

    t.index  [i] = &(t.valeur[i]);

  //  printf ("%p %p\n", &(t.valeur[i]), t.index  [i] );
   }

  return t;
 }

Tableau initialiser2 (Tableau t)   // Je passe en paramètre qqch que j'ai créé dans le main
 {
  for ( int i=0 ; i<10 ; i++ )
   {
    t.valeur [i] = rand() % 50;
    t.index  [i] = &(t.valeur[i]);

  //  printf ("%p %p\n", &(t.valeur[i]), t.index  [i] );
   }

  return t;
 }

void afficher ( Tableau t )
  {
   for ( int i=0 ; i<10 ; i++ )
    {
     printf ("valeur [%d] = %2d (%p) et index[%d]=%p\n", i, t.valeur[i], &(t.valeur[i]), i, t.index[i]);
    }
  }

Tableau trier (Tableau t)   // Je passe en paramètre qqch que j'ai créé dans le main
 {
  int  permutation = 0;
  int* temp;

  do
   {
    permutation = 0;

    for ( int i=0 ; i<9 ; i++ )
     {
      if ( *(t.index [i]) > *(t.index [i+1])  )
       {
        temp          = t.index [i];
        t.index [i]   = t.index [i+1];
        t.index [i+1] = temp;
        permutation = 1;

        printf ("On permute les adresses %d (%p => %2d) et %d (%p => %2d)\n", i   , t.index [i  ] , *(t.index [i  ]) ,
                                                                              i+1 , t.index [i+1] , *(t.index [i+1]) );

       }
     }
   }
   while ( permutation );

  return t;
 }

void afficher2 ( Tableau t )
  {
   for ( int i=0 ; i<10 ; i++ )
    {
     printf ("index [%d] = %p => %d\n", i, t.index[i], *(t.index[i]) );
    }

   for ( int i=0 ; i<10 ; i++ )
    {
     printf ("valeur [%d] = %d => %p\n", i, t.valeur[i], &(t.valeur[i]) );
    }
  }


int main()
 {
  srand ( time (NULL) );

  Tableau t;

  t = initialiser2 (t);

  printf ("Situation initiale : \n");

  afficher (t);

  printf ("========\n");

  t = trier (t);

  printf ("\n\nSituation finale : \n");

  afficher2 (t);

  return 0;
 }
