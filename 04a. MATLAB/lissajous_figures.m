%https://www.mathworks.com/matlabcentral/mlc-downloads/downloads/submissions/23972/versions/22/previews/chebfun/examples/geom/html/Lissajous.html
function [x, y, t] = lissajous_figures(A, a, d, B, b)
    t = linspace(0,2*pi, 101);
    x = A * sin(a*t + d);
    y = B * sin(b*t);