#include "gradconj.h"
#include "matriz.h"
#include <math.h>
#include <stdlib.h>


void sub_vec(int n, double *v1, double *v2, double *r)
{
    int i;

    for(i=0;i<n;i++)
    {
        r[i] = v1[i] - v2[i];
    }
}

int GradConj (int n, double** A, double* b, double* x, double tol)
{
    int x0 = 0;
    int k,i,j,count;
    double alpha, betha;
    double N,D;
    double *Ax = vetcria(n);
    double *r = vetcria(n);
    double *d = vetcria(n);
    double *temp = vetcria(n);
    double *rk = vetcria(n);
    double **A_temp = matcria(n,n);

    multmv(n, n, A, x, Ax);
    sub_vec(n, b, Ax, r);
    sub_vec(n, b, Ax, d);

    count = 0;
    for(k=0;k<n;k++)
    {
        if (tol > norma2(n, r))
            break;

        N = escalar(n, r, r);
        multmv(n, n, A, d, temp);
        D = escalar(n, d, temp);
        
        alpha = N/D;

        for(i=0;i<n;i++)
            x[i] = x[i] + alpha*d[i];
        

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                A_temp[i][j] = A[i][j] * alpha;
        }

        multmv(n, n, A_temp, d, temp);
        for (i = 0; i < n; i++)
            rk[i] = r[i] - temp[i];

        betha = (escalar(n, rk, rk)) / (escalar(n, r, r));

        for (i = 0; i < n; i++)
        {
            d[i] = rk[i] + betha*d[i];
            r[i] = rk[i];
        }
        count++;
    }

    return count;
}


double **precondicionador(int n, double ** A)
{
	int i, j;
	double **M;
	M = matcria(n, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			M[i][j] = 0;
			if (i == j)
				M[i][j] = 1 / A[i][j];
		}
	}
	return M;

}

int GradConjJacobi (int n, double** A, double* b, double* x, double tol)
{
    int i, j, k, cont;
	double aux = 0;
	double *r;
	double *rk;
	double *d,*z,*zk;
	double *Ax;
	double alfa = 0;
	double beta;
	double *Aux;
	double **AuxM;
	double **M1;
	r = vetcria(n);
	rk = vetcria(n);
	d = vetcria(n);
	z = vetcria(n);
	zk = vetcria(n);
	Ax = vetcria(n);
	Aux = vetcria(n);
	M1 = precondicionador(n,A);
	AuxM = matcria(n, n);
	multmv(n, n, A, x, Ax);
	cont = 0;

	for (i = 0; i<n; i++)
		r[i] = b[i] - Ax[i];
        
	multmv(n, n, M1, r, d);
	multmv(n, n, M1, r, z);

	for (k = 0;k < n;k++)
	{
		if (tol > norma2(n, r))
			break;

		alfa = escalar(n, r, z);
		multmv(n, n, A, d, Aux);
		aux = escalar(n, d, Aux);
		alfa /= aux;

		for (i = 0; i < n; i++)
			x[i] = x[i] + alfa*d[i];

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				AuxM[i][j] = A[i][j] * alfa;
		}

		multmv(n, n, AuxM, d, Aux);
        
		for (i = 0; i < n; i++)
			rk[i] = r[i] - Aux[i];
            
		multmv(n, n, M1, rk, zk);
		beta = escalar(n, rk, zk) / escalar(n, r, z);

		for (j = 0; j < n; j++)
			Aux[i] = beta*d[i];
            
		for (i = 0; i < n; i++)
		{
			d[i] = zk[i] + beta*d[i];;
			r[i] = rk[i];
			z[i] = zk[i];
		}
		cont++;
	}

	return cont;
}