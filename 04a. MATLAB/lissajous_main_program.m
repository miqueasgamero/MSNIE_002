run = 1;
it = 1;

while run ~= 0
    arr(1) = input('Ingresar la amplitud A: ');
    arr(2) = input('Ingresar la frecuencia a: ');
    arr(4) = input('Ingresar la amplitud B: ');
    arr(5) = input('Ingresar la frecuencia b: ');
    arr(3) = input('Ingresar el corrimiento de fase δ: ');
    
    cp = 0; 
    if it ~= 1 
        cp = input('Si desea limpiar el gráfico anterior ingrese 1, de lo contrario ingrese 0: '); 
    end
       
    [x,y] = lissajous_figures(arr(1), arr(2), arr(3), arr(4), arr(5));
    animated_plot(x, y, arr(1), arr(4), cp, it);
    run = input('Si desea continuar ingrese un número distinto de  cero: ');
    it = it + 1;
    
end

clf;