
% PRIMEIRO EXEMPLO

printf("PRIMEIRO EXEMPLO\n")

A = [1 2 1.5;
	-2 3 5;
	-5 10 3]

B = [-2;
	-3;
	-1]

determinante = det(A)

% X = inv(A) * B
% X = A\B

X = fgauss(A, B)
res = max(abs((A * X) - B))

printf("\n")

% SEGUNDO EXEMPLO

printf("SEGUNDO EXEMPLO\n")

A = [0 2 3;
	1.5 -1 4;
	3 -2 8]

B = [10;
	-1;
	-2]

determinante = det(A)

% X = inv(A) * B
% X = A\B

X = fgauss(A, B)
res = max(abs((A * X) - B))

printf("\n")

% TERCEIRO EXEMPLO

printf("TERCEIRO EXEMPLO\n")

A = [0 2 3;
	1.5 -1 4;
	3 -2 8]

B = [10;
	-1;
	-7]

determinante = det(A)

% X = inv(A) * B
% X = A\B

X = fgauss(A, B)
res = max(abs((A * X) - B))
