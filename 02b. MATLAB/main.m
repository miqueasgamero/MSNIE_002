fprintf('Ingresa polinomios de la funcion transferencia como \n');
fprintf('   >[a0 a1 a2 a3] = a0 x^3 + a1 x^2 + a2 x + a3< \n');
fprintf(' siendo estos ultimos sus coeficientes. No omita ceros \n');
fprintf('_______________________________________________________\n');
num = input('Ingresa numerador de la funcion transferencia: ');
fprintf('_______________________________________________________\n');
den = input('Ingresa denominador de la funcion transferencia: ');
fprintf('_______________________________________________________\n');

current_figure = figure;
interval=-100:.1:100; %Aca va el intervalo que ingrese el usuario.
plot(interval,polyval(num,interval));
saveas(current_figure, 'current_figure');
close all;

%fplot(@(x) polyval(num,x), [-50 50], 'LineWidth', 2);

factorized_num = factor(poly2sym(num));
factorized_den = factor(poly2sym(den));
syms x;
for i=1:length(factorized_num)
    root = bisection_v3(sym2poly(factorized_num(i)), -100, 100, 0.01, 600);
    if has(factorized_num(i), x)
        fprintf("Raiz %1.1d\n", root);
        pause(10);
    end
end
hold off
for i=1:length(factorized_den)
    root = bisection_v3(sym2poly(factorized_den(i)), -100, 100, 0.01, 600);
    if has(factorized_den(i), x)
        fprintf("Raiz %1.1d\n", root);
    end
end