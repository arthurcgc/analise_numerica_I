#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "metiter.h"

void teste1_Jacobi()
{
    double tol = pow(10,-7);
    int n = 2;
    double *b = (double*)malloc(sizeof(double)*n);
    double **A = matcria(n,n);
    double *x = (double*)malloc(sizeof(double)*n);
    int iter;
    int i;

    b[0] = b[1] = 5;   
    for(i=0;i<n;i++)
        x[i] = 0;

    A[0][0] = 3; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 2;

    iter = Jacobi(n, A, b, x, tol);

    printf("iters = %d\n", iter);
    printvec(x, n);
}


void teste2_Jacobi()
{
    double tol = pow(10,-7);
    int n = 6;
    double *b = (double*)malloc(sizeof(double)*n);
    double **A = matcria(n,n);
    double *x = (double*)malloc(sizeof(double)*n);
    int iter;
    int i;

    b[0] = 2.5; b[1] = 1.5; b[2] = 1; b[3] = 1; b[4] = 1.5; b[5] = 2.5;   

    
    A[0][0] = 3;  A[0][1] =-1;A[0][2] =  0; A[0][3] = 0; A[0][4] = 0;   A[0][5] = 0.5;
    A[1][0] = -1; A[1][1] = 3; A[1][2] = -1; A[1][3] = 0; A[1][4] = 0.5; A[1][5] = 0;
    A[2][0] = 0; A[2][1] =-1; A[2][2] = 3; A[2][3] = -1; A[2][4] = 0; A[2][5] = 0;
    A[3][0] = 0; A[3][1] = 0; A[3][2] = -1; A[3][3] = 3; A[3][4] = -1; A[3][5] = 0;
    A[4][0] = 0; A[4][1] = 0.5; A[4][2] = 0; A[4][3] = -1; A[4][4] = 3; A[4][5] =-1;
    A[5][0] = 0.5; A[5][1] = 0; A[5][2] = 0; A[5][3] = 0; A[5][4] = -1; A[5][5] = 3;

    for(i=0;i<n;i++)
        x[i] = 0;

    iter = Jacobi(n, A, b, x, tol);

    printf("iters = %d\n", iter);
    printvec(x, n);
}

void teste1_Gauss()
{
    double tol = pow(10,-7);
    int n = 2;
    double *b = (double*)malloc(sizeof(double)*n);
    double **A = matcria(n,n);
    double *x = (double*)malloc(sizeof(double)*n);
    int iter;
    int i;

    b[0] = b[1] = 5;   
    for(i=0;i<n;i++)
        x[i] = 0;

    A[0][0] = 3; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 2;

    iter = GaussSeidel(n, A, b, x, tol);
    printf("iters = %d\n", iter);
    printvec(x, n);
}

void teste2_Gauss()
{
    double tol = pow(10,-7);
    int n = 6;
    double *b = (double*)malloc(sizeof(double)*n);
    double **A = matcria(n,n);
    double *x = (double*)malloc(sizeof(double)*n);
    int iter;
    int i;

    b[0] = 2.5; b[1] = 1.5; b[2] = 1; b[3] = 1; b[4] = 1.5; b[5] = 2.5;   

    
    A[0][0] = 3;  A[0][1] =-1;A[0][2] =  0; A[0][3] = 0; A[0][4] = 0;   A[0][5] = 0.5;
    A[1][0] = -1; A[1][1] = 3; A[1][2] = -1; A[1][3] = 0; A[1][4] = 0.5; A[1][5] = 0;
    A[2][0] = 0; A[2][1] =-1; A[2][2] = 3; A[2][3] = -1; A[2][4] = 0; A[2][5] = 0;
    A[3][0] = 0; A[3][1] = 0; A[3][2] = -1; A[3][3] = 3; A[3][4] = -1; A[3][5] = 0;
    A[4][0] = 0; A[4][1] = 0.5; A[4][2] = 0; A[4][3] = -1; A[4][4] = 3; A[4][5] =-1;
    A[5][0] = 0.5; A[5][1] = 0; A[5][2] = 0; A[5][3] = 0; A[5][4] = -1; A[5][5] = 3;

    for(i=0;i<n;i++)
        x[i] = 0;

    iter = GaussSeidel(n, A, b, x, tol);

    printf("iters = %d\n", iter);
    printvec(x, n);
}

void teste1_SOR()
{
    double tol = pow(10,-7);
    int n = 2;
    double *b = (double*)malloc(sizeof(double)*n);
    double **A = matcria(n,n);
    double *x = (double*)malloc(sizeof(double)*n);
    int iter;
    int i;

    b[0] = b[1] = 5;   
    for(i=0;i<n;i++)
        x[i] = 0;

    A[0][0] = 3; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 2;

    iter = SOR(n, A, b, x, tol, 1.1);

    printf("iters = %d\n", iter);
    printvec(x, n);    
}

void teste2_SOR()
{
    double tol = pow(10,-7);
    int n = 6;
    double *b = (double*)malloc(sizeof(double)*n);
    double **A = matcria(n,n);
    double *x = (double*)malloc(sizeof(double)*n);
    int iter;
    int i;

    b[0] = 2.5; b[1] = 1.5; b[2] = 1; b[3] = 1; b[4] = 1.5; b[5] = 2.5;   

    
    A[0][0] = 3;  A[0][1] =-1;A[0][2] =  0; A[0][3] = 0; A[0][4] = 0;   A[0][5] = 0.5;
    A[1][0] = -1; A[1][1] = 3; A[1][2] = -1; A[1][3] = 0; A[1][4] = 0.5; A[1][5] = 0;
    A[2][0] = 0; A[2][1] =-1; A[2][2] = 3; A[2][3] = -1; A[2][4] = 0; A[2][5] = 0;
    A[3][0] = 0; A[3][1] = 0; A[3][2] = -1; A[3][3] = 3; A[3][4] = -1; A[3][5] = 0;
    A[4][0] = 0; A[4][1] = 0.5; A[4][2] = 0; A[4][3] = -1; A[4][4] = 3; A[4][5] =-1;
    A[5][0] = 0.5; A[5][1] = 0; A[5][2] = 0; A[5][3] = 0; A[5][4] = -1; A[5][5] = 3;

    for(i=0;i<n;i++)
        x[i] = 0;

    iter = SOR(n, A, b, x, tol, 1.1);

    printf("iters = %d\n", iter);
    printvec(x, n);
}
int main()
{
    //teste 1
    printf("\t\t\t\tTESTE 1 Jacobi:\n");
    teste1_Jacobi();
    printf("\t\t\t\tTESTE 1 Gauss-Seidel:\n");
    teste1_Gauss();
    printf("\t\t\t\tTESTE 1 SOR e w = 1.1:\n");
    teste1_SOR();

    printf("\t\t\t\tTESTE 2 Jacobi:\n");
    teste2_Jacobi();
    printf("\t\t\t\tTESTE 2 Gauss-Seidel:\n");
    teste2_Gauss();
    printf("\t\t\t\tTESTE 2 SOR e w = 1.1:\n");
    teste2_SOR();


    return 0;
}