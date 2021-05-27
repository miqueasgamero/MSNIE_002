#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZOOM 5

void zoom(float mat [128][128],float mat2[128 * ZOOM][128 * ZOOM]);

void main(){

    int i,j;
    static float escenario[128][128]; 
    static float escenario2[128 * ZOOM][128 * ZOOM]; 

    FILE *arch;
    FILE *arch2;
    char s[100];
    char aux_char[10];
    float aux_float;

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
                escenario[i][j] = aux_float;
            }
        }

        fclose(arch);
        //_____________________________________________________
        zoom(& escenario, & escenario2);

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
    }
}

//Función que realiza el escalado
void zoom(float * mat[128][128], float * mat2[640][640]){

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
}