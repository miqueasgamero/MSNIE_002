fprintf('Ingresa polinomios de la funcion transferencia como \n');
fprintf('   >[a0 a1 a2 a3] = a0 x^3 + a1 x^2 + a2 x + a3< \n');
fprintf(' siendo estos ultimos sus coeficientes. No omita ceros \n');
fprintf('_____________________________________________________________\n');
num = input('Ingresa numerador de la funcion transferencia: ');
fprintf('_____________________________________________________________\n');
den = input('Ingresa denominador de la funcion transferencia: ');
fprintf('_____________________________________________________________\n');
max_iter = input('Ingresa el valor máximo de iteración: ');
fprintf('_____________________________________________________________\n');
in_error = input('Ingresa el error máximo: ');
fprintf('_____________________________________________________________\n');
guess = input('Ingresa un valor de búsqueda inicial xi: ');
fprintf('_______________________________________________________\n');
bounds = input('Ingresa los extremos de la búsqueda como [inferior, superior]: ');
fprintf('_____________________________________________________________\n');

current_figure = figure;
interval=bounds(1):.1:bounds(2); 
plot(interval,polyval(den,interval),'Color', 'r', 'LineWidth', 2);
title("Método de Newton-Raphson.");
xlabel('Re[s]'); ylabel('Im[s]');
saveas(current_figure, 'current_figure_2');
close all;

factorized_num = factor(poly2sym(num));
factorized_den = factor(poly2sym(den));
syms x;
fprintf("Ceros de la función transferencia. \n");
for i=1:length(factorized_num)
    if has(factorized_num(i), x)
        root = newton_raphson(sym2poly(factorized_num(i)), max_iter, guess, in_error);
        fprintf("%1.1d es un cero\n", root);
        pause(1);
    end
end

current_figure = figure;
plot(interval,polyval(den,interval),'Color', 'r', 'LineWidth', 2);
title("Método de Newton-Raphson.");
xlabel('Re[s]'); ylabel('Im[s]');
saveas(current_figure, 'current_figure_2');
close all;

fprintf("Polos de la función transferencia. \n");
for i=1:length(factorized_den)
    if has(factorized_den(i), x)
        root = newton_raphson(sym2poly(factorized_den(i)),max_iter,  guess, in_error);
        fprintf("%1.1d es un polo\n", root);
        pause(1);
    end
end