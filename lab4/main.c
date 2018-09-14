#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>
#include "interp.h"
#include "matriz.h"

#define PI 3.14159265358979323846

int n = 6;

int main(int argc, char const *argv[])
{
    double *xi,*bi,x,nfact,err,error,res;
    double a = 0, b = PI/2;
    double base = b/10;

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

    nfact = 1;
	for(i = n; i > 0; i--) 
    {
		nfact *= i;
	}

    	for(i = 0; i < 10; i++) 
        {
	
		x = i * base;

		res = NewtonAval(n, xi, bi, x);

		printf("\ncos(%lf) interpolação =  %.16g\ncos(%lf) real = %.16g\n", x, fabs(res), x, cos(x));

		err = fabs(cos(x) - res);
		error = (pow( ((b - a)/2.0), n) / pow(2.0, n - 1)) * ( 1 / nfact ); 

        if(err<error)
		    printf("\nerror =  %.16g\n|real - obtido| = %.16g\n\n", error, err);
        else
            printf("erro maior do que o limite, rever código");
	}

    return 0;
}
