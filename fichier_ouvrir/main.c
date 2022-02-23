#include <stdio.h>
int main (int argc, char* argv[])
{
 char* nomFichier = "essai.txt";
 FILE* fichier = fopen ( nomFichier , "r" );
 char chaine [50];
 if ( fichier )
 {
 printf ("Le fichier %s a pu etre ouvert en lecture.\n", nomFichier);
 for (int i = 0; i < 2; i++){
   printf ("chaine=%s\n", fgets (chaine, 50, fichier) );
 }
 fclose (fichier);

 }
 else {
 printf ("Le fichier %s n'a pas pu etre ouvert.\n", nomFichier);
 }
 return 0;
}
