#include <stdio.h>
#include <math.h>
#include <string.h>

void genLissajousFigures(float A, float a, float B, float b, float delta);

void main(){
    float A,a,B,b,delta;
    char pi_place[2];
    const char pi[2] = "pi";

    delta = 1; 

    printf("Ingresa los valores de A, a, B, b y ẟ respectivamente\n");
    printf("Si el valor de ẟ comprende π agrege \"pi\" separado un espacio o debajo\n");
    printf("A:"); scanf("%f", &A);
    printf("a:"); scanf("%f", &a);
    printf("B:"); scanf("%f", &B);
    printf("b:"); scanf("%f", &b);
    printf("ẟ:"); scanf("%f %s", &delta, pi_place);
    
    //printf("Delta %1.10f \n", delta);
    if (strstr(pi_place, pi) != NULL)  {
        delta = delta * M_PI;
        //printf("Delta %1.10f \n", delta);
        //printf("Pi %1.10f \n", M_PI);
    }
    printf("El programa generó un archivo .csv\n");

    genLissajousFigures(A, a, B, b, delta);
}