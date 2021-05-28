function [d]=defecto(a)
r=2;
x=[0:0.001:r]; 
y=sqrt(r.^2-x.^2); 
plot(x,y)
%Lo anterior dibuja cuarto de circunferencia de radio r
D=r/a; %Cantidad de divisiones 
aux=0;
m=[];
for k=1:(D-1) 
    y=sqrt(r.^2-(aux+a).^2);  %¡¡¡ESTA LINEA!!! es la única diferencia con el cálculo por exceso 
    line([aux aux],[0 y]) %Líneas constantes en x (alturas de los rectangulos) 
    line([aux aux+a],[y y]) %Líneas constantes en y (las bases de los rectangulos)
    line([aux+a aux+a],[0 y]) %Completa la barra 
    area=a*y; %Calcula área siendo "a" la base e "y" la altura
    m=[m, area]; %Guarda todas las áreas en una matriz
    aux=aux+a; 
    
end
d= sum(m); %Suma las áreas
%sprintf('Por defecto: %1.10f',d)