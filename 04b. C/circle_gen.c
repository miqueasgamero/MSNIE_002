#include <stdio.h>
#include <math.h>

//SOURCE
//https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm

float * genUnitCircle() {
   /* 
   Salida: se espera de la función retornar un puntero
   a un arreglo que contiene los 101 decimales espaciados
   por π/50 en el intervalo (0, 2π) 
   */
  
   //Definición estática para poder volver la dirección en memoria
   static float circle[100];
   int i;
   
   //Genera los 101 valores del intervalo
   for ( i = 0; i <= 100; i++) {
      circle[i] = i* (2 * M_PI)/100;
   }
   return circle;
}