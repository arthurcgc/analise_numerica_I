#include <stdio.h>
#include "taylor.h"

int main()
{
	double r = tcos(0);

	printf("tcos(0) = %f\n", r);

	printf("tcos_erro(0) = %f\n", tcos_erro(0));

	printf("tsqrt(2) = %f\n", tsqrt(2));

	printf("tsqrt_erro(2) = %f\n", tsqrt_erro(2));


	return 0;
}
