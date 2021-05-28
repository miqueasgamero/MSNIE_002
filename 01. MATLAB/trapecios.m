function [t]=trapecios(a)
r=2;
x=[0:0.001:r];
y=sqrt(abs(r.^2-x.^2));
plot(x,y)
%Lo anterior dibuja cuarto de circunferencia de radio r

D=r/a; 
aux=0;
m=[];
for k=1:D  
    y=sqrt(r.^2-aux.^2); %Calcula la coordenada y para graficar
    y0=sqrt(r.^2-aux.^2); 
    y1=sqrt(abs(r.^2-(aux+a).^2));
    line([aux aux],[0 y]) %Líneas constantes en x  
    line([aux aux+a],[y0 y1]) %"Techo" de los trapecios 
    area=a*((y0+y1)/2);  %Formula trapecios
    m=[m, area]; %Se guardan todas las areas en una matriz
    aux=aux+a;  %Se actualiza la variable auxiliar
end
t= sum(m); %Se suman todas las areas que guarda la matriz

%sprintf('Por trapecios: %1.10f',t)