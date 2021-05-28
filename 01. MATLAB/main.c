#include <stdio.h>
#include <math.h>

//FUNCIONES:
void Areas(double c);
void Errores(double AreaE, double AreaD, double AreaT);
double Area_exceso(double c);
double Area_defecto(double c);
double Area_trapecios(double c);


int main () {
    double Ancho;
    int k; 
    for (k=1; k<=6; k++) {
        Ancho=(1/pow(10,k));
        Areas(Ancho); 
    }
    return 0;
}

 void Areas(double c) {
    double y,e,area,AreaE, AreaD, AreaT, UpperLimit;    
    int r=2;        //Declaramos el radio
    UpperLimit= r/c;        //Llamamos así a la cantidad de divisiones. Será el tope de los bucles
    printf("\n Cantidad de iteraciones: %1f \n",UpperLimit);


    //Imprimo resultados: 
    printf(" -------------------------------------------------------- \n");
    printf("\n  Pi: \n");
    printf("| Por exceso       | Por defecto       | Por Trapecios       | \n");
    printf("| %1.10f     | %1.10f      | %1.10f        | \n",Area_exceso(c),Area_defecto(c), Area_trapecios(c));
    Errores(Area_exceso(c), Area_defecto(c), Area_trapecios(c));

 }//FIN función Areas

 //Por exceso: 
double Area_exceso(double c){
    int k,r=2; 
    double e=0,UpperLimit,y,area, AreaE;
    UpperLimit=r/c; 
    for (k=0; k<UpperLimit ; k++ ) {
        y=sqrt(pow(r,2)-pow(e,2));      //Altura de la columna
        e=e+c;      //Salto
        area=c*y;       //Calculo el área de la columna actual
        AreaE=AreaE+area;       //Suma de areas 
    } //FIN BUCLE FOR
        return AreaE;
} //FIN función AREA_E

//Por defecto:
double Area_defecto(double c){
    double q, e=0, UpperLimit, area, AreaD,y;
    int r=2,k;
    UpperLimit=r/c; 
    //AreaD=0; //Este area no sé por qué trae un valor guardado, debo inicializar en 0.
    for (k=1; k<UpperLimit ; k++ ) {
        q=e+c;      
        y=sqrt((pow(r,2))-(pow((q),2)));
        e=e+c;
        area=c*y;
        AreaD=AreaD+area;
    }//FIN BUCLE FOR
    return AreaD;
}//FIN función AREA_D

//Por trapecios:
double Area_trapecios(double c){
    double y0,y1,AreaTT,aux, e, UpperLimit, area,q, AreaTotal;
    int r=2;
    int k;
    e=0;
    UpperLimit=r/c;     
    //AreaTotal=0; //No sé por qué este area trae un valor en 20 si no lo inicalizo en 0. 
    for (k=0; k<UpperLimit; k++) {
        q=e+c;
        aux=fabs((pow(r,2))-(pow((q),2)));
        y0=sqrt(fabs((pow(r,2))-(pow(e,2))));
        y1=sqrt(aux);
        area=c*(y0+y1)/2;
        AreaTotal=AreaTotal+area;
        e=e+c;
}
    return AreaTotal;
}//FIN función AREA_T

void Errores(double AreaE, double AreaD, double AreaT){
double pi = 3.1415926536;       //Vamos a trabajar Pi con estos decimales. 
/*Acá calculamos el error absoluto
Está dado por el valor real menos el medido
*/
double ErrorE, ErrorD,ErrorT;
ErrorE=fabs(pi-AreaE);      
ErrorD=fabs(pi-AreaD);
ErrorT=fabs(pi-AreaT);

printf("\n Errores absolutos: \n");
printf("| Error por exceso | Error por defecto | Error por trapecios | \n");
printf("| %1.10f     | %1.10f      | %1.10f        | \n",ErrorE,ErrorD, ErrorT);

/* Acá calculamos el error relativo portencual
El error relativo está dado por el cociente del error absoluto
y el valor real. El porcentual es eso mismo x 100.
*/
double ErrorEE, ErrorDD,ErrorTT;
ErrorEE=fabs(ErrorE/pi)*100;
ErrorDD=fabs(ErrorD/pi*100);
ErrorTT=fabs(ErrorT/pi*100);
printf("\n Errores portencuales: \n");
printf("| Error por exceso | Error por defecto | Error por trapecios | \n");
printf("| %1.10f     | %1.10f      | %1.10f        | \n",ErrorEE,ErrorDD, ErrorTT);


}//FIN FUNCIÓN ERRORES 

