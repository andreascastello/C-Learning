#include <stdio.h>
#include <stdlib.h>
#include "barybary.h"
typedef struct
 {
  float x;
  float y;
  float z;
 }
 Coordonnees;

int main()
 {
  Coordonnees A = { 10 , 20 , 30 };
  Coordonnees B = { 40 , 50 , 60 };

  Coordonnees C = {
                    (A.x+B.x)/2 ,
                    (A.y+B.y)/2 ,
                    (A.z+B.z)/2
                  };

  /* Equivaut à faire :

     Coordonnees C;

     C.x = (A.x+B.x)/2;
     C.y = (A.y+B.y)/2;
     C.z = (A.z+B.z)/2;

   */

  printf (" A ( %5.2f , %5.2f , %5.2f )\n", A.x, A.y, A.z );
  printf (" B ( %5.2f , %5.2f , %5.2f )\n", B.x, B.y, B.z );
  printf (" C ( %5.2f , %5.2f , %5.2f )\n", C.x, C.y, C.z );

  return 0;
 }
