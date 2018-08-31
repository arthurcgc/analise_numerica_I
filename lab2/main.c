#include <stdio.h>
#include "raiz.h"
#include <math.h>
#include <stdlib.h>


double functeste(double x)
{
  return sin(x) - pow(x, 3);
}

double func_ex2(double x)
{
  return cos(x) - pow(x,3) + x;
}

double func_ex3(double m)
{
  double e = 2.718281828;
  double coef = -135/m;
  return 53.5714/(1-pow(e,coef));
}

int main()
{
  double *raiz = (double*)malloc(sizeof(double));
  // primeiro teste
  printf("teste\n");
  int res = bissecao(0.5,1.5,6, functeste, raiz);
  printf("raiz por bissecao = %f\niteracoes = %d\n",*raiz,res);
  res = IQI(0.5, 0.8, 1, 6,functeste, raiz);
  printf("raiz por IQI = %f\niteracoes = %d\n",*raiz,res);

  //segunda questao letra a
  printf("segunda questao letra a:\n");
  res = bissecao(1.0, 1.5, 6, func_ex2, raiz);
  printf("raiz por bissecao = %f\niteracoes = %d\n",*raiz,res);
  res = IQI(1.0, 1.2, 1.5, 6, func_ex2, raiz);
  printf("raiz por IQI = %f\niteracoes = %d\n",*raiz,res);

  //segunda questao letra b
  printf("segunda questao letra b:\n");
  res = bissecao(-18, -12, 6, func_ex3, raiz);
  printf("raiz por bissecao = %f\niteracoes = %d\n",*raiz,res);
  res = IQI(-20, -18, -15, 8, func_ex3, raiz);
  printf("raiz por IQI = %f\niteracoes = %d\n",*raiz,res);

  return 0;
}
