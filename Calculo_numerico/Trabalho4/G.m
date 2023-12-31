function Y = G(X)
    Y(1) =  X(1) + X(2) + X(3);
    Y(2) =  X(1)*X(4) + X(2)*X(5) + X(3)*X(6);
    Y(3) =  X(1)*(X(4)^2) + X(2)*(X(5)^2) + X(3)*(X(6)^2);
    Y(4) =  X(1)*(X(4)^3) + X(2)*(X(5)^3) + X(3)*(X(6)^3);
    Y(5) =  X(1)*(X(4)^4) + X(2)*(X(5)^4) + X(3)*(X(6)^4);
    Y(6) =  X(1)*(X(4)^5) + X(2)*(X(5)^5) + X(3)*(X(6)^5);
end
