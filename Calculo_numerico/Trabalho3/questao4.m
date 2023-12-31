function x = questao4()
	x=[0.5   0.6   0.8   1; 
	   1   0.83266  0.666   0.5; 
	   0.4   0.6333   0.8666333   1.1];

	y=[0   0   0   0; 
	   0   -30   -60   -90; 
	   -35  -35  -35  -35];
   
	Nsegmentos=size(x,1)

	for n=1:Nsegmentos
		m = 4;
		x(n,m+1)=x(n,1);
		y(n,m+1)=y(n,1);	
		numpasso=100;
		h=1/numpasso;
		t=0;
		cx=3*(x(n,2)-x(n,1));bx=3*(x(n,3)-x(n,2))-cx;ax=(x(n,4)-x(n,1))-(cx+bx);
		cy=3*(y(n,2)-y(n,1));by=3*(y(n,3)-y(n,2))-cy;ay=(y(n,4)-y(n,1))-(cy+by);
		xmax=0;ymax=0;
		for i=1:numpasso+1
		   xx(n,i)=x(n,1)+t*(cx+t*(bx+t*ax));
		   yy(n,i)=y(n,1)+t*(cy+t*(by+t*ay));
		   t=t+h;
		end
	end

	#Marcadores
	plot(x(1,:),y(1,:),'*r','markersize',10,x(1,:),y(1,:),'--r');hold on;
	plot(x(2,:),y(2,:),'ob','markersize',10,x(2,:),y(2,:),'--b');hold on;
	 plot(x(3,:),y(3,:),'sg','markersize',10,x(3,:),y(3,:),'--g');hold on;
	 plot(xx(1,:),yy(1,:),'-r','linewidth',5)
	 plot(xx(2,:),yy(2,:),'-b','linewidth',5)
	 p = plot(xx(3,:),yy(3,:),'-g','linewidth',5)
	%xlim([-0.5 4])
	hold on;
	grid on;
end
