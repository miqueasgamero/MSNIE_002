#include <stdio.h>
#include <math.h>

float * genUnitCircle() {
   static float circle[100];
   int i;
     
   for ( i = 0; i <= 100; i++) {
      circle[i] = i* (2 * M_PI)/100;
   }
   return circle;
}