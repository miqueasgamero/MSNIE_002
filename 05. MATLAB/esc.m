 
clc ; clear all;close all;
prompt = 'The Zooming factor =  ';
k = input(prompt);
imag2=mat2gray(imread(uigetfile('.jpg')));

%guarda la matriz en el archivo de texto mat.txt
arch=fopen('mat.txt','wt');
for i=1:size(imag2,1)
    for j=1:size(imag2,2)
        fprintf(arch,'%f ',imag2(i,j))
        if j==size(imag2,2)
            fprintf(arch,'\n')
        end
    end
end

%algoritmo de zoomo por replicacion de pixeles
xx=size(imag2);
for i=1:xx(1)
    cc=0; 
    for j=1:xx(2)
        for c=1:k 
            imagZ(i,cc+c)=imag2(i,j) ;
        end 
            cc=cc+k; 
    end
end
xxx=size(imagZ) ;
for i=1:xxx(1)
    cc=i+(k-1)*(i-1); 
    for ck=0:k-1 
        for j=1:xxx(2)
            imagZF(cc+ck,j)=imagZ(i,j);
        end
    end
end
imagZF
figure;imshow(imag2);
figure;imshow(imagZF); 
