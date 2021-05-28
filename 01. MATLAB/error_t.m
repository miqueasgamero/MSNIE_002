function[D]=error_t(Ec)
a=pi;
Ep=ErrorPorcentual(a)
while Ep>Ec 
    a=a/2;
    Ep=ErrorPorcentual(a);
end 
D=2/a; %Cantidad de segmentos (radio sobre ancho)
t=trapecios(a); %el area real para el ancho obtenido
t2=pi-(pi*Ec)/100; %el area que se debería obtener teóricamente para el error ingresado
sprintf(' Con ancho obtenido a= %1.10f, \n se consiguió un error de Ep= %1.10f. \n Si bien, para el ancho obtenido el area por trapecios resulta %1.10f, \n con el error computado se logra un area de %1.10f. \n Por último, la cantidad de segmentos resulta D= %1.10f ',a,Ep,t,t2,D)

