function X = Sistema_Tridiagonal(T, R, D, B)
	n = size(T, 1);	
	X = zeros(1, n);

	for (k = 1:(n-1))
		for (i = (k+1):n)
			aux = T(i)/R(i-1);
			T(i) = 0;
			R(i) = R(i) - D(i-1)*aux;
			B(i) = B(i) - B(i-1)*aux;
		end
	end

	X(n) = B(n)/R(n);

	for (i = (n-1):-1:1)
		X(i) = (B(i) - D(i)*X(i+1))/R(i);
	end

end
