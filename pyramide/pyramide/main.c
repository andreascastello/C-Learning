#include <stdio.h>
#include <stdlib.h>

void main()
{
    int h = NULL;

    scanf("%d", &h);

    for (int i = 0; i < h; i++)
    {
        for (int j = h-i; j > 0; j--)
            printf(" ");

        for (int j = -1; j < i*2; j++)
            printf("*");

        printf("\n");
    }
}
