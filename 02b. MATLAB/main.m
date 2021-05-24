fprintf('Ingresa polinomios de la funcion transferencia como \n');
fprintf('   >[a0 a1 a2 a3] = a0 x^3 + a1 x^2 + a2 x + a3< \n');
fprintf(' siendo estos ultimos sus coeficientes. No omita ceros \n');
fprintf('_____________________________________________________________\n');
num = input('Ingresa numerador de la funcion transferencia: \n');
den = input('Ingresa denominador de la funcion transferencia: \n');
fprintf('_____________________________________________________________\n');
bounds = input('Ingresa los extremos de la búsqueda como [inferior, superior]: \n');
max_iter = input('Ingresa la cantidad maxima de interaciones : \n');
in_error = input('Ingresa el error absoluto deseado: \n');
fprintf('_____________________________________________________________\n');

%Se factorizan los polinomios del numerador y denominados
factorized_num = factor(poly2sym(num));
factorized_den = factor(poly2sym(den));

%Sentencia necesaria para manipular la condicion de la sentencia if
syms x;

%El switch sirve como selector de opciones
option = input('Ingrese una opción \n (1)---> BISECCIÓN \n (2)---> FALSA POSICIÓN \n ---> Tu entrada: ');
switch (option)
    case 1 
        %__________________________________________________________________
        %Sentencias para graficar y exportar el polinomio original
        current_figure = figure;
        interval=bounds(1):.1:bounds(2);
        plot(interval,polyval(num,interval),'Color', 'r', 'LineWidth', 2);
        title('Búsqueda de raíces por bisección');
        xlabel('Re[s]'); ylabel('Im[s]');
        grid on
        saveas(current_figure, 'current_figure');
        close all;
        %__________________________________________________________________
        %Llamada a la función bisección
        fprintf("Ceros de la función transferencia.\n");
        for i=1:length(factorized_num) 
            %El if surge pues algunas factorizaciones no tienen terminos en 
            %funcion de x es por eso necesario cerciorarse que asi sea.
            if has(factorized_num(i), x)
                root = bisection(sym2poly(factorized_num(i)), bounds(1), bounds(2), in_error, max_iter);
                fprintf("%1.1d es un cero\n", root);
            end
        end
        
        %__________________________________________________________________
        %Sentencias para graficar y exportar el polinomio original
        current_figure = figure;
        plot(interval,polyval(den,interval),'Color', 'r', 'LineWidth', 2);
        title('Búsqueda de raíces por bisección');
        xlabel('Re[s]'); ylabel('Im[s]');
        grid on
        saveas(current_figure, 'current_figure');
        close all;
        %__________________________________________________________________
        %Llamada a la función bisección
        fprintf("Polos de la función transferencia. \n");
        for i=1:length(factorized_den)
            %El if surge pues algunas factorizaciones no tienen terminos en 
            %funcion de x es por eso necesario cerciorarse que asi sea.
            if has(factorized_den(i), x)
                root = bisection(sym2poly(factorized_den(i)), bounds(1), bounds(2), in_error, max_iter);
                fprintf("%1.1d es un polo\n", root);
            end
        end
    case 2
        
        current_figure = figure;
        interval=bounds(1):.1:bounds(2);
        plot(interval,polyval(num,interval),'Color', 'r', 'LineWidth', 2);
        title('Búsqueda de raíces por falsa posición');
        xlabel('Re[s]'); ylabel('Im[s]');
        grid on
        saveas(current_figure, 'current_figure');
        close all;
        fprintf("Ceros de la función transferencia.\n");
        for i=1:length(factorized_num)
            if has(factorized_num(i), x)
                root = false_position(sym2poly(factorized_num(i)), bounds(1), bounds(2), in_error, max_iter);
                fprintf("%1.1d es un cero\n", root);
            end
        end
        
        current_figure = figure;
        plot(interval,polyval(den,interval),'Color', 'r', 'LineWidth', 2);
        title('Búsqueda de raíces por bisección');
        xlabel('Re[s]'); ylabel('Im[s]');
        grid on
        saveas(current_figure, 'current_figure');
        close all;
        fprintf("Polos de la función transferencia. \n");
        for i=1:length(factorized_den)
            if has(factorized_den(i), x)
                root = false_position(sym2poly(factorized_num(i)), bounds(1), bounds(2), in_error, max_iter);
                fprintf("%1.1d es un polo\n", root);
            end
        end
end