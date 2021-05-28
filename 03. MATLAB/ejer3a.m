%se cargan los datos en la matriz A
A=vertcat(importdata('datalog1'),importdata('datalog2'),importdata('datalog3'));
T=(1:size(A,1));            %matriz tiempo
T=T*0.001;
T(:);

nc=1;
j=1;
ni=zeros(1,8); %inicializar ni

for i=2:(size(A)-1)
    if  or (((A(i)<=0) & (A(i+1)>0)),((A(i)>=0) & ( A(i+1)<0)))     %se cuentan el numero de cambios de signo
        nc=nc+1;
        if nc==43*j
            ni(j)=i;
            ni(8)=ni(8)+(size(A,1)-ni(8));
            if j>1 && j<9
                 nii(1)=ni(1);
                 nii(j)=ni(j)-ni(j-1);
            end                           
            j=j+1;
        end
            
    end
end

nc=nc/2 ;                  % se divide a la mitad para calcular el numero de ciclos
t=((1/50)/20)*size(A,1);   %tiempo total en tomar todas las mediciones (en segundos)
frec=nc/t


for i=1:8
    Tablafrec(i)=(43/2)/(nii(i)*0.001); %tabla de frecuencias promedio en intervalos de 43 semiciclos(8 intervalos)
end

ds=std(Tablafrec)           %desvio estandar

subplot(2,2,2),plot(T(1:end),A(1:end)),title('SEÑAL REAL')%grafica la señal ral segun los datos medidos
med=mean(Tablafrec)
Inter=(1:8);
prome(1:8)=med;

subplot(2,2,1),plot(Inter(1:8),prome(1:8)),title('DESVIACIÓN ESTANDAR')%grafica la frcuencia promedio
hold on
subplot(2,2,1),plot(Inter(1:8),Tablafrec(1:8),'--')%grafica la desviacion estandar junto la la frecuencia promedio
ejer3b
subplot(2,2,3),plot(TablaTiempo(1:4),Tprom(1:4)),title('TENSIÓN PROMEDIO');

