typedef double (*FuncPtr2)(double, double);
typedef double (*FuncPtr1)( double);
double bisec(FuncPtr1 f, double a, double b, double E);
double horde(FuncPtr1 f, double a, double b, double E);
double nyuton(FuncPtr1 f, FuncPtr1 f2, double a, double b, double E);
double iter(FuncPtr1 f, double a, double b, double E);
double lagranj(double* xs, double* ys, int n, double x);
double rectangle(FuncPtr1 f, double a, double b, int n); //  3
double trapezoid(FuncPtr1 f, double a, double b, int n); // 28
double simpson(FuncPtr1 f, double a, double b, int n);   //  7 
double renge(double a, double b);
void gauss(double** A, double* b, double* x, int n);
double* method_gause(double matrix[3][3], double vector[3]);
void plus(double matrix[3][3], double vector[3],
     int k1, int k2, double m);

double* method_gause_z(double matrix[3][3], double vector[3], double epsilon);
double* anton(FuncPtr2 f, double start, double y0, double step, int steps);
double* renge_kuta(FuncPtr2 f, double start, double y0, double step, int steps);
