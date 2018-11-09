#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "metiter.h"

void D1_neg(double **mat, int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j!=i)
                mat[i][j] = 0;
            else
                mat[i][j] = 1/mat[i][j];
        }
    }
}

void L_plus_U(double **mat, int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==i)
                mat[i][j] = 0;
        }
    }
}


void v_sub(int n, double* a, double* b, double* c) 
{
  int i;
  for (i = 0; i < n; i++) 
  {
    c[i] = a[i] - b[i];
  }
}

void v_copy(int n, double* src, double* dst) 
{
  int i;
  for (i = 0; i < n; i++) 
    dst[i] = src[i];
}

void copy_mat(int n, double **A, double **copy)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            copy[i][j] = A[i][j];
        }
    }
}

void multmv (int m, int n, double** A, double* v, double* w)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		w[i]=0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			w[i]+=A[i][j]*v[j];
		}
	}

}

void matlibera (int m, double** A)
{
	int i;
	for(i=0;i<m;i++)
	{
		vetlibera(A[i]);
	}
}

double** matcria (int m, int n)
{
	int i;
	double **mat = (double **)malloc(m * sizeof(double*));
    	for (i=0; i<m; i++)
         	mat[i] = vetcria(n);
	return mat;
}


double norma2 (int n, double* v)
{
	int i;
	double sum = 0;

	for(i=0;i<n;i++)
	{
		sum += v[i]*v[i];
	}

	return sqrt(sum);
}

void printvec(double *vec,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("v[%d] = %f\n", i,vec[i]);
	}
}

void printmat(int m, int n, double **mat)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("mat[%d][%d] = %f\t",i,j,mat[i][j]);
			if(j==n-1)
			{
				printf("\n");
			}
		}
	}

}

void vetlibera (double* v)
{
	free(v);
}


double* vetcria (int n)
{
	double *vec = (double*)malloc(sizeof(double)*n);
	return vec;
}

int Jacobi (int n, double** A, double* b, double* x, double tol)
{
    double n2;
    double *y = (double*)malloc(sizeof(double)*n);
    double **D_minus = matcria(n,n);
    double **LpU = matcria(n,n);
    double *lpux = (double*)malloc(sizeof(double)*n);
    double *b_lpux = (double*)malloc(sizeof(double)*n);
    double *xn = (double*)malloc(sizeof(double)*n);
    double *dif = (double*)malloc(sizeof(double)*n);

    int check = 2;
    int iter = 0;

    copy_mat(n, A, D_minus);
    D1_neg(D_minus, n);
    
    copy_mat(n, A, LpU);
    L_plus_U(LpU,n);


    while(check)
    {
        // i'm using lpux vector in every equation for the sake of saving space
        iter++;
        multmv(n, n, LpU, x, lpux);
        v_sub(n, b, lpux, b_lpux);
        multmv(n, n, D_minus, b_lpux, xn);
        
        v_sub(n, x, xn, dif);
        n2 = norma2(n, dif);
        if(n2<tol)
            check--;
        v_copy(n, xn, x);
    }

    matlibera(n, D_minus);
    matlibera(n, LpU);
    free(lpux);
    free(b_lpux);
    free(xn);
    free(dif);

    return iter;
}

int GaussSeidel (int n, double** A, double* b, double* x, double tol)
{
    return SOR(n, A, b, x, tol, 1);
}


int SOR (int n, double** A, double* b, double* x, double tol, double w)
{
    int iter = 0;
    int i, j;

    double *xn = (double*)malloc(sizeof(double)*n);
    double *xdif = (double*)malloc(sizeof(double)*n);
    double sumu, suml, nor;

    nor = tol + 1;

    while (nor > tol)
    {
        iter++;
        // sumu -> U * x[k]
        // suml -> L * x[k+1]
        for (i = 0; i < n; i++)
        {
            sumu = 0;
            suml = 0;
            for (j = 0; j < n; j++)
            {
                if (j < i)
                suml += A[i][j] * xn[j];
                else if (j > i)
                sumu += A[i][j] * x[j];
            }

            xn[i] = (1.0 - w) * x[i] + w/A[i][i] * (b[i] - sumu - suml);
        }

        v_sub(n, x, xn, xdif);
        nor = norma2(n, xdif);

        v_copy(n, xn, x);
    }

    free(xn);
    free(xdif);

    return iter;
}
