#include <stdio.h>
#include "qr.h"
#include "matriz.h"

int main(int argc, char const *argv[])
{
    int m =4;
    int n =3;
    double **A = matcria(m,n);
    double **Q = matcria(m,n);
    double **R = matcria(m,n);


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

    return 0;
}
