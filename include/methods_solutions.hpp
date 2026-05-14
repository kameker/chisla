double bisec(double a, double b, double E);
double horde(double a, double b, double E);
double nyuton(double a, double b, double E);
double iter(double a, double b, double E);
double lagranj(double* xs, double* ys, int n, double x);
double rectangle(double a, double b, int n); //  3
double trapezoid(double a, double b, int n); // 28
double simpson(double a, double b, int n);   //  7 
double renge(double a, double b);
void gauss(double** A, double* b, double* x, int n);
double* method_gause(double matrix[3][3], double vector[3]);
void plus(double matrix[3][3], double vector[3],
     int k1, int k2, double m);
double* method_gause_z(double matrix[3][3], double vector[3], double epsilon);