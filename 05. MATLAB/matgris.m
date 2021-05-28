A=mat2gray(imread(uigetfile('.jpg')));
arch=fopen('mat.txt','wt');
for i=1:size(A,1)
    for j=1:size(A,2)
        fprintf(arch,'%f\n ',A(i,j))
        %if j==size(A,2)
         %   fprintf(arch,'\n')
        %end
    end
end
imshow(A);
fclose(arch);
%fscanf(abie,'%ft',size(A))