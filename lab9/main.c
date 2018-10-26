#include <math.h>
#include <stdio.h>
#include "ode.h"


int contador=0;
double f(double t, double y)
{
	contador++;
	return t*y + t*t*t;
}

double y(double t)
{
	return exp(t*t/2)-t*t-2;
}

int main()
{
    double yt1,erro;
	contador=0;

	// first
	printf("Para 0.01:\n\n");
	printf("Real: %lf\n\n",y(2.4));
	yt1 = Euler (0,2.4, 0.01, -1, f);
	erro=fabs(yt1-y(2.4))/yt1;
	printf("Euler: %lf\n",yt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	contador=0;
	yt1 = EulerAdapt (0, 2.4, 0.01, -1, f, 0.01);
	printf("Erro relativo Euler: %lf\n", erro);
	erro = fabs(yt1 - y(2.4)) / yt1;
	printf("Resultado Euler Adapt: %lf\n", yt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler Adapt: %lf\n\n",erro);
	contador=0;


	//second
	printf("Para 0.001:\n\n");
	printf("Real: %lf\n\n",y(2.4));
	yt1 = Euler (0,2.4, 0.001, -1, f);
	erro=fabs(yt1-y(2.4))/yt1;
	printf("Euler: %lf\n",yt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	contador=0;
	yt1 = EulerAdapt (0, 2.4, 0.001, -1, f, 0.001);
	printf("Erro relativo Euler: %lf\n", erro);
	erro = fabs(yt1 - y(2.4)) / yt1;
	printf("Resultado Euler Adapt: %lf\n", yt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler Adapt: %lf\n\n",erro);


	//third
	printf("Para 0.0001:\n\n");
	printf("Real: %lf\n\n",y(2.4));
	yt1 = Euler (0,2.4, 0.0001, -1, f);
	erro=fabs(yt1-y(2.4))/yt1;
	printf("Euler: %lf\n",yt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	contador=0;
	yt1 = EulerAdapt (0, 2.4, 0.0001, -1, f, 0.0001);
	printf("Erro relativo Euler: %lf\n", erro);
	erro = fabs(yt1 - y(2.4)) / yt1;
	printf("Resultado Euler Adapt: %lf\n", yt1);
	printf("Quantidade de avaliacoes da derivada: %d\n",contador);
	printf("Erro relativo Euler Adapt: %lf\n\n",erro);

	return 0;
}