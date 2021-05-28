
function [variable]= texto()
%A=mat2gray(imread(uigetfile('.jpg')));
[nombre ruta]=uigetfile('.txt');
variable=load([ruta nombre]);
%figure;imshow(A);
figure;imshow(variable);

end
%dlmread