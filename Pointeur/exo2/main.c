#include <stdio.h>
#include <stdlib.h>

int main()
{
    char lettre = 'A';
    char* pt1 = &lettre;
    char* pt2 = pt1;
    char* pt3 = pt2;
        printf ("Lettre = %c\n", lettre);

    char remplace = 'B';
    char remplaceBis = 'C';
    char remplaceTrois = 'D';

    *pt1 = remplace;
        printf ("Lettre = %c\n", lettre);

    *pt2 = remplaceBis;
        printf ("Lettre = %c\n", lettre);

    *pt3 = remplaceTrois;
        printf ("Lettre = %c\n", lettre);
    return 0;
}
