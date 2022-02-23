/**
* \file main.c
* \brief Programme de tests.
* \author Andreas Castello
* \version 0.1
* \date 04 decembre 2020
*
* Programme de test pour doxygen
*
*/
#ifndef __TYPES__
#define __TYPES__
/**
* \struct Point
* \brief Point en 2 dimensions.
*
* Une structure de test qui contient 2 champs !
*/
typedef struct
{
    int X;    /*!< TestX */
    int Y;    /*!< TestY */
}
Point;

#include <stdio.h>
#include <stdlib.h>
/**
* \struct Point2D
* \brief C'est juste la rue
*
* LA STRUCTURE POINT2D
*/
typedef struct str_Point2D
{
    double x; /*!< Le vraiX */
    double y; /*!< Le vraiY */
}
Point2D;

void printf_Point2D (Point2D p)
{
 printf ("Point 2D de coordonnees (%.3lf , %.3lf)\n", p.x, p.y);
}

int main()
{
    Point2D a = { 10, 20 };
    printf_Point2D (a);

    return 0;
}
