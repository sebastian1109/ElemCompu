double **MatDin(int fil, int col);
double *VectDin(int n);
double *MatMult(double **A, double *xx, int dimension, int fil);
int Jacobi(int n, double **A, double *b, int *xi, double eps, int maxIt)
