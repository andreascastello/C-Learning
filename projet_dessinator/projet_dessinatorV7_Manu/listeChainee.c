/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module            : listeChainee.c                                  */
/* Numéro de version : 0.7                                             */
/* Date              : 08/05/2021                                      */
/* Auteur            : Emmanuel Romagnoli                              */
/***********************************************************************/

#include "listeChainee.h"
#include "affichageTexte.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Noeud* creerNoeud ( Figure2D* _figure )
 {
  Noeud* n = (Noeud*) malloc ( sizeof (Noeud) );

  if ( n )
   {
    n->contenu = _figure;
    n->suivant = NULL;
   }

  return n;
 }

void detruireNoeud ( Noeud* _noeud )
 {
  if ( _noeud )
   {
    if ( _noeud->contenu )
     {
      free ( _noeud->contenu );
     }

    free ( _noeud );
   }
 }

ListeChainee* creerListe ( char* _nom )
 {
  ListeChainee* l = (ListeChainee*) malloc ( sizeof (ListeChainee) );

  if ( l )
   {
    l->premier = NULL;
    l->taille  = 0;

    strcpy (l->nom, _nom);
   }

  return l;
 }

void detruireListe ( ListeChainee* _liste )
 {
  if ( _liste )
   {
    Noeud* courant = _liste->premier;
    Noeud* suivant = NULL;

    while ( courant )
     {
      suivant = courant->suivant;

      detruireNoeud (courant);

      courant = suivant;
     }

    free ( _liste );
   }
 }

void insererDansListe ( ListeChainee* _liste       ,
                        Figure2D*     _element     ,
                        unsigned int  _ptInsertion )
 {
  if ( _liste )
   {
    if ( _ptInsertion > _liste->taille )
          {
           printf ("Le point d'insertion %u est incorrect\n", _ptInsertion);
          }
     else {
           if ( _liste->premier == NULL )
                 {
                  _liste->premier = creerNoeud ( _element );

                  if ( _liste->premier )
                        {
                         _liste->taille  += 1;
                        }
                   else {
                         perror ( "Impossible d'ajouter la figure" );
                        }
                 }
            else {
                  Noeud* noeudEcrit = creerNoeud ( _element );

                  if ( noeudEcrit )
                        {
                         Noeud* courant    = _liste->premier;
                         Noeud* noeudAvant = NULL;

                         for ( unsigned int i=0; i<_ptInsertion; i++)
                          {
                           noeudAvant = courant;
                           courant    = courant->suivant;
                          }

                         noeudEcrit->suivant = courant;
                         noeudAvant->suivant = noeudEcrit;

                         _liste->taille  += 1;
                        }
                   else {
                         perror ( "Impossible d'ajouter la figure" );
                        }
                 }
          }

   }
 }

Figure2D supprimerDansListe ( ListeChainee* _liste         ,
                              unsigned int  _ptSuppression )
 {
  Figure2D figure = { .type = FIGURE };

  if ( _liste )
   {
    if ( _ptSuppression >= _liste->taille )
          {
           printf ("Le point de suppression %d est incorrect\n", _ptSuppression);
          }
     else {
           if ( _liste->premier )
            {
             if ( _liste->taille == 1 )
                   {
                    figure = *(_liste->premier->contenu);

                    detruireNoeud ( _liste->premier );

                    _liste->premier = NULL;

                    _liste->taille  = 0;
                   }
              else {
                    Noeud* courant    = _liste->premier;
                    Noeud* noeudAvant = NULL;
                    Noeud* noeudApres = NULL;

                    for ( unsigned int i=0; i<_ptSuppression; i++ )
                     {
                      noeudAvant = courant;
                      courant    = courant->suivant;
                      noeudApres = courant->suivant;
                     }

                    figure = *(courant->contenu);

                    detruireNoeud ( courant );

                    noeudAvant->suivant = noeudApres;

                    _liste->taille  -= 1;
                   }
            }
          }
        }

  return figure;
 }

void afficherListe ( ListeChainee* _liste )
 {
  if ( _liste )
   {
    if ( _liste->premier == NULL)
          {
           printf ("\n\nLa liste ne contient aucune figure\n\n");
          }
     else {
           printf ("\n\nLa liste ne contient %u figure%s\n\n", _liste->taille, (_liste->taille>1?"s":"") );

           Noeud* courant = _liste->premier;

           while ( courant )
            {
             printf_Figure2D ( courant->contenu );

             courant = courant->suivant;
            }

           printf ("\n\n\n");
          }
   }
 }

void ajouterPoint ( ListeChainee* _liste ,
                    double        _x     ,
                    double        _y     ,
                    double        _rouge ,
                    double        _vert  ,
                    double        _bleu  )
 {
  if ( _liste )
   {
    insererDansListe ( _liste , creerPoint ( _x     ,
                                             _y     ,
                                             _rouge ,
                                             _vert  ,
                                             _bleu  ) , _liste->taille );
   }
 }

void ajouterSegment ( ListeChainee* _liste    ,
                      double        _departX  ,
                      double        _departY  ,
                      double        _arriveeX ,
                      double        _arriveeY ,
                      double        _rouge    ,
                      double        _vert     ,
                      double        _bleu     )
 {
  if ( _liste )
   {
    insererDansListe ( _liste , creerSegment ( _departX  ,
                                               _departY  ,
                                               _arriveeX ,
                                               _arriveeY ,
                                               _rouge    ,
                                               _vert     ,
                                               _bleu     ) , _liste->taille );
   }
 }

void ajouterRectangle ( ListeChainee* _liste     ,
                        double        _Ax        ,
                        double        _Ay        ,
                        double        _Bx        ,
                        double        _By        ,
                        double        _dimension ,
                        double        _rouge     ,
                        double        _vert      ,
                        double        _bleu      )
 {
  if ( _liste )
   {
    insererDansListe ( _liste , creerRectangle ( _Ax        ,
                                                 _Ay        ,
                                                 _Bx        ,
                                                 _By        ,
                                                 _dimension ,
                                                 _rouge     ,
                                                 _vert      ,
                                                 _bleu      ) , _liste->taille );
   }
 }

void ajouterCercle ( ListeChainee* _liste   ,
                     double        _centreX ,
                     double        _centreY ,
                     double        _rayon   ,
                     double        _rouge   ,
                     double        _vert    ,
                     double        _bleu    )
 {
  if ( _liste )
   {
    insererDansListe ( _liste , creerCercle ( _centreX ,
                                              _centreY ,
                                              _rayon   ,
                                              _rouge   ,
                                              _vert    ,
                                              _bleu    ) , _liste->taille );
   }
 }

void ajouterArcDeCercle ( ListeChainee* _liste         ,
                          double        _centreX       ,
                          double        _centreY       ,
                          double        _rayon         ,
                          double        _angleDepart   ,
                          double        _angleArrivee  ,
                          double        _rouge         ,
                          double        _vert          ,
                          double        _bleu          )
 {
  if ( _liste )
   {
    insererDansListe ( _liste , creerArcDeCercle ( _centreX      ,
                                                   _centreY      ,
                                                   _rayon        ,
                                                   _angleDepart  ,
                                                   _angleArrivee ,
                                                   _rouge        ,
                                                   _vert         ,
                                                   _bleu         ) , _liste->taille );
   }
 }
