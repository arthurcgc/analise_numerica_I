#include <stdio.h>
#include <math.h>


double tcos (double x)
{
	double res;
	
	res = 1 + (-1*x*x)/2. + x*x*x*x/24.;
	
	return res;
}
double tcos_erro (double x)
{
	double residue = -(x*x*x*x*x*x)/720.;
	return residue;
}


double tsqrt (double x)
{
	return 1 + (x-1)/2. - (1/8.)*((x-1)*(x-1)) + ((x-1)*(x-1)*(x-1))/16.;
}

double tsqrt_erro (double x)
{
	double c = 1.438;
	return ((-15/16.)*pow(c,7/2.))/24. *((x-1)*(x-1)*(x-1)*(x-1));
}

int main()
{
	double r = tcos(2);
	
	printf("tcos(2) = %f\n", r);
	
	printf("tcos_erro(2) = %f\n", tcos_erro(2));

	
	return 0;
}
