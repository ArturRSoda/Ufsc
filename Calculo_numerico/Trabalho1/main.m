printf("Questão 1.a:\n")
printf("n = -20.125\n")
printf("v = (-1)^(1) * 2^(4) * (1.01000010000000000000000)\n")
printf("s = 1\n")
printf("e = 131\n")
printf("f = 01000010000000000000000\n")
printf("|1|10000011|01000010000000000000000|\n")
questao1(-20.125)

printf("\n")

printf("Questão 1.b:\n")
printf("n = -60.06\n")
printf("v = (-1)^(1) * 2^(5) * (1.11100000011110101110001)\n")
printf("s = 1\n")
printf("e = 132\n")
printf("f = 11100000011110101110001\n")
printf("|1|10000100|11100000011110101110001|\n")
questao1(-60.06);

printf("\n")

printf("Questão 2.1.a)\n")
[A, B] = questao21();

printf("Questão 2.1.b)\n")
X = questao21b(A, B)
residuo = sum((A*X) - B)

printf("\n")

printf("Questão 2.1.c)\n")
N = size(X, 1);
Operacoes_realizadas = (4*(N**3) + 9*(N**2) - N - 6)/6

printf("\n")

printf("Questão 2.1.a)\n")
questao22a(A)
printf("CONVERGE POR METODO ITERATIVO, pois o modulo de cada elemento da diagonal principal é maior ou igual a soma dos modulos dos demais elementos da respectiva linha. \n")




