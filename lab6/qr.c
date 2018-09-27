#include "matriz.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



double dotproduct(double *v1, double *v2, int n)
{
    int i;
    double sum = 0;
    for(i = 0; i <= n; i++)
    {
        sum+=v1[i]*v2[i];
    }
    return sum;
}

void scalar_vect(double mull, double *v_1, double * v_res, int n)
{
    int i;
    for (i=0;i<=n;i++)
    {
        v_res[i]+=mull*v_1[i];
    }
}

void subvector(double *v1, double *v2, double *res, int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        res[i] = v1[i]-v2[i];
    }
}

double *projection(double **v, int n, int v_index)
{
    int index = v_index;
    int i;
    double *v_res = (double*)malloc(n*sizeof(double));
    double mull;
    for(i=0;i<=n;i++)
    {
        v_res[i] = 0;
    }
    while(index>0)
    {
        mull = dotproduct(v[v_index], v[index-1],n)/dotproduct(v[index-1],v[index-1],n);
        scalar_vect(mull,v[index-1],v_res,n);
        index--;
    }
    return v_res;
}


double sum_sqrt(double *v, int n)
{
    int i;
    double sum = 0;
    for(i=0;i<=n;i++)
    {
        sum += v[i]*v[i];
    }

    sum = sqrt(sum);

    return sum;
}

/* Gram Schmit Process */
double **GS_matrix(int m,  int n, double **A)
{
    int i,j;
    double mull;
    double **Qt = matcria(n,m);
    double *Qt_proj;
    double length;
    transposta(m,n,A,Qt);
    for(i=1;i<n;i++)    // n = numero de linhas de Qt
    {
        Qt_proj = projection(Qt,n,i);
        subvector(Qt[i],Qt_proj,Qt[i],n);
    }
    for(i=0;i<n;i++)
    {
        length = sum_sqrt(Qt[i],n);
        for(j=0;j<m;j++)
        {
            Qt[i][j] = Qt[i][j]/length;
        }
    }
    return Qt;
}

void QR (int m, int n, double** A, double** Q, double** R)
{
    double **Qt = GS_matrix(m,n,A);
    transposta(n,m,Qt,Q);
    multmm(n,m,n,Qt,A,R);
}
