#include<stdio.h>
#include<time.h>
void llenar_Matriz(int dim, int matriz[dim][dim]);
void mostrar_matriz(int dim, int matriz[dim][dim]);
void prom_matriz(int dim, float prom_matriz[dim][dim],int matriz[dim][dim]);
void mostrar_matriz1(int dim, float matriz[dim][dim]);

int main(){
 srand(time(NULL));


 int dim;
 printf("Ingrese la dimension: ");
 scanf("%d",&dim);

  int matriz[dim][dim];
  float matriz_prom[dim-2][dim-2];
 
 
 llenar_Matriz(dim,matriz);// esta parte llamo a la funcion
 
 mostrar_matriz(dim,matriz);// esta parte llamo a la funcion para que me muestre la matriz

 printf("\n");
 
 prom_matriz(dim, matriz_prom, matriz); //calcula el promedio de las contiguas

 mostrar_matriz1( dim, matriz_prom);//muestra matriz promedio
 return 0;
}
// esta funcion muestra la matriz generada
void mostrar_matriz(int dim, int matriz[dim][dim]){
 int i,j;
 for(i=0;i<dim;i++){
  for(j=0;j<dim;j++){
   printf("%d\t",matriz[i][j]);
  }
  printf("\n");
 }
}
void mostrar_matriz1(int dim, float matriz[dim-2][dim-2]){
 int i,j;
 for(i=0;i<dim-2;i++){
  for(j=0;j<dim-2;j++){
printf("%.3f\t",matriz[i][j]);
  }
  printf("\n");
 }
}


// esta funcion es para llenar la matriz al azar
void llenar_Matriz(int dim, int matriz[dim][dim]){
 int i,j;
 for(i=0;i<dim;i++){
  for(j=0;j<dim;j++){
   matriz[i][j]=1+rand() % 9;
  }
 }
}

// esta  funcion llena promedio de contiguas de la matriz creada al azar
void prom_matriz(int dim, float prom_matriz[dim-2][dim-2], int matriz[dim][dim]){
    int i,j;

     for(i=1;i<dim-1;i++){
        for(j=1;j<dim-1;j++){
            prom_matriz[i-1][j-1]=(matriz[i-1][j]+matriz[i+1][j]+matriz[i][j-1]+matriz[i][j+1]+matriz[i-1][j-1]
            +matriz[i+1][j+1]+matriz[i-1][j+1]+matriz[i+1][j-1])/8.0;
           
        }
    }
}