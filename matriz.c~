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
	for(i=0;i<5;i++)
	{
		printf("v[%d] = %f\n", i,vec[i]);
	}
}

void printmat(int n, int m, double **mat)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("mat[%d][%d] = %f\t",i,j,mat[i][j]);
			if(j==4)
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
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			T[i][j] = A[j][i];
	}	
}

int main()
{
	int i,j,count;
	double *v = vetcria(5);
	double *w = vetcria(5);
	double **m = matcria(5,5);
	double **trans = matcria(5,5);
	
	for(i=0;i<5;i++)
	{
		v[i] = i+1;
		w[i] = v[i];
	}
	
	count = 1;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			m[i][j] = count++;
	}
		
	printvec(v,5);
	printf("produto escalar de v e w:\n");
	printf("%f\n",escalar(5,v,w));
	printf("norma2 de v:\n%f\n",norma2(5,v));
	vetlibera(v);
	printmat(5,5,m);
	transposta(5,5,m,trans);
	printf("transposta: \n");
	printmat(5,5,trans);
	matlibera(5,m);
	
	return 0;
}
