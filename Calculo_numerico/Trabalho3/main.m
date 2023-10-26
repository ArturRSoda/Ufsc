dom = [0 pi/2]

coef = [
		(pi*sqrt(2))/8
		(sqrt(2)*(4-pi))/8
		-(sqrt(2)*(8+pi))/16
		-(sqrt(2)*(12-pi))/96
		-(sqrt(2)*(8+pi))/2304
		-(sqrt(2)*(12-pi))/276480
	]
grau = length(coef)-1;

xi = (dom(1) + dom(2))/2

h = (dom(2) - dom(1))/100;
xp = dom(1):h:dom(2);

ye = xp .* cos(xp);
ya = valor_polinomio(xp, coef, xi);

erro_max = max(abs(ya - ye))

plot(xp, ye)
hold on
p = plot(xp, ya);
waitfor(p)
