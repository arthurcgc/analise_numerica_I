#include<stdio.h>
#include<stdlib.h>
#include"mmq.h"
#include"matriz.h"
#include<math.h>


void executaPrimeiroTeste();

int main() {

	printf("\n\n========== TESTE DE MMQ (MÉTODO DOS MÍNIMOS QUADRADOS) ==========\n\n");

	printf("\n\n====== Primeiro Teste ======\n\n");

	executaPrimeiroTeste();

	return 0;
}

void vet_imprime(int n, double* V, char* format) {

   int cols = 0;

   printf("| ");
   for(cols = 0; cols < n - 1; cols++) 
   {

      printf(format, V[cols]);
      printf(" ; ");
   }

	printf(format, V[cols]);
   printf("\t|\n");
}

void executaPrimeiroTeste() 
{

	double 	**A	= matcria(5, 3);
	double 	*b		= vetcria(5);
	double 	*x		= (double*) malloc(3 * sizeof(double));
	int 		i 		= 0;
	double 	r 		= 0;

	A[0][0] 	= 3;	A[0][1] 	= -1;	A[0][2] 	= 2;

	A[1][0] 	= 4;	A[1][1] 	= 1;	A[1][2] 	= 0;

	A[2][0] 	= -3;	A[2][1] 	= 2;	A[2][2] 	= 1;

	A[3][0] 	= 1;	A[3][1] 	= 1;	A[3][2] 	= 5;

	A[4][0] 	= -2;	A[4][1] 	= 0;	A[4][2] 	= 3;


	b[0] = 10;	b[1] = 10;	b[2] = -5;	b[3] = 15;	b[4]	= 0;


	x[0] = 0;	x[1] = 0;	x[2] = 0;

    printmat(5, 3, A);

	printf("\n\t\t\t * \n");

	printf("|\tx1\t|\n|\tx2\t|\n|\tx3\t|\n\n");

	printf("\t\t\t=\n\n");

	vet_imprime(5, b, "%.5g");
	
	printf("\n===> RESULTADO <===\n\n");

	MMQ(5, 3, A, b, x);
    
    vet_imprime(3, x, "%.5g");
}

