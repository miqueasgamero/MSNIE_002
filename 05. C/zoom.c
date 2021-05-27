#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k=5; //VARIABLE GLOBAL????

void zoom(float mat [128][128],float mat2[128*k][128*k],int k);

void main(){

    int i,j;
    float escenario[128][128]; 
    float escenario2[128*k][128*k]; 

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
                //printf("El aux_float [%d,%d] guarda: %f \n",i,j, aux_float);
                
            }
            //printf("\n");
        }

        //Se muestra que la matriz fue correctamente cargada
        // for (i = 0; i < 128; i++){
        //     for(j = 0; j < 128; j++){
        //         printf("El escenario[%d][%d] %f\n",i,j, escenario[i][j]);
        //     }
        //     printf("\n");
        // }

        fclose(arch);
        zoom(escenario, escenario2 ,5);

        //Se abre otro archivo de texto para guardar la matriz una vez que se le aplico el zoom
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
        }
}

//Función que realiza el escalado
void zoom(float mat [128][128],float mat2[128*k][128*k],int k){
   float  mataux[k*128][k*128];
   int c,xx,xxx,cc,ck,j,i;
   
    xx=128;
    for (i=0;i<128;i++){
        cc=0; 
        for (j=0;j<128;j++){
            for (c=0;c<k;c++){ 
                mataux [i][cc+c]= mat [i][j] ;
            } 
                cc=cc+k; 
        }
    }
    xxx=128*k ;
    for (i=0;i<128*k;i++){
        cc=i+(k-1)*(i-1); 
        for (ck=0;ck<k;ck++) {
            for (j=0;j<128*k;j++){
                mat2[cc+ck][j]=mat[i][j]; 
            }
        }
    }
}