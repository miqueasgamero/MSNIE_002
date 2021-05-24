function root = newton_raphson(pol, max_iter, in_guess, in_error)
%__________________________________________________________________________
%La funcion recibe 4 variables:
%   -> pol: corresponde al polinomio.
%   -> in_guess: la estimacion o adivinanza inicial para la raiz
%   -> in_error: el error deseado por el usuario. 
%   -> max_iter: iteracion maxima.
%Retornara UNA sola raiz del polinomio. 
%__________________________________________________________________________

%Variables necesarias
i = 1;
err(i) = 1;
rel_error = 1;

%Creacion de un arreglo que aloja desde la primer hasta la ultima
%"adivinanza"
x(1) = in_guess; 

%Variable que aloja la derivada del polinomio en forma estandar para los
%polinomios en MATLAB
pold = polyder(pol);

%Control del plot
interval=-10:.1:10; 
openfig('current_figure_2');
hold on
grid on;

while (i<max_iter)&&(rel_error>in_error)
    %Sentencias del método
    x(i+1)=x(i)-(polyval(pol, x(i)) /  polyval(pold, x(i)));
    root=x(i);
    
    %Control del plot
    root_dot = plot(root, 0.5, 'o', 'LineWidth', 2, 'Color', 'b');
    str = ['Buscando la raíz, iteración número #', int2str(i)];
    title(str);
    
    %Pendiente y ordenada al origen
    m = (polyval(pol, x(i))-x(i))/(0-x(i+1));
    n = polyval(pol, x(i))* m;
    %Linea conectando la recta estimada
    root_line = plot(interval, m*(interval) + n,'--', 'LineWidth', 0.5, 'Color', 'b');
    
    %Control del plot
    pause(1);
    delete(root_dot);
    delete(root_line);
    
    %Control del bucle
    rel_error=abs((x(i+1)-x(i))/x(i));
    i = i + 1;    
end
root = x(i);

%Control del plot
hold off
close all
