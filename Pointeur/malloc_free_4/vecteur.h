#ifndef VECTEUR_H_INCLUDED
#define VECTEUR_H_INCLUDED
#define CROISSANT   1
#define DECROISSANT 2
typedef struct
 {
  int*          contenu;
  unsigned long taille;
 }
 Vecteur;

 Vecteur* creerVecteur ( unsigned long taille );
  void detruireVecteur ( Vecteur* v );
  void afficherVecteur ( Vecteur* v );
  void trierVecteur ( Vecteur* v , int sens );
  void ajouterDansVecteur ( Vecteur* v , int valeur );
  int supprimerDansVecteur ( Vecteur* v );
  void insererDansVecteur ( Vecteur* v, int valeur, int position);

#endif // VECTEUR_H_INCLUDED
