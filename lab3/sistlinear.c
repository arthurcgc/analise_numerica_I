#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


#include <math.h>
#include <stdlib.h>
#include "matriz.h"

static double **pivot(int n, double** A)
{
  int i, j, k, jmax, tmp;
  double** P = matcria(n, n);

  // Matriz identidade
  for (i = 0; i < n; i++) {
    P[i][i] = 1;
  }

  for (i = 0; i < n; i++)  {
    jmax = i;
    for (j =  i; j <  n; j++) {
      if (fabs(A[j][i]) > fabs(A[jmax][i])) {
        jmax = j;
      }
    }

    if (jmax != i){
      for (k = 0; k < n; k++) {
        tmp = P[i][k];
        P[i][k] = P[jmax][k];
        P[jmax][k] = tmp;
      }
    }
  }

  return P;
}




void fatoracao (int n, double** A, int* p)
{
  int i, j, k;
   double s;

   double **P = pivot(n, A);
   double **PA = matcria(n, n);
   mat_multm(n, n, n, P, A, PA);

   double **L = mat_cria(n, n);
   double **U = mat_cria(n, n);

   // A diagonal de L é 1
   for (i = 0; i < n; i++)
   {
     L[i][i] = 1;
   }

   for (i = 0; i < n; i++)
   {
     for (j = 0; j < n; j++)
     {
       if (j <= i)
       {
         s = 0;
         for (k = 0; k <  j; k++)
         {
           s+=  L[j][k] * U[k][i];
         }
         U[j][i] = PA[j][i] - s;
       }
       if (j >= i)
       {
         s = 0;
         for (k = 0; k <  i; k++)
         {
           s+=  L[j][k] * U[k][i];
         }
         L[j][i] = (PA[j][i] - s) / U[i][i];
       }
     }
   }

   for (i = 0; i < n; i++)
   {
     for (j = 0; j < n; j++)
     {
       if (i <= j)
       {
         A[i][j] = U[i][j];
       }
       else
       {
         A[i][j] = L[i][j];
       }
     }
   }

   // Liberando
   mat_libera(n, PA);
   mat_libera(n, L);
   mat_libera(n, U);

   return P;
 }


int main()
{
  int n = 3;
  double **A = matcria(n,n);
  double **P = matcria(n,n);
  double **PA = matcria(n,n);

  A[0][0] = 25; A[0][1] = 5; A[0][2] = 1;
  A[1][0] = 64; A[1][1] = 8; A[1][2] = 1;
  A[2][0] = 144; A[2][1] = 12; A[2][2] = 1;

  printf("\nA=\n");
  printmat(n,n,A);

  P = pivot(n,A);

  printf("\nP=\n");
  printmat(n,n,P);

  printf("\nPA=\n");
  multmm(n,n,n,P,A,PA);
  printmat(n,n,PA);

  return 0;
}
