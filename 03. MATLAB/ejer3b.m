pks=findpeaks(A);%encuentra los maximos locales es decir los valores maximos positivos de la onda
promVp=mean(pks);%valor maximo promedio 
Vrms=promVp/sqrt(2)%valor de tensiòn eficaz
Tprom(1:4)=Vrms;
TablaTiempo=(1:4);
%subplot(2,2,3),plot(TablaTiempo=(1:4),Tprom(1:4);

