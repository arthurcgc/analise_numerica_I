#include "pendulo.h"
#include <math.h>
#include <stdio.h>

#define PI 3.1415

double v_ang(double t, double theta)
{
    double g = 9.8;
    double l = 10;
    return (-g/l) * sin(theta);
}


double pendulo (double t, double h, double* theta, double* w)
{
    double k1, k2, k3, k4;


    k1 = h * v_ang(t, *theta);
    /* printf("k1 = %.16g\n", k1); */
    k2 = h * v_ang(t + (h/2), *theta + (k1/2));
    /* printf("k2 = %.16g\n", k2); */
    k3 = h * v_ang(t + (h/2), *theta + (k2/2));
    /* printf("k3 = %.16g\n", k3); */
    k4 = h * v_ang(t + h, *theta + k3);
    /* printf("k4 = %.16g\n", k4); */


    *theta= *theta + h * (*w);
    *w = *w + ((k1 + 2*k2 + 2*k3 + k4)/6);
    t = t + h;
/* 
    printf("w arthur = %.16g\n", *w);
    printf("t arthur = %.16g\n", t); */
    return t;
}

double periodo(double theta_0)
{
	double theta=theta_0;
	double T=0;
	double t1=0;
	double t2=0;
	double w1=0;
	double w2=0;
	double h=pow(10.0,-3);
	int cont=0;
    int i = 0;
	theta=theta*PI/180;
	while(cont<10)
	{
		w1=w2;
		t1=t2;
		t2=pendulo(t1,h, &theta,&w2);
		if(w1*w2<0)
		{
			cont++;
		}
        i++;
	}
	T=(2*(t1 +(fabs(w1)/(fabs(w1)+fabs(w2)))*(t2-t1)));
	return T/10;

}   

double periodo_simplificado(double theta0)
{
    double g = 9.8;
    double l = 10;
    
    return 2*PI*sqrt(l/g);
}
