#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZOOM 10

//SOURCE: https://www.ijser.org/researchpaper/Adaptive-Approach-for-Zooming-Images-Using-Bilinear-Interpolation-Technique.pdf

void bilinear_interpolation(float * original_img);

void main(){

    int i,j,u,v, scale_i, scale_j;
    float original_img[128][128]; 
    float zoomed_img[128 * ZOOM][128 * ZOOM]; 

    FILE *arch;
    FILE *arch2;
    char s[100];
    char aux_char[10];
    float aux_float;
    scale_i = ZOOM; scale_j = ZOOM;

    printf("Ingresar nombre del archivo: ");
    scanf("%s", s);

    arch = fopen(s,"r"); //Abriendo el archivo.txt
    
    if (arch == NULL){
        fclose(arch);
        printf("¡Error de apertura del archivo!");
    } else {
        //A continuación se carga la matriz con los valoress del archivo de texto en formato float
        for (i = 0; i < 128; i++){
            for(j = 0; j < 128; j++){
                fscanf(arch,"%s \n", aux_char);
                aux_float= strtof(aux_char, NULL);
                original_img[i][j] = aux_float;
            }
        }

        fclose(arch);

        for (i = 0; i < 128; i++){
            for (j = 0; j < 128; j++){
                zoomed_img[i * ZOOM][j * ZOOM] = original_img[i][j];
            }
        }

        for (i = 0; i < 128 * ZOOM - u; i+=ZOOM){
            for (j = 0; j < 128 * ZOOM - v; j+=ZOOM){
                for (u = 1; u < scale_i - 1; u++){
                    for (v = 1; v < scale_j - 1; v++){                        
                        // zoomed_img[i+u][j+v] =         
                        // zoomed_img[i][j+v] = (original_img[i][j+1] - original_img[i][j])*v + original_img[i][j];
                        // zoomed_img[i+1][j+v] = (original_img[i+1][j+1] - original_img[i+1][j])*v + original_img[i+1][j];
                        // zoomed_img[i + u][j + v] = (1-u)*(1-v)*original_img[i][j] - (1-u)*v*original_img[i][j+1] + u*(1-v)*original_img[i+1][j] + u*v*original_img[i+1][j+1];
                    }
                }            
            } 
        }
        printf("Especifique un archivo de destino: ");
        scanf("%s", s);
        printf("%s", s);    
        arch2 = fopen(s,"w"); //Abriendo el archivo.txt

        for (i = 0; i < 128 * ZOOM; i++){
            for(j = 0; j < 128 * ZOOM; j++){
                fprintf(arch2, "%f ", zoomed_img[i][j]);
            }
            fprintf(arch2,"\n");
        }
        fclose(arch2);
    }
}