#include <stdio.h>
#include "matriz.h"
#include "gradconj.h"
#include <math.h>



void teste1_1(double tol)
{
    int n = 2;
    double **A = matcria(n,n);
    double *x = vetcria(n);
    double *b = vetcria(n);
    int iters;

    A[0][0] = 3; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 2;
    b[0] = b[1] = 5;

    iters = GradConj(n, A, b, x, tol);

    printf("vetor x:\n");
    printvec(x, n);
    printf("numero de iteracoes:\niters = %d\n", iters);

}

void teste1_2(double tol)
{
    int n = 6;
    double **A = matcria(n,n);
    double *x = vetcria(n);
    double *b = vetcria(n);
    int iters;
    int i;


    for(i=0;i<n;i++)
    {
        A[i][i-1] = -1;
        A[i][i] = 3;
        A[i][i+1] = -1;
    }

    A[0][5] = A[1][4] = A[4][1] = A[5][0] = 0.5;
    b[0] = b[5] = 2.5;
    b[1] = b[4] = 1.5;
    b[2] = b[3] = 1;

    iters = GradConj(n, A, b, x, tol);

    printf("vetor x:\n");
    printvec(x, n);
    printf("numero de iteracoes:\niters = %d\n", iters);

}

void teste2_1(double tol)
{
    int n = 2;
    double **A = matcria(n,n);
    double *x = vetcria(n);
    double *b = vetcria(n);
    int iters;

    A[0][0] = 3; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 2;
    b[0] = b[1] = 5;

    iters = GradConjJacobi(n, A, b, x, tol);

    printf("vetor x:\n");
    printvec(x, n);
    printf("numero de iteracoes:\niters = %d\n", iters);
}

void teste2_2(double tol)
{
    int n = 6;
    double **A = matcria(n,n);
    double *x = vetcria(n);
    double *b = vetcria(n);
    int iters, i;

    for(i=0;i<n;i++)
    {
        A[i][i-1] = -1;
        A[i][i] = 3;
        A[i][i+1] = -1;
    }

    A[0][5] = A[1][4] = A[4][1] = A[5][0] = 0.5;
    b[0] = b[5] = 2.5;
    b[1] = b[4] = 1.5;
    b[2] = b[3] = 1;

    iters = GradConjJacobi(n, A, b, x, tol);

    printf("vetor x:\n");
    printvec(x, n);
    printf("numero de iteracoes:\niters = %d\n", iters);
}

int main()
{
    double tol = pow(10,-7);

    printf("Teste1: sem pre-condicionador\n");
    printf("\nmatriz1\n");
    teste1_1(tol);
    printf("\nmatriz2\n");
    teste1_2(tol);
    
    
    printf("\n\nTeste2: com pre-condicionador:\n");
    printf("\nmatriz1\n");
    teste2_1(tol);   
    printf("\nmatriz2\n");
    teste2_2(tol);
    
    
    return 0;
}