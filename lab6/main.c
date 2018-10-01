#include <stdio.h>
#include "qr.h"
#include "matriz.h"

int main(int argc, char const *argv[])
{
    int m =4;
    int n =3;
    int k = 5;
    int u = 4;
    double **A = matcria(m,n);
    double **Q = matcria(m,n);
    double **R = matcria(m,n);


    double **B = matcria(k,u);
    double **Rb = matcria(k,u);
    double **Qb = matcria(k,u);


    double **Qt;
    A[0][0] = 1;    A[0][1] = 2;   A[0][2] = 3;
    A[1][0] =-1;    A[1][1] = 1;   A[1][2] = 1;
    A[2][0] = 1;    A[2][1] = 1;   A[2][2] = 1;
    A[3][0] = 1;    A[3][1] = 1;   A[3][2] = 1;

    printf("\nMatriz A = \n");
    printmat(m,n,A);
    Qt = GS_matrix(m,n,A);
    printf("\nMatriz Qt = \n");
    printmat(n,m,Qt);
    QR(m,n,A,Q,R);
    printf("\nMatriz Q=\n");
    printmat(m,n,Q);

    printf("\nMatriz R=\n");
    printmat(n,n,R);

    printf("\n\n-----------------------------------SEGUNDO TESTE----------------------------------------------------------\n\n");
    B[0][0] = 4;    B[0][1] =  2;   B[0][2] = 0;
    B[1][0] =-2;    B[1][1] =  3;   B[1][2] = 1;
    B[2][0] = 1;    B[2][1] =  3;   B[2][2] = 2;
    B[3][0] = 1;    B[3][1] =  0;   B[3][2] =-1;
    B[4][0] =-3;    B[4][1] =  1;   B[4][2] =-2;
    
    printf("\nMatriz B = \n");
    printmat(k,u,B);

    QR(k,u,B,Qb,Rb);
    printf("\nMatriz Qb=\n");
    printmat(k,u,Qb);
    printf("\nMatriz Rb=\n");
    printmat(u,u,Rb);

    return 0;
}
