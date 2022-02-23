/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module            : affichageTexte.h                                */
/* Numéro de version : 0.7                                             */
/* Date              : 08/05/2021                                      */
/* Auteur            : Emmanuel Romagnoli                              */
/***********************************************************************/

#ifndef __AFFICHAGE_TEXTE_H__
#define __AFFICHAGE_TEXTE_H__

#include "types.h"

void printf_Point2D       (Point2D       p);
void printf_Segment2D     (Segment2D     s);
void printf_Rectangle2D   (Rectangle2D   r);
void printf_Cercle2D      (Cercle2D      c);
void printf_ArcDeCercle2D (ArcDeCercle2D a);

void printf_Figure2D      (Figure2D*     f);

#endif
