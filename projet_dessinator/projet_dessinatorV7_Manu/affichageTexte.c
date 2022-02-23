/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module            : affichageTexte.c                                */
/* Numéro de version : 0.7                                             */
/* Date              : 08/05/2021                                      */
/* Auteur            : Emmanuel Romagnoli                              */
/***********************************************************************/

#include "affichageTexte.h"

#include <stdio.h>

void printf_Couleur (Couleur c)
 {
  printf ("  - Rouge : %.3lf\n", c.rouge);
  printf ("  - Vert  : %.3lf\n", c.vert );
  printf ("  - Bleu  : %.3lf\n", c.bleu );
 }

void printf_Point2D (Point2D p)
 {
  printf ("Point 2D :\n");
  printf ("  - Coordonnees : (%.3f ; %.3f)\n", p.x,  p.y);
  printf_Couleur (p.couleur);
  printf ("\n");
 }

void printf_Segment2D (Segment2D s)
 {
  printf ("Segment 2D :\n");
  printf ("  - Point de depart : (%.3f ; %.3f)\n", s.depart_x,  s.depart_y);
  printf ("  - Point d'arrivee : (%.3f ; %.3f)\n", s.arrivee_x, s.arrivee_y);
  printf_Couleur (s.couleur);
  printf ("\n");
 }

void printf_Rectangle2D (Rectangle2D r)
 {
  printf ("Rectangle 2D :\n");
  printf ("  - Point A         : (%.3f ; %.3f)\n", r.A_x, r.A_y);
  printf ("  - Point B         : (%.3f ; %.3f)\n", r.B_x, r.B_y);
  printf ("  - Autre dimension : %.3f\n"         , r.autreDimension);
  printf_Couleur (r.couleur);
  printf ("\n");
 }

void printf_Cercle2D (Cercle2D c)
 {
  printf ("Cercle 2D :\n");
  printf ("  - Centre : (%.3f ; %.3f)\n", c.centre_x,  c.centre_y);
  printf ("  - Rayon  : %.3f\n"         , c.rayon);
  printf_Couleur (c.couleur);
  printf ("\n");
 }

void printf_ArcDeCercle2D (ArcDeCercle2D a)
 {
  printf ("Arc de cercle 2D :\n");
  printf ("  - Centre          : (%.3f ; %.3f)\n", a.centre_x,  a.centre_y);
  printf ("  - Rayon           : %.3f\n"         , a.rayon);
  printf ("  - Angle de depart : %.3f\n"         , a.angleDepart);
  printf ("  - Angle d'arrivee : %.3f\n"         , a.angleArrivee);
  printf_Couleur (a.couleur);
  printf ("\n");
 }

void printf_Figure2D (Figure2D* f)
 {
  if ( f )
   {
    switch (f->type)
     {
      case POINT         : printf_Point2D       ( f->point       ); break;
      case SEGMENT       : printf_Segment2D     ( f->segment     ); break;
      case RECTANGLE     : printf_Rectangle2D   ( f->rectangle   ); break;
      case CERCLE        : printf_Cercle2D      ( f->cercle      ); break;
      case ARC_DE_CERCLE : printf_ArcDeCercle2D ( f->arcDeCercle );
     }
   }
 }

