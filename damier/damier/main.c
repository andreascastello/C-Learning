#include <stdio.h>
#include <stdlib.h>

void main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                    printf ("X");
                else
                    printf ("0");
            }else
            {
                if (j % 2 == 0)
                    printf ("0");
                else
                    printf ("X");
            }
        }
        printf ("\n");
    }
}
