double Euler (double t0, double t1, double h, double y0, double (*f) (double t, double y));

double EulerAdapt (double t0, double t1, double h0, double y0,double (*f) (double t, double y), double tol);