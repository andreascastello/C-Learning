/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module            : types.c                                         */
/* Numéro de version : 0.7                                             */
/* Date              : 08/05/2021                                      */
/* Auteur            : Emmanuel Romagnoli                              */
/***********************************************************************/

#include "types.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

Figure2D* creerPoint (double x,
                      double y,
                      double rouge,
                      double vert,
                      double bleu)
 {
  Figure2D* figure = (Figure2D*) malloc (sizeof (Figure2D));

  if ( !figure )
   {
    perror ("Impossible de creer Figure2D");
    exit (-1);
   }

  figure->type                = POINT;
  figure->point.x             = x;
  figure->point.y             = y;
  figure->point.couleur.rouge = rouge;
  figure->point.couleur.vert  = vert;
  figure->point.couleur.bleu  = bleu;

  return figure;
 }

Figure2D* creerSegment     (double departX,
                            double departY,
                            double arriveeX,
                            double arriveeY,
                            double rouge,
                            double vert,
                            double bleu)
 {
  Figure2D* figure = (Figure2D*) malloc (sizeof (Figure2D));

  if ( !figure )
   {
    perror ("Impossible de creer Figure2D");
    exit (-1);
   }

  figure->type                  = SEGMENT;
  figure->segment.depart_x      = departX;
  figure->segment.depart_y      = departY;
  figure->segment.arrivee_x     = arriveeX;
  figure->segment.arrivee_y     = arriveeY;
  figure->segment.couleur.rouge = rouge;
  figure->segment.couleur.vert  = vert;
  figure->segment.couleur.bleu  = bleu;

  return figure;
 }

Figure2D* creerRectangle   (double Ax,
                            double Ay,
                            double Bx,
                            double By,
                            double dimension,
                            double rouge,
                            double vert,
                            double bleu)
 {
  Figure2D* figure = (Figure2D*) malloc (sizeof (Figure2D));

  if ( !figure )
   {
    perror ("Impossible de creer Figure2D");
    exit (-1);
   }

  figure->type                     = RECTANGLE;
  figure->rectangle.A_x            = Ax;
  figure->rectangle.A_y            = Ay;
  figure->rectangle.B_x            = Bx;
  figure->rectangle.B_y            = By;
  figure->rectangle.autreDimension = dimension;
  figure->rectangle.couleur.rouge  = rouge;
  figure->rectangle.couleur.vert   = vert;
  figure->rectangle.couleur.bleu   = bleu;

  return figure;
 }

Figure2D* creerCercle      (double centreX,
                            double centreY,
                            double rayon,
                            double rouge,
                            double vert,
                            double bleu)
 {
  Figure2D* figure = (Figure2D*) malloc (sizeof (Figure2D));

  if ( !figure )
   {
    perror ("Impossible de creer Figure2D");
    exit (-1);
   }

  figure->type                 = CERCLE;
  figure->cercle.centre_x      = centreX;
  figure->cercle.centre_y      = centreY;
  figure->cercle.rayon         = rayon;
  figure->cercle.couleur.rouge = rouge;
  figure->cercle.couleur.vert  = vert;
  figure->cercle.couleur.bleu  = bleu;

  return figure;
 }

Figure2D* creerArcDeCercle (double centreX,
                            double centreY,
                            double rayon,
                            double angleDepart,
                            double angleArrivee,
                            double rouge,
                            double vert,
                            double bleu)
 {
  Figure2D* figure = (Figure2D*) malloc (sizeof (Figure2D));

  if ( !figure )
   {
    perror ("Impossible de creer Figure2D");
    exit (-1);
   }

  figure->type                      = ARC_DE_CERCLE;
  figure->arcDeCercle.centre_x      = centreX;
  figure->arcDeCercle.centre_y      = centreY;
  figure->arcDeCercle.rayon         = rayon;
  figure->arcDeCercle.angleDepart   = angleDepart;
  figure->arcDeCercle.angleArrivee  = angleArrivee;
  figure->arcDeCercle.couleur.rouge = rouge;
  figure->arcDeCercle.couleur.vert  = vert;
  figure->arcDeCercle.couleur.bleu  = bleu;

  return figure;
 }

void supprimerFigure (Figure2D* figure)
 {
  if ( !figure )
   {
    free (figure);
   }
 }
