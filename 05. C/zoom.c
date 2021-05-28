#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZOOM 3

//void zoom(float mat [128][128],float mat2[128 * ZOOM][128 * ZOOM]);
//void bilinear_interpolation(float original_img[128][128], float*zoomed_img[128 * ZOOM][128 * ZOOM]);
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

        for (i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                printf("%1.1f \t", original_img[i][j]);
            }
            printf("\n");
        }

        fclose(arch);
        printf("\n");
        printf("\n");
        printf("\n");

        for (i = 0; i < 128 * ZOOM; i++){
            for (j = 0; j < 128 * ZOOM; j   ++){
                for (u = 0; u < scale_i; u++){
                    for (v = 0; v < scale_i; v++){
                        zoomed_img[i][j+v] = (original_img[i][j+1] - original_img[i][j])*v + original_img[i][j];
                        //printf("%1.1f \t", zoomed_img[i][j+v]);
                        zoomed_img[i+1][j+v] = (original_img[i+1][j+1] - original_img[i+1][j])*v + original_img[i+1][j];
                        zoomed_img[i + u][j + v] = (1-u)*(1-v)*original_img[i][j] - (1-u)*v*original_img[i][j+1] + u*(1-v)*original_img[i+1][j] + u*v*original_img[i+1][j+1];
                        printf("%1.1f \t", zoomed_img[i + u][j+v]);
                    }
                }            
            } 
        }
    }
}
        /*//Se abre otro archivo de texto para guardar la matriz una vez que se le aplico el zoom
        printf("Especifique un archivo de destino");
        scanf("%s", s);
        
        arch2 = fopen(s,"w"); //Abriendo el archivo.txt
    
        // if (arch2 == NULL){
         //     fclose(arch2);                              -----------> OJO. Nunca va a haber apertura erronea porque lo estás creando!
        //     printf("¡Error de apertura del archivo!");
        // }

        for (i = 0; i < 128*k; i++){
            for(j = 0; j < 128*k; j++){
                fprintf(arch2,"%f ", escenario2[i][j]);
            }
            fprintf(arch2,"\n");
        }
        printf("¡se ha realizado la tarea!");
        fclose(arch2);
        }*/
//    }
//}

//Función que realiza el escalado

//https://www.ijser.org/researchpaper/Adaptive-Approach-for-Zooming-Images-Using-Bilinear-Interpolation-Technique.pdf


/*void zoom(float * mat[128][128], float * mat2[640][640]){

   float  mataux[128 * ZOOM][128 * ZOOM];
   int c, xx, xxx, cc, ck, i, j;
   
   xx=128;

    for (i=0;i<128;i++){
        cc=0; 
        for (j=0;j<128;j++){
            for (c=0; c < ZOOM;c++){ 
                mataux [i][cc+c]= mat[i][j] ;
            } 
            cc = cc + ZOOM; 
        }
    }

    xxx=128 * ZOOM;

    for (i=0;i<(128* ZOOM);i++){

        cc = i + (ZOOM-1) * (i-1); 

        for (ck=0; ck < ZOOM;ck++) {
            for (j=0; j < (128*ZOOM);j++){
                mat2[cc+ck][j]=mat[i][j]; 
            }
        }
    }
}*/