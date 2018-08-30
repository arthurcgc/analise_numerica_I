#include <math.h>
#include <stdlib.h>

int bissecao (double a, double b, int p, double (*f) (double x), double* r)
{
  int i,n;
  double fa,fc,c;

  n = ceil( log( (b-a)/(0.5 * pow(10, -p)) ) / log(2) ) - 1;

  fa = f(a);

  for (i = 0; i < n; i++)
  {
    c = (a+b)/2;
    fc = f(c);

    if(fc == 0)
      return c;

    else if(fa*fc > 0)
    {
      a = c;
      fa = fc;
    }
      else
        b = c;
  }

  *r = c;

  return n;

}


int IQI (double x0, double x1, double x2, int p,
double (*f) (double x), double* r)
{
  int i,n;
  double y0,y1,y2,x3,y3;


  n=100;

  for(i=0;i<n;i++)
  {
    y0 = f(x0);
    y1 = f(x1);
    y2 = f(x2);
    x3 = ((y1*y2/((y0-y1)*(y0-y2)))*x0) + ((y0*y2/((y1-y0)*(y1-y2)))*x1) + ((y0*y1/((y2-y0)*(y2-y1)))*x2);
    x0=x3;
    y3 = f(x3);
    if (y3 < 0)
      y3 *= -1;
    if(y3 < 0.5 * pow(10,-p))
    {
      *r = x0;
      return i+1;
    }
  }
  *r = x0;

  return n;
}
