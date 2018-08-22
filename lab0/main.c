#include "matriz.h"

int main()
{

	int i,j,count,n,m,q;
	double *v = vetcria(n);
	double *w = vetcria(n);
  double *v1,*v2;
	n = 3;
	m = 2;
	double **mat = matcria(m,n);
	double **trans = matcria(n,m);
	//matrizes que serao multiplicadas:
	double **m1 = matcria(n,m); // 3 linhas x 2 colunas
	double **m2 = matcria(m,n); // 2 linhas x 3 colunas
	q = n;
	double **res = matcria(n,q);	// resultado

	//populando o vetor
	for(i=0;i<n;i++)
	{
		v[i] = i+1;
		w[i] = v[i];
	}

	//populando a matriz
	count = 1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			mat[i][j] = count++;
	}

	//vetores:
	printf("imprimindo vetor vet:\n");
	printvec(v,n);
	printf("\nproduto escalar de v e w(v=w):\n");
	printf("%f\n",escalar(n,v,w));
	printf("\nnorma2 de v:\n%f\n",norma2(n,v));
	vetlibera(v);

	//matrizes:
	printf("\nimprimindo matriz mat:\n");
	printmat(m,n,mat);
	transposta(m,n,mat,trans);
	printf("\ntransposta de mat: \n");
	printmat(n,m,trans);
	matlibera(n,mat);
	//multiplicacao de matrizes:
	m1[0][0] = 2; m1[0][1] = 3;
	m1[1][0] = 0; m1[1][1] = 1;
	m1[2][0] = -1; m1[2][1] = 4;

	m2[0][0] = 1; m2[0][1] = 2; m2[0][2] = 3;
	m2[1][0] = -2; m2[1][1] = 0; m2[1][2] = 4;

	printf("\nm1 = \n");
	printmat(n, m, m1);
	printf("\nm2 = \n");
	printmat(m, q, m2);
	printf("\nmultiplicando m1 por m2 temos:\n");
	multmm (n, m, q, m1, m2, res);
	printmat(n, q, res);

	return 0;
}
