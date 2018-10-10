#include <stdio.h> 
#include <math.h>
#include "deri_int.h"
#define PI 3.1413

double func(double x)
{
    return cos(x)-2*sin(x);
}

double dfunc(double x)
{
    return (-2*cos(x) - sin(x));
}



int main ()
{
    double h_optimal;

    h_optimal = h_otimo(func, dfunc, 1);
    printf("\nh otimo = %.16g\nderivada segunda ordem = %.16g\nderivada de fato = %.16g\n\n",
    h_optimal, derivada(func,1,h_optimal), dfunc(1));
    
    return 0;
}