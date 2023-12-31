function x = convergente(A);

	n = size(A, 1);

	convergente = 1;

	soma = 0;
	i = 1;
	for (j = (2:n))
		soma += abs(A(i,j));
	end
	if (abs(A(i,i)) >= soma)
		printf("|%d| >= |%d| V \n", A(i,i), soma)
	else
		printf("|%d| >= |%d| F \n", A(i,i), soma)
		convergente = 0;
	end

	for (i = 2:n)
		soma = 0;

		for (j = 1:(i-1))
			soma += abs(A(i,j));
		end

		for (j = (i+1):n)
			soma += abs(A(i,j));
		end

		if (abs(A(1,1)) >= soma)
			printf("|%d| >= |%d| V \n", A(i,i), soma)
		else
			printf("|%d| >= |%d| F \n", A(i,i), soma)
			convergente = 0;
		end
	end

	soma = 0;
	i = n;
	for (j = (1:(n-1)))
		soma += abs(A(i,j));
	end
	if (abs(A(i,i)) >= soma)
		printf("|%d| >= |%d| V \n", A(i,i), soma)
	else
		printf("|%d| >= |%d| F \n", A(i,i), soma)
		convergente = 0;
	end

	if (convergente == 1)
		disp("Sistema convergente, pois possui diagonal dominante")	
		disp("ou seja, o modo do A(i,i) e maior que o modulo da soma dos outros valores la linha")
	else
		disp("Sistema nao convergente, nao possui diagonal dominante")
	end

end
