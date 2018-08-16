#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* vetcria (int n)
{
	double *vec = (double*)malloc(sizeof(double)*n);
	return vec;
}

void vetlibera (double* v)
{
	free(v);
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

double escalar (int n, double* v, double* w)
{
	int i;
	double sum, temp = 0;
	for (i=0;i<n;i++)
	{
		temp = v[i]*w[i];
		sum += temp;
	}
	return sum;
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

double** matcria (int m, int n)
{
	int i;
	double **mat = (double **)malloc(m * sizeof(double*));
    	for (i=0; i<m; i++)
         	mat[i] = vetcria(n);
	return mat;
}

void matlibera (int m, double** A)
{
	int i;
	for(i=0;i<m;i++)
	{
		vetlibera(A[i]);
	}
}

void transposta (int m, int n, double** A, double** T)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			T[i][j] = A[j][i];
	}
}

int main()
{

	int i,j,count,n,m;
	double *v = vetcria(n);
	double *w = vetcria(n);
	n = 3;
	m = 2;
	double **mat = matcria(m,n);
	double **trans = matcria(n,m);

	//populando o vetor
	for(i=0;i<n;i++)
	{
		v[i] = i+1;
		w[i] = v[i];
	}

	//populando a matriz
	count = 1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			mat[i][j] = count++;
	}

	printf("imprimindo vetor vet:\n");
	printvec(v,n);
	printf("\nproduto escalar de v e w:\n");
	printf("%f\n",escalar(n,v,w));
	printf("\nnorma2 de v:\n%f\n",norma2(n,v));
	vetlibera(v);
	printf("\nimprimindo matriz mat:\n");
	printmat(m,n,mat);
	transposta(m,n,mat,trans);
	printf("\ntransposta: \n");
	printmat(n,m,trans);
	// matlibera(n,mat);

	return 0;
}
