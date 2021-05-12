function [] = animated_plot(x, y, A, B, cp, it)
    if cp == 1 
        clf;
    else 
    end
    curve = animatedline('Color', [rand, rand, rand], 'LineStyle', '-.');
    set(gca, 'XLim',[-A A], 'YLim', [-B B]);
    grid on;
    xlabel('x(t)') 
    ylabel('y(t)') 
    title(sprintf('Curvas de Lissajous. Ejecución #%2d', it))
    for iter=1:length(x)
        addpoints(curve, x(iter), y(iter));
        drawnow;
        pause(0.01);
    end