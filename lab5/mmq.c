#include"mmq.h"
#include"matriz.h"
#include"sistlinear.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void MMQ (int m, int n, double** A, double* b, double* x)
{
    double** At 	= (double**) malloc(n * sizeof(double*));
	double** AtA 	= (double**) malloc(n * sizeof(double*));
	double *w;
    int i;
	int *p = (int*) malloc(n * sizeof(int));

	for(i = 0; i < n; i++) 
    {
		At[i]	= (double*) malloc(m * sizeof(double));
		AtA[i] 	= (double*) malloc(n * sizeof(double));
    }
    w = vetcria(n);

    transposta(m , n, A, At);
    printf("imprimindo At:\n\n\n");
    printmat(n, m, At);
    printf("\n\n\n");

	printf("\n\nimprimindo AtA\n\n");
    multmm(n, m, n, At, A, AtA);
    printmat(n, m, AtA);
    printf("\n\n\n");

    
    multmv(n, m, At, b, w);

    fatoracao(n, AtA, p);
    substituicao(n, AtA, p, w, x);

/*     
    vetlibera(w);

    matlibera(m, At);
    matlibera(m,AtA); 
*/

}

