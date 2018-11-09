int Jacobi (int n, double** A, double* b, double* x, double tol);
int GaussSeidel (int n, double** A, double* b, double* x, double tol);
int SOR (int n, double** A, double* b, double* x, double tol, double w);


double* vetcria (int n);

void vetlibera (double* v);

void printvec(double *vec, int n); //print vector

double escalar (int n, double* v, double* w);

double norma2 (int n, double* v);

double** matcria (int m, int n);

void matlibera (int m, double** A);

void transposta (int m, int n, double** A, double** T);

void multmm (int m, int n, int q, double** A, double** B, double** C);

void multmv (int m, int n, double** A, double* v, double* w);

void printmat(int m, int n, double **mat); // print matrix