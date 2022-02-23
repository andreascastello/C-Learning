#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#define TAILLE 50

#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3

#include <stdint.h>

void afficherMur      (int x, int y);
void afficherSol      (int x, int y);
void afficherJoueur   (int x, int y);
void afficherFantome  (int x, int y);
void afficherPacgomme (int x, int y);
void afficherPastille (int x, int y);

void afficherJeu ();

void deplacerJoueur  (int dir);
void deplacerFantome (int dir);

// a correspond au temps, exprimé en nanosecondes, qui s'est écoulé depuis le lancement du programme
// b et c n'ont pas de signification et sont mis à 0

void fonctionPeriodique ( uint64_t a , uint64_t b , uint64_t c);

// a correspond au code de la touche enfoncée
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void toucheEnfoncee ( uint64_t a , uint64_t b , uint64_t c);

// a correspond au code de la touche relâchée
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void toucheRelachee ( uint64_t a , uint64_t b , uint64_t c);

// a correspond au code du bouton de la souris, qui est enfoncé
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void boutonSourisEnfonce ( uint64_t a , uint64_t b , uint64_t c);

// a correspond au code du bouton de la souris, qui est relâchée
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void boutonSourisRelache ( uint64_t a , uint64_t b , uint64_t c);

// a n'a pas de signification et est mis à 0
// b correspond à l'abscisse du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche
// c correspond à l'ordonnée du pointeur de la souris, dans la fenêtre, par rapport au coin supérieur gauche

void mouvementSouris ( uint64_t a , uint64_t b , uint64_t c);



#endif // JEU_H_INCLUDED
