function []=Errores(e,d,t)
disp('--------------------');
disp(' Errores absolutos: ');
ErrorE=abs(pi-e);
ErrorD=abs(pi-d);
ErrorT=abs(pi-t);
PorExceso=[' Por exceso: ',num2str(ErrorE)];
disp(PorExceso);
PorDefecto=['Por defecto: ',num2str(ErrorD)];
disp(PorDefecto);
PorTrapecios=['Por trapecios: ',num2str(ErrorT)];
disp(PorTrapecios);
disp('--------------------');
disp('Errores porcentuales:');
ErrorEE=(ErrorE/pi)*100;
ErrorDD=(ErrorD/pi)*100;
ErrorTT=(ErrorT/pi)*100;
PorExceso=['Por exceso: ',num2str(ErrorEE)];
disp(PorExceso);
PorDefecto=['Por defecto: ',num2str(ErrorDD)];
disp(PorDefecto);
PorTrapecios=['Por trapecios: ',num2str(ErrorTT)];
disp(PorTrapecios);