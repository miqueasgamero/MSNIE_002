function [root] = false_position(p, l, u, in_error, max_iter)
%__________________________________________________________________________
%La funcion recibe 5 variables:
%   -> pol: corresponde al polinomio.
%   -> l: corresponde al limite inferior o lower.
%   -> u: corresponde al limite superior o upper.
%   -> in_error: el error deseado por el usuario. 
%   -> max_iter: iteracion maxima.
%Retornara UNA sola raiz del polinomio. 
%__________________________________________________________________________

%Variables de control del bucle
iter = 0;
iter_u = 0; iter_l = 0;
rel_error = 1;

%Control del plot
openfig('current_figure');
hold on

while (rel_error > in_error)&&(iter < max_iter)    
    
    %Variables que alojan los polinomios evaluados en los extremos
    pl = polyval(p, l);
    pu = polyval(p, u);
    
    %Estimacion de la raiz
    r = u - pu * (l - u)/(pl - pu);     
    
    %Control del plot    
    root_dot = plot(r, 0.5, 'o', 'LineWidth', 2, 'Color', 'g');
    str = ['Buscando la raíz, iteración número #', int2str(iter)];
    title(str);
    
    %Control del bucle
    if (pl * pu) < 0
        rel_error = abs((r - u)/r);
        u = r;
        
        %Sentencias que ayudan a dar cuenta si una iteracion se repite mas
        %de una vez. Esto corresponde al algoritmo de falsa posicion
        %modificado u optimizado.
        iter_l = iter_l + 1;
        iter_u = 0;
        if iter_l > 2 
            pl = pl * 0.5;
        end
    elseif (pl * pu) > 0 
        rel_error = abs((r - l)/r);
        l = r;
        
        %Sentencias que ayudan a dar cuenta si una iteracion se repite mas
        %de una vez. Esto corresponde al algoritmo de falsa posicion
        %modificado u optimizado.
        iter_u = iter_u + 1;
        iter_l = 0;
        if iter_u > 2 
            pu = pu * 0.5;
        end
    else 
        rel_error = 0;
        break;
    end
    pause(1);
    iter = iter + 1; 
    delete(root_dot);
end
root = r;

%Control del plot
hold off
sclose all;