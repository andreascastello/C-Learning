#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
printf ("argc = %d\n", argc);
 printf ("argv[0] = %s\n", argv[0]);
 printf ("argv[1] = %s\n", argv[1]);
 printf ("argv[2] = %s\n", argv[2]);

 if (argc != 3)
 {
     printf ("le dossier machin machin\n");
 }
 else
 {
     printf ("le code %s va vers le fichier %s\n", argv[1], argv[2]);
 }
    return 0;
}
