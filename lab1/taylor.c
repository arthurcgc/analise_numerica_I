#include <stdio.h>


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
	return (1 + (x-1)/2. - (((x-1)*(x-1))/8.) + ((x-1)*(x-1)*(x-1))/16.);
}

double tsqrt_erro (double x)
{
	return (-0.26324/24.)*((x-1)*(x-1)*(x-1)*(x-1));
}

int main()
{
	double r = tcos(0);

	printf("tcos(0) = %f\n", r);

	printf("tcos_erro(0) = %f\n", tcos_erro(0));

	printf("tsqrt(2) = %f\n", tsqrt(2));

	printf("tsqrt_erro(2) = %f\n", tsqrt_erro(2));


	return 0;
}
