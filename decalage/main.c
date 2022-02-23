#include <stdio.h>

int main()
 {
  int tab [10];
  int temp;

  for (int i=0; i<10; i++) tab [i] = 0;

  for (int s=0; s<10; s++)
   {
    printf ("Saisir la valeur : ");
    scanf ("%d", &temp);

    for (int c=9; c>=1; c--) tab[c] = tab[c-1];

    tab[0] = temp;

    printf ("TAB : ");
    for (int c=0; c<10; c++) printf ("%d ", tab[c]);
    printf ("\n");

   }

  return 0;
 }
