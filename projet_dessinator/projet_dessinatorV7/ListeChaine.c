#include <stdio.h>
#include <stdlib.h>
#include "ListeChaine.h"

Noeud* creerNoeud(Figure2D* fig)
{
    Noeud* nd = (Noeud*) malloc (sizeof(Noeud));
    nd->contenu = fig;
    nd->suivant = NULL;
    nd->precedent = NULL;

    return nd;
}

void detruireNoeud (Noeud* nd)
{
    if (nd)
    {
        supprimerFigure(nd->contenu);
        free(nd);
    }
}

listeChainee* creerListe (char* nom, unsigned int taille)
{
    listeChainee* lc = (listeChainee*) malloc (sizeof(listeChainee));
    if (lc != NULL)
    {
        lc->taille = 0;
        lc->premier = NULL;
        lc->dernier = NULL;

        for (int i = 0; i < 50; i++)
        {
            lc->nom[i] = nom[i];
        }
    }
    return lc;
}


void insererDebut (listeChainee* lc,Figure2D* fig)
{
    if (lc != NULL)
    {
        Noeud* newNoeud = creerNoeud(fig);

        if (newNoeud)
        {


            if (lc->dernier == NULL)
            {
                newNoeud->suivant   = NULL;
                lc->premier         = newNoeud;
                lc->dernier         = newNoeud;
            }
            else
            {
                lc->premier->precedent  = newNoeud;
                newNoeud->suivant       = lc->premier;
                lc->dernier             = newNoeud;
            }
            lc->taille++;
        }
    }
}

void insererFin (listeChainee* lc,Figure2D* fig)
{
    if (lc != NULL)
    {
        Noeud* newNoeud = creerNoeud(fig);

        if (newNoeud)
        {
            if (lc->premier == NULL)
            {
                newNoeud->precedent = NULL;
                lc->premier         = newNoeud;
                lc->dernier         = newNoeud;
            }
            else
            {
                lc->dernier->suivant  = newNoeud;
                newNoeud->precedent   = lc->dernier;
                lc->dernier           = newNoeud;
            }
            lc->taille++;
        }
    }
}

void insererDansListe (listeChainee* lc, Figure2D* fig, unsigned int pointInser)
{
    if (lc != NULL && fig !=NULL && pointInser > 0)
    {
        Noeud* noeudCourant = lc->premier;
        int k = 1;

        while (k <= pointInser)
        {
            if (k == pointInser)
            {
                if (k == 1 && noeudCourant != NULL)
                {
                     insererDebut(lc, fig);
                }
                else if (k == lc->taille + 1 && noeudCourant == NULL)
                {
                   insererFin(lc, fig);
                }
                else if (noeudCourant != NULL)
                {
                    Noeud* newNoeud = creerNoeud(fig);
                        newNoeud->suivant                   = noeudCourant;
                        newNoeud->precedent                 = noeudCourant->precedent;
                        noeudCourant->precedent->suivant    = newNoeud;
                        noeudCourant->precedent             = newNoeud;
                }
            }
            else
            {
                noeudCourant = noeudCourant->suivant;
            }
            k++;
        }
    }
}

void detruireListe (listeChainee** lc)
{
    if (*lc)
    {
        Noeud* noeudCourant = (*lc)->premier;
        while (noeudCourant != NULL)
        {
            Noeud* ndDelete = noeudCourant;
            noeudCourant    = noeudCourant->suivant;
            free(ndDelete);
        }
        free(*lc);
    }
}

void afficherListe (listeChainee* lc)
{
    if (lc)
    {
        Noeud* noeudCourant = lc->premier;
        while (noeudCourant != NULL)
        {
            printf_Figure2D (noeudCourant->contenu);
            noeudCourant = noeudCourant->suivant;
        }
    }

}

Figure2D* supprimerDansListe (listeChainee* lc, unsigned int pointSup)
{
    if(lc != NULL && pointSup > 0)
    {
        Noeud* noeudCourant = lc->premier;
        int k = 1;

        while (noeudCourant != NULL && k <= pointSup)
        {
            if(pointSup == k)
            {
                if (noeudCourant->suivant == NULL)
                {
                    lc->dernier = noeudCourant->precedent;
                    lc->dernier->suivant = NULL;
                }
                else if (noeudCourant->precedent == NULL)
                {
                    lc->premier = noeudCourant->suivant;
                    lc->premier->precedent = NULL;
                }
                else
                {
                    noeudCourant->suivant->precedent = noeudCourant->precedent;
                    noeudCourant->precedent->suivant = noeudCourant->suivant;
                }
            }
            else
            {
                noeudCourant = noeudCourant->suivant;
            }
            k++;
        }
    }
}


    void ajouterPoint (listeChainee* lc, double x, double y, double rouge, double vert, double bleu)
    {
        Figure2D* fig = creerPoint(x, y, rouge, vert, bleu);
        insererDebut (lc, fig);
    }

    void ajouterSegment (listeChainee* lc, double departX, double departY, double arriveeX, double arriveeY, double rouge, double vert, double bleu)
    {
        Figure2D* fig = creerSegment(departX, departY, arriveeX, arriveeY, rouge, vert, bleu);
    insererDansListe(lc, fig, 2);
    }

    void ajouterRectangle (listeChainee* lc, double Ax, double Ay, double Bx, double By, double dimension, double rouge, double vert, double bleu)
    {
        Figure2D* fig = creerRectangle(Ax, Ay, Bx, By, dimension, rouge, vert, bleu);
    insererDansListe(lc, fig, 3);
    }

    void ajouterCercle (listeChainee* lc, double centreX, double centreY, double rayon, double rouge, double vert, double bleu)
    {
        Figure2D* fig = creerCercle(centreX, centreY, rayon, rouge, vert, bleu);
    insererDansListe(lc, fig, 4);
    }

    void ajouterArcDeCercle (listeChainee* lc, double centreX, double centreY, double rayon, double angleDepart, double angleArrivee, double rouge, double vert, double bleu)
    {
        Figure2D* fig = creerArcDeCercle(centreX, centreY, rayon, angleDepart, angleArrivee, rouge, vert, bleu);
        insererFin (lc, fig);
    }
