#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

//SOURCES
//https://austinrepp.com/how-to-write-to-a-csv-file-in-c/
//https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program
//https://austinrepp.com/how-to-write-to-a-csv-file-in-c/

float * genUnitCircle(); 
void genLissajousFigures(float A, float a, float B, float b, float delta);

void genLissajousFigures(float A, float a, float B, float b, float delta){
   /* 
   Parámetros de entrada:
      ---> A: amplitud de la figura A
      ---> a: frecuencia de la figura A
      ---> B: amplitud de la figura B
      ---> b: frecuencia de la figura B
      ---> delta: angulo de desfase
   Salida: se espera de la función que genere un archivo .txt en disco con 
   101 valores para la figura A y 101 valores para la figura B obedeciendo
   las relaciones matemáticas impuestas por las Curvas de Lissajous. 
   */
  
   FILE * fpointer;
   char fileName[100];
   int i;
   float * circle;

   time_t timer;
   char buffer[26], line[50];
   struct tm* tm_info;
   time(&timer);
   tm_info = localtime(&timer);

   //Generación del nombre para exportar
   strcpy(fileName, "Lissajous Figure ");
   strftime(buffer, 26, "%d-%m-%y %H-%M-%S", tm_info);
   strcat(fileName, buffer);
   strcat(fileName, ".txt");

   //Creación del archivo con permiso de escribir
   fpointer = fopen(fileName, "w+");   

   //Invocación a la generación del círculo
   circle = genUnitCircle();

   //Escritura en el archivo .txt de los valores de cada figura
   for (i = 0; i <= 100; i++) {
      printf("x(t=%d) = %f \n", i, A * sin(a * circle[i] + delta));
      fprintf(fpointer, "%3.4f \n", A * sin(a * circle[i] + delta));    
   }
   for (i = 0; i <= 100; i++) {
      fprintf(fpointer, "%3.4f \n ", B * sin(b * circle[i]));    
   }
}