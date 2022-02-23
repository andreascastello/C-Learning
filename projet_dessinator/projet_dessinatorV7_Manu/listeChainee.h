/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module            : listeChaine.h                                   */
/* Numéro de version : 0.7                                             */
/* Date              : 08/05/2021                                      */
/* Auteur            : Emmanuel Romagnoli                              */
/***********************************************************************/

#ifndef __LISTE_CHAINEE_H__
#define __LISTE_CHAINEE_H__

#include "types.h"

typedef struct strNoeud Noeud;

struct strNoeud
 {
  Figure2D* contenu;
  Noeud*    suivant;
 };

typedef struct
 {
  Noeud*       premier;
  unsigned int taille;
  char         nom [50];
 }
 ListeChainee;

Noeud*        creerNoeud         ( Figure2D*     _figure        );

void          detruireNoeud      ( Noeud*        _noeud         );

ListeChainee* creerListe         ( char*         _nom           );

void          detruireListe      ( ListeChainee* _liste         );

void          insererDansListe   ( ListeChainee* _liste         ,
                                   Figure2D*     _element       ,
                                   unsigned int  _ptInsertion   );

Figure2D      supprimerDansListe ( ListeChainee* _liste         ,
                                   unsigned int  _ptSuppression );

void          afficherListe      ( ListeChainee* _liste         );

void          ajouterPoint       ( ListeChainee* _liste         ,
                                   double        _x             ,
                                   double        _y             ,
                                   double        _rouge         ,
                                   double        _vert          ,
                                   double        _bleu          );

void          ajouterSegment     ( ListeChainee* _liste         ,
                                   double        _departX       ,
                                   double        _departY       ,
                                   double        _arriveeX      ,
                                   double        _arriveeY      ,
                                   double        _rouge         ,
                                   double        _vert          ,
                                   double        _bleu          );

void          ajouterRectangle   ( ListeChainee* _liste         ,
                                   double        _Ax            ,
                                   double        _Ay            ,
                                   double        _Bx            ,
                                   double        _By            ,
                                   double        _dimension     ,
                                   double        _rouge         ,
                                   double        _vert          ,
                                   double        _bleu          );

void          ajouterCercle      ( ListeChainee* _liste         ,
                                   double        _centreX       ,
                                   double        _centreY       ,
                                   double        _rayon         ,
                                   double        _rouge         ,
                                   double        _vert          ,
                                   double        _bleu          );

void          ajouterArcDeCercle ( ListeChainee* _liste         ,
                                   double        _centreX       ,
                                   double        _centreY       ,
                                   double        _rayon         ,
                                   double        _angleDepart   ,
                                   double        _angleArrivee  ,
                                   double        _rouge         ,
                                   double        _vert          ,
                                   double        _bleu          );


#endif
