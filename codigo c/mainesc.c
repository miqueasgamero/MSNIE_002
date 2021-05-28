#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zoom(float mat [128][128],float mat2[128*5][128*5],int k);

void main(){
    int i,j;
    float escenario[128][128]; 

    float escenario2[128*5][128*5]; 

    FILE *arch;
    FILE *arch2;
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
//A continuacòn se carga la matriz con los valoress del archivo de texto en formato float
    for (i = 0; i < 128; i++){
        for(j = 0; j < 128; j++){
            fscanf(arch,"%s \n", aux_char);
            aux_float= strtof(aux_char, NULL);
            escenario[i][j] = aux_float;
            printf("El aux_float [%d,%d] guarda: %f \n",i,j, aux_float);
            
        }
        printf("\n");
    }


    i = 0;
    j = 0;
//se muesatra que la matriz fue correctamnte cargada
    for (i = 0; i < 128; i++){
        for(j = 0; j < 128; j++){
            printf("El escenario[%d][%d] %f\n",i,j, escenario[i][j]);
        }
        printf("\n");
    }



    fclose(arch);
   
    
zoom( escenario, escenario2,5);

//se abre otrao archivo de texto para guardar la matriz una vez que se le aplico el zoom
     printf("¿cual es su archivo de destino>>?");
    scanf("%s", s);
    
    arch2 = fopen(s,"w"); //Abriendo el archivo.txt
   

    if (arch2 == NULL){
        fclose(arch2);
        printf("¡Error de apertura del archivo!");
    }
    i=0;
    j=0;

     for (i = 0; i < 128*5; i++){
        for(j = 0; j < 128*5; j++){
            fprintf(arch2,"%f ", escenario2[i][j]);
        }
        fprintf(arch2,"\n");
    }
    printf("¡se ha realizado la tarea!");
    fclose(arch2);


}
// funcion que realiza el escalado
void zoom(float mat [128][128],float mat2[128*5][128*5],int k){
   float  mataux[128][5*128];
   int c,xx,xxx,cc,ck,j,i;
c=1;
  
   
    xx=128;//tamaño de filas de la matriz original
for (i=0;i<128;i++){
    cc=0; 
    for (j=0;j<128;j++){
        for (c=1;c=k;c++){ 
            mataux [i][(cc+c)-1]= mat [i][j] ;// se carga la matriz auxiliar de maner que por cada fila carga k valores consecutivos iguales en las columnas
        } 
            cc=cc+k; 
    }
}
i=0;
j=0;
ck=0;
xxx=128*k ;
for (i=0;i<128;i++){
    cc=i+(k-1)*(i-1); // cc va de 5 en 5
    if (cc==-4){
        cc=0;
    }
    for (ck=0;ck<k;ck++) {
        for (j=0;j<128*k;j++){
            mat2[(cc+ck)][j]=mataux[i][j]; //se carga la matriz con valores de manera por cada columna carga k valores iguales consecutivos en las filas 
        }
    }
}

}