function [root] = bisection(p, l, u, in_error, max_iter)
%__________________________________________________________________________
%La funcion recibe 5 variables:
%   -> pol: corresponde al polinomio.
%   -> l: corresponde al limite inferior o lower.
%   -> u: corresponde al limite superior o upper.
%   -> in_error: el error deseado por el usuario. 
%   -> max_iter: iteracion maxima.
%Retornara UNA sola raiz del polinomio. 
%__________________________________________________________________________

%Inicializacion de variables de control
iter = 0;
rel_error = 1;

%Control del plot
openfig('current_figure');
hold on

while (rel_error > in_error)&&(iter < max_iter)    
        r = (l+u)/2; 
        
        %Control del plot
        root_dot = plot(r, 0.5, 'o', 'LineWidth', 2, 'Color', 'b');
        str = ['Buscando la raíz, iteración número #', int2str(iter)];
        title(str);
        
        if (polyval(p, l) * polyval(p, r)) < 0
            if r ~= 0 
                rel_error = abs((r - u)/r);
            end
            u = r;
        elseif (polyval(p, l) * polyval(p, r)) > 0 
            if r~=0 
                rel_error = abs((r - l)/r);
            end
            l = r;
        else 
            rel_error = 0;
        end
        pause(0.5);
        delete(root_dot);
        iter = iter + 1; 
end
root = r;

%Control del plot
hold off
close all;