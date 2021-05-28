function []=areas(c)
e=exceso(c);
d=defecto(c);
t=trapecios(c);
sprintf('El area por exceso es %1.10f,  \n por defecto es %1.10f,\n por trapecios es %1.10f.',e,d,t)
sprintf('referencia: %1.15f',pi)
Errores(e,d,t)





