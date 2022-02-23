#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    double a = 10;
    double b = 20;
    double cookie;
    double* pt = &b;

    cookie = a;
    a = *pt;
    b = cookie;


    printf ("a = %lf  \n", a);
    printf ("b = %lf    ", b);

    return 0;
}
