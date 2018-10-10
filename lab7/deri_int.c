#include <math.h>
#include <stdio.h>

double derivada (double (*f) (double x), double x, double h)
{
    double fxph, fxmh;
    fxph = f(x + h);
    fxmh = f(x-h);

    return (fxph - fxmh)/(2*h);
}


double h_otimo (double (*f) (double x), double (*fl) (double x), double x)
{
    int i;
    double h = 1;
    double derivate = 0;
    double error = 0;
    double realderivate = fl(x);
    double min_error;
    double h_otimo;
    for(i=1;i<13;i++)
    {
        h /= 10;
        derivate = derivada(f, x, h);
        error = fabs(derivate - realderivate);
        if(i == 1)
            min_error = error;
        else if(error < min_error)
        {
            // printf("\nerro antigo = %.16g\n erro novo = %.16g\nh antigo = %.16g\nh novo = %.16g\n", min_error, error, h_otimo, h);
            min_error = error;
            h_otimo = h;
        }
    }
    return h_otimo;
}