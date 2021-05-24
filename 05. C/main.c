#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int i,j;
    float escenario[128][128];  
    FILE *arch;
    char s[100];
    char aux_char[10];
    float aux_float;

    printf("¿cual es su archivo>>?");
    scanf("%s", s);
    
    arch = fopen(s,"r"); //Abriendo el archivo.txt
    
    if (arch == NULL){
        fclose(arch);
        printf("¡Error de apertura del archivo!");
    }

    for (i = 0; i < 128; i++){
        for(j = 0; j < 128; j++){
            fscanf(arch,"%s \n", aux_char);
            aux_float = strtof(aux_char, NULL);
            printf("El aux_float [%d,%d] guarda: %f \n",i,j, aux_float);
            escenario[i][j] = aux_float;
        }
        printf("\n");
    }

    for (i = 0; i < 128; i++){
        for(j = 0; j < 128; j++){
            fscanf(arch,"%s \n", aux_char);
            aux_float = strtof(aux_char, NULL);
            //printf("El aux_float %f \n",i,j, aux_float);
            escenario[i][j] = aux_float;
        }
        //printf("\n");
    }
    i = 0;
    j = 0;

    for (i = 0; i < 128; i++){
        for(j = 0; j < 128; j++){
            printf("El escenario[%d][%d] %f\n",i,j, escenario[i][j]);
        }
        printf("\n");
    }



    fclose(arch);
    //https://www.tutorialspoint.com/system-function-in-c-cplusplus#:~:text=The%20system()%20function%20is,included%20to%20call%20this%20function.
}