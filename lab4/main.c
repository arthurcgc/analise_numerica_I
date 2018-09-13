#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "interp.h"
#include "matriz.h"

#define PI 3.14159265358979323846

int n = 6;

int main(int argc, char const *argv[])
{
    double *xi,*bi;
    double a = 0, b = PI/2;

    xi = vetcria(n);
    bi = vetcria(n);

    int i;

    Chebyshev(n,a,b,xi);
    
    for(i = 0; i < n; i++)
    {
        printf("xi[%d] em [%f,%f] = %f\n",i, a, b, xi[i]);
    }
    
    NewtonCoef(n,xi,cos,bi);

    printf("\nCoeficientes do Polinômio Interpolante por Diferenças de Newton (n = %d):\n\n", n);
	for(i = 0; i < n; i++) 
    {
		printf("bi[%d] = %.16g\n", i, bi[i]);
	}

    return 0;
}
