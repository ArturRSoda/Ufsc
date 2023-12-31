format long

f_y1 = @(x,y1,y2,y3) y2
f_y2 = @(x,y1,y2,y3) y3
f_y3 = @(x,y1,y2,y3) -(1/2)*y1.*y2

a = 0; b = 10;
x(1) = 0;
y1(1) = 0;
y2(1) = 0;
y3(1) = 0.2;

% Vamos criar uma função Runge-Kutta de 4ª ordem para resolver 3 equações diferenciais de 1ª ordem

n = 64 #para erro de y1 menor que 1e-6
[x, y1, y2, y3] = f_runge_kutta4_3EDOs(x, y1, y2, y3, f_y1, f_y2, f_y3, a, b, n);
[x_e, y1_e, y2_e, y3_e] = f_runge_kutta4_3EDOs(x, y1, y2, y3, f_y1, f_y2, f_y3, a, b, 2*n);

x

erro_estimado_y1 = max(abs(y1 - y1_e(1 : 2 : 2*n+1)))
erro_estimado_y2 = max(abs(y2 - y2_e(1 : 2 : 2*n+1)))
erro_estimado_y3 = max(abs(y3 - y3_e(1 : 2 : 2*n+1)))

p = plot(x, y1, "-r", x, y2, "-g", x, y3, "-b");
legenda = legend("y1", "y2", "y3");
legend(legenda, "location", "northwest")
grid on
waitfor(p)
