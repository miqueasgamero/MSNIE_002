function [e]=exceso(a)
r=2;
x=[0:0.001:r];  
y=sqrt(r.^2-x.^2); 
plot(x,y)
xlabel('x');
%Lo anterior dibuja cuarto de circunferencia de radio r  
D=r/a; %Cantidad de divisiones 
aux=0;
m=[];
for k=1:D
    y=sqrt(r.^2-aux.^2);
    line([aux aux],[0 y]) %Líneas constantes en x (alturas de los rectangulos) 
    line([aux aux+a],[y y]) %Líneas constantes en y (las bases de los rectángulos)
    line([aux+a aux+a],[0 y]) %Completa la parte de la  barra que se sale de la circunferencia
    area=a*y; %Calcula área siendo "a" la base e "y" la altura 
    m=[m, area]; %Guarda todas las áreas en una matriz
    aux=aux+a; %Actualiza la variable auxiliar
end
e= sum(m); %Suma todas las áreas y guarda en la variable e
%sprintf('Por exceso: %1.10f',e)
