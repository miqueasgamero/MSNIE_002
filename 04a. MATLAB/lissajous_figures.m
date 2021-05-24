%SOURCE
%https://www.mathworks.com/matlabcentral/mlc-downloads/downloads/submissions/23972/versions/22/previews/chebfun/examples/geom/html/Lissajous.html

function [x, y, t] = lissajous_figures(A, a, d, B, b)
    %Parámetros de entrada:
    %   ---> A: amplitud de la figura A.
    %   ---> a: frecuencia de la figura A.
    %   ---> d: ángulo de desfase entre figuras.
    %   ---> B: amplitud de la figura B.
    %   ---> b: frecuencia de la figura B.
    %Salida: Se espera de la función que devuelva un arreglo que contiene
    %101 valores comprendidos en el rango (0, 2π) para cada figura.
    
    t = linspace(0,2*pi, 101);
    x = A * sin(a*t + d);
    argumento_seno = 
    y = B * sin(b*t);