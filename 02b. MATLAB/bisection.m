function [r] = bisection(func, a, b, in_error, max_iter)
r = (a+b)/2;
rel_error = 1;
iter=0;
while (rel_error > in_error) && (iter < max_iter) 
    %Impone la condición de seguir hasta dado error.
    if func(r)<0 && func(a)<0 
        if r ~= 0
            rel_error = abs((r - a)/r);
        end
        a = r;
        fprintf("Extremo izquierdo: %f \t", a);
        fprintf("Extremo derecho: %f \t", b);
        fprintf("Error relativo: %f \t", rel_error);
    else
        if r ~= 0
            rel_error = abs((r - a)/r);
        end
        b = r;
        fprintf("Extremo izquierdo: %f \t", a);
        fprintf("Extremo derecho: %f \t", b);
        fprintf("Error relativo: %f \t", rel_error);
    end
    iter = iter + 1;
    r = (a+b)/2;
    fprintf("\n");
end