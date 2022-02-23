#include "interfaceGraphique.h"
#include <stdio.h>
#include "jeu.h"

int main (int argc, char** argv)
 {
  creerFenetre ("IDpacman",    // Titre de la fenêtre graphique
                 500      ,    // Largeur de la fenêtre graphique
                 500      );   // Hauteur de la fenêtre graphique
                 
  specifierLimites (    0 ,        // Abscisse minimale
                      500 ,        // Abscisse maximale
                      500 ,        // Ordonnée minimale
                        0 );       // Ordonnée maximale

  specifierGestionnaire ( "PERIODIQUE"         , fonctionPeriodique  );

  specifierGestionnaire ( "TOUCHE ENFONCEE"    , toucheEnfoncee      );
  specifierGestionnaire ( "TOUCHE RELACHEE"    , toucheRelachee      );
  specifierGestionnaire ( "CLIC ENFONCE"       , boutonSourisEnfonce );
  specifierGestionnaire ( "CLIC RELACHE"       , boutonSourisRelache );
  specifierGestionnaire ( "DEPLACEMENT SOURIS" , mouvementSouris     );



  afficherJeu ();

  gererEvenements ();           

  detruireFenetre ();

  return 0;
 }
