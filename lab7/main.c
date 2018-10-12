#include <stdio.h> 
#include <math.h>
#include "integral.h"
#define PI 3.14159265358979323846

double func(double x)
{
    return cos(x)-2*sin(x);
}

double dfunc(double x)
{
    return (-2*cos(x) - sin(x));
}

double f1(double x)
{
    return x/sqrt((x*x)+9);
}

double f2(double x)
{
    return (x * x) * log(x);
}

double f3(double x)
{
    return x*x*sin(x);
}


int main ()
{
    double h_optimal;
    int n, a, b;
    double res_simpson;
    double res_pontomedio;
    printf("----testes derivada----\n");
    h_optimal = h_otimo(func, dfunc, 1);
    printf("\nh otimo = %.16g\nderivada segunda ordem = %.16g\nderivada de fato = %.16g\n\n",
    h_optimal, derivada(func,1,h_optimal), dfunc(1));
    
    printf("\n---------testes integral com n = 16--------\n\n\n");
    n = 16;

    a = 0; b = 4;
    res_simpson = simpson(f1, a, b, n);
    res_pontomedio = pontomedio(f1, a, b, n);
    printf("Simpson de f1 -> %.16g\n", res_simpson);
    printf("Ponto Medio de f1 -> %.16g\n", res_pontomedio);

    printf("\n\n");
    a = 1; b = 3;
    res_simpson = simpson(f2, a, b, n);
    res_pontomedio = pontomedio(f2, a, b, n);
    printf("Simpson de f2 -> %.16g\n", res_simpson);
    printf("Ponto Medio de f2 -> %.16g\n", res_pontomedio);


    printf("\n\n");
    a = 0; b = PI;
    res_simpson = simpson(f3, a, b, n);
    res_pontomedio = pontomedio(f3, a, b, n);
    printf("Simpson de f3 -> %.16g\n", res_simpson);
    printf("Ponto Medio de f3 -> %.16g\n", res_pontomedio);

    printf("\n---------testes integral com n = 32--------\n\n\n");
    n = 32;

    a = 0; b = 4;
    res_simpson = simpson(f1, a, b, n);
    res_pontomedio = pontomedio(f1, a, b, n);
    printf("Simpson de f1 -> %.16g\n", res_simpson);
    printf("Ponto Medio de f1 -> %.16g\n", res_pontomedio);

    printf("\n\n");
    a = 1; b = 3;
    res_simpson = simpson(f2, a, b, n);
    res_pontomedio = pontomedio(f2, a, b, n);
    printf("Simpson de f2 -> %.16g\n", res_simpson);
    printf("Ponto Medio de f2 -> %.16g\n", res_pontomedio);


    printf("\n\n");
    a = 0; b = PI;
    res_simpson = simpson(f3, a, b, n);
    res_pontomedio = pontomedio(f3, a, b, n);
    printf("Simpson de f3 -> %.16g\n", res_simpson);
    printf("Ponto Medio de f3 -> %.16g\n", res_pontomedio);



    return 0;
}
