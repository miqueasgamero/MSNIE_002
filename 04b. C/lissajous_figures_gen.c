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
   FILE * fpointer;
   char fileName[100];
   int i;
   float * circle;

   time_t timer;
   char buffer[26], line[50];
   struct tm* tm_info;

   time(&timer);
   tm_info = localtime(&timer);

   strcpy(fileName, "Lissajous Figure ");
   strftime(buffer, 26, "%d-%m-%y %H-%M-%S", tm_info);
   strcat(fileName, buffer);
   strcat(fileName, ".txt");

   fpointer = fopen(fileName, "w+");   

   circle = genUnitCircle();

   for (i = 0; i <= 100; i++) {
      printf("Argumento del seno es: %f \n", a * circle[i] + delta);
      printf("x(t=%d) = %f \n", i, A * sin(a * circle[i] + delta));
      fprintf(fpointer, "%3.4f \n", A * sin(a * circle[i] + delta));    
   }
   for (i = 0; i <= 100; i++) {
      fprintf(fpointer, "%3.4f \n ", B * sin(b * circle[i]));    
   }
}