#include <stdio.h>
#include <math.h>
#include "matriz.h"

#define PI 3.14159265358979323846

void Chebyshev (int n, double a, double b, double* xi)
{
	double p = (b - a) / 2, c = (a + b) / 2;
	int i = 0, beta = 1;
	double d = 2 * n;

	for(i = 0; i < n; i++) 
    {
		xi[i] = p * cos( (beta * PI) / d ) + c;
		beta += 2;
	}
}

void NewtonCoef (int n, double* xi, double (*f) (double), double* bi)
{
    int i,j;

    double **matrix = matcria(n,n);

	for(i = 0; i < n; i++) 
	{
		for(j = i; j >= 0; j--) 
		{
			if(i == j) 
				matrix[j][i] = f(xi[i]);
			else 
				matrix[j][i] = (matrix[j + 1][i] - matrix[j][i - 1]) / (xi[i] - xi[j]);
		}

		bi[i] = matrix[0][i];
	}

	matlibera(n,matrix);    

}


double NewtonAval (int n, double* xi, double* bi, double x)
{
	int i;
	double res = bi[0];
	double cache = 1;

	for(i = 1; i < n; i++) 
	{
		cache *= (x - xi[i - 1]);
		res += bi[i] * cache;
	}

	return res;
}


