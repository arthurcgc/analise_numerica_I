#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* vetcria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}
void vetlibera (double* v)
{
  free(v);
}
double** matcria (int m, int n)
{
  double** A = (double**) malloc(m*sizeof(double*));
  for (int i=0; i<m; ++i)
    A[i] = (double*) malloc(n*sizeof(double));
  return A;
}

void matlibera (int m, double** A)
{
  for (int i=0; i<m; ++i)
    free(A[i]);
  free(A);
}

void transposta (int m, int n, double** A, double** T)
{
  for (int i=0; i<m; ++i)
    for (int j=0; j<n; ++j)
      T[j][i] = A[i][j];
}
  
void multmv (int m, int n, double** A, double* v, double* w)
{
  for (int i=0; i<m; ++i) {
    w[i] = 0.0;
    for (int j=0; j<n; ++j)
      w[i] += A[i][j] * v[j];
  }
}
  
void multmm (int m, int n, int q, double** A, double** B, double** C)
{
  for (int i=0; i<m; ++i) {
    for (int k=0; k<q; ++k) {
      C[i][k] = 0.0;
      for (int j=0; j<n; ++j) 
        C[i][k] += A[i][j] * B[j][k];
    }
  }
}
  
void printmat(int m, int n, double **mat)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("mat[%d][%d] = %.5f\t",i,j,mat[i][j]);
			if(j==n-1)
			{
				printf("\n");
			}
		}
	}

}