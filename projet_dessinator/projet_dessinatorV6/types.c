#include <stdio.h>
#include "types.h"
#include <errno.h>

    Figure2D* creerPoint (double x, double y, double rouge, double vert, double bleu)
    {
        Figure2D* fig = (Figure2D*) malloc (sizeof(Figure2D));
        if (fig == NULL)
        {
            perror ("Erreur d'allocation");
            exit (-1);
        }
        fig->point.x                = x;
        fig->point.y                = y;
        fig->point.couleur.rouge    = rouge;
        fig->point.couleur.vert     = vert;
        fig->point.couleur.bleu     = bleu;
        fig->type                   = POINT;
    }

    Figure2D* creerSegment (double departX, double departY, double arriveeX, double arriveeY, double rouge, double vert, double bleu)
    {
        Figure2D* fig = (Figure2D*) malloc (sizeof(Figure2D));
        if (fig == NULL)
        {
            perror ("Erreur d'allocation");
            exit (-1);
        }
        fig->segment.departX        = departX;
        fig->segment.departY        = departY;
        fig->segment.arriveeX       = arriveeX;
        fig->segment.arriveeY       = arriveeY;
        fig->segment.couleur.rouge  = rouge;
        fig->segment.couleur.vert   = vert;
        fig->segment.couleur.bleu   = bleu;
        fig->segment.type           = SEGMENT;

        return fig;
    }

    Figure2D* creerRectangle (double Ax, double Ay, double Bx, double By, double dimension, double rouge, double vert, double bleu)
    {
        Figure2D* fig = (Figure2D*) malloc (sizeof(Figure2D));
        if (fig == NULL)
        {
            perror ("Erreur d'allocation");
            exit (-1);
        }
        fig->rectangle.AX             = Ax;
        fig->rectangle.AY             = Ay;
        fig->rectangle.BX             = Bx;
        fig->rectangle.BY             = By;
        fig->rectangle.dimension      = dimension;
        fig->rectangle.couleur.rouge  = rouge;
        fig->rectangle.couleur.vert   = vert;
        fig->rectangle.couleur.bleu   = bleu;
        fig->rectangle.type           = RECTANGLE;

        return fig;
    }

    Figure2D* creerCercle (double centreX, double centreY, double rayon, double rouge, double vert, double bleu)
    {
        Figure2D* fig = (Figure2D*) malloc (sizeof(Figure2D));
        if (fig == NULL)
        {
            perror ("Erreur d'allocation");
            exit (-1);
        }
        fig->cercle.centreX        = centreX;
        fig->cercle.centreY        = centreY;
        fig->cercle.rayon          = rayon;
        fig->cercle.couleur.rouge  = rouge;
        fig->cercle.couleur.vert   = vert;
        fig->cercle.couleur.bleu   = bleu;
        fig->cercle.type           = CERCLE;

        return fig;
    }

    Figure2D* creerArcDeCercle (double centreX, double centreY, double rayon, double angleDepart, double angleArrivee, double rouge, double vert, double bleu)
    {
        Figure2D* fig = (Figure2D*) malloc (sizeof(Figure2D));
        if (fig == NULL)
        {
            perror ("Erreur d'allocation");
            exit (-1);
        }
        fig->arcDeCercle.centreX          = centreX;
        fig->arcDeCercle.centreY          = centreY;
        fig->arcDeCercle.rayon            = rayon;
        fig->arcDeCercle.debut            = angleDepart;
        fig->arcDeCercle.fin              = angleArrivee;
        fig->arcDeCercle.couleur.rouge    = rouge;
        fig->arcDeCercle.couleur.vert     = vert;
        fig->arcDeCercle.couleur.bleu     = bleu;
        fig->arcDeCercle.type             = ARC_DE_CERCLE;

        return fig;
    }

    void supprimerFigure (Figure2D* fig)
    {
        if (fig)
        {
            free (fig);
        }
    }

