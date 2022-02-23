/***********************************************************************/
/* Projet Dessinator                                                   */
/*---------------------------------------------------------------------*/
/* Module            : types.h                                         */
/* Numéro de version : 0.7                                             */
/* Date              : 08/05/2021                                      */
/* Auteur            : Emmanuel Romagnoli                              */
/***********************************************************************/

#ifndef __TYPES_H__
#define __TYPES_H__

typedef struct
 {
  double rouge;
  double vert;
  double bleu;
 }
 Couleur;

typedef struct
 {
  unsigned int type;
  Couleur      couleur;
  double       x;
  double       y;
 }
 Point2D;

typedef struct
 {
  unsigned int type;
  Couleur      couleur;
  double       depart_x;
  double       depart_y;
  double       arrivee_x;
  double       arrivee_y;
 }
 Segment2D;

typedef struct
 {
  unsigned int type;
  Couleur      couleur;
  double       A_x;
  double       A_y;
  double       B_x;
  double       B_y;
  double       autreDimension;
 }
 Rectangle2D;

typedef struct
 {
  unsigned int type;
  Couleur      couleur;
  double       centre_x;
  double       centre_y;
  double       rayon;
 }
 Cercle2D;

typedef struct
 {
  unsigned int type;
  Couleur      couleur;
  double       centre_x;
  double       centre_y;
  double       rayon;
  double       angleDepart;
  double       angleArrivee;
 }
 ArcDeCercle2D;

typedef union
 {
  unsigned int  type;
  Point2D       point;
  Segment2D     segment;
  Rectangle2D   rectangle;
  Cercle2D      cercle;
  ArcDeCercle2D arcDeCercle;
 }
 Figure2D;


#define ROUGE   1.0f, 0.0f, 0.0f
#define VERT    0.0f, 1.0f, 0.0f
#define BLEU    0.0f, 0.0f, 1.0f
#define MAGENTA 1.0f, 0.0f, 1.0f
#define CYAN    0.0f, 1.0f, 1.0f
#define JAUNE   1.0f, 1.0f, 0.0f
#define BLANC   1.0f, 1.0f, 1.0f
#define GRIS    0.5f, 0.5f, 0.5f
#define NOIR    0.0f, 0.0f, 0.0f

#define FIGURE        0
#define POINT         1
#define SEGMENT       2
#define RECTANGLE     3
#define CERCLE        4
#define ARC_DE_CERCLE 5

Figure2D* creerPoint       (double x,
                            double y,
                            double rouge,
                            double vert,
                            double bleu);

Figure2D* creerSegment     (double departX,
                            double departY,
                            double arriveeX,
                            double arriveeY,
                            double rouge,
                            double vert,
                            double bleu);

Figure2D* creerRectangle   (double Ax,
                            double Ay,
                            double Bx,
                            double By,
                            double dimension,
                            double rouge,
                            double vert,
                            double bleu);

Figure2D* creerCercle      (double centreX,
                            double centreY,
                            double rayon,
                            double rouge,
                            double vert,
                            double bleu);

Figure2D* creerArcDeCercle (double centreX,
                            double centreY,
                            double rayon,
                            double angleDepart,
                            double angleArrivee,
                            double rouge,
                            double vert,
                            double bleu);

void supprimerFigure (Figure2D* figure);

#endif
