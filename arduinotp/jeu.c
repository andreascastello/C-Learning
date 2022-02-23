#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>


int main (void)
 {

  int a = 16;
  int end = 0;
  int score;

  wiringPiSetupGpio ();
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (14, OUTPUT);
  pinMode (15, OUTPUT);
  pinMode (16, OUTPUT);
  pinMode (24, INPUT);


for (int i = 10; i <= 16; i++)
{
    digitalWrite (i, LOW);
}

do
{
    digitalWrite (a, LOW);
    switch (a)
    {
        case 10 :

            if(digitalRead (24) == 0)
            {
                digitalWrite (10, LOW);
                score += 1;
                printf ("Score = %d\n", score);
            }
            else{
                digitalWrite (10, HIGH);
                a = 15;
            }
            break;
        case 11 :

            if(digitalRead (24) == 0)
            {
                digitalWrite (11, LOW);
                score += 3;
                printf ("Score = %d\n", score);
            }
            else
            {
                digitalWrite (11, HIGH);
                a = 10;
            }break;
        case 12 :

            if(digitalRead (24) == 0)
            {
                digitalWrite (12, LOW);
                score += 4;
                printf ("Score = %d\n", score);
            }
            else
            {
                digitalWrite (12, HIGH);
                a= 11;
            }
            break;
        case 13 :
            if(digitalRead (24) == 0)
            {
                digitalWrite (13, LOW);
                score += 1;
                printf ("Score = %d\n", score);
            }
            else
            {
                digitalWrite (13, HIGH);
                a=12;
            }break;
        case 14 :
            if(digitalRead (24) == 0)
            {
                digitalWrite (14, LOW);
                score += 3;
                printf ("Score = %d\n", score);
            }
            else
            {
                digitalWrite (14, HIGH);
                a=13;
            }break;
        case 15 :
            if(digitalRead (24) == 0)
            {
                digitalWrite (15, LOW);
                score += 3;
                printf ("Score = %d\n", score);
            }
            else
            {
            digitalWrite (15, HIGH);
            a=16;
            }break;
        case 16 :
            if(digitalRead (24) == 0)
            {
                digitalWrite (16, LOW);
                score += 5;
                printf ("Score = %d\n", score);
            }
            else
            {
                digitalWrite (16, HIGH);
                a = 14;
            }break;
    }

    digitalWrite (a, LOW);
    sleep(1);
}
while(end == 0);
return 0;
 }
