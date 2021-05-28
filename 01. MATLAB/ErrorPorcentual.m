function [Ep]=ErrorPorcentual(a)
%Esta función devuelve el error porcentual para un ancho "a", por trapecios. 
t=trapecios(a); 
ErrorT=abs(pi-t); %error absoluto
ErrorTT=(ErrorT/pi)*100;  %error relativo 
Ep=ErrorTT;
