#include <stdio.h>
#include "raiz.h"
#include <math.h>
#include <stdlib.h>


double func(double x)
{
  return sin(x) - pow(x, 3);
}

int main()
{
  double *raiz = (double*)malloc(sizeof(double));
  int res = bissecao(0.5,1.5,6, func, raiz);
  printf("raiz por bissecao = %f\niteracoes = %d\n",*raiz,res);
  res = IQI(0.5, 0.8, 1, 6,func, raiz);
  printf("raiz por IQI = %f\niteracoes = %d\n",*raiz,res);

  return 0;
}
