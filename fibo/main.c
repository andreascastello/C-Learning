#include <stdio.h>
#include <stdlib.h>
#include "calcul.h"


int main()
{
  int nombre;
  int i = 0;
  int j;

printf("Entrer les termes\n");
scanf("%d", &nombre);
j = fibo(nombre);
printf("%d", j);

  return 0;
}
