#include "methods_solutions.hpp"
#include "fun.hpp"
#include <stdio.h>
#include <math.h>
double bisec(FuncPtr1 f, double a, double b, double E){
    double temp;
    if (f(a) == 0) printf("%f\n",a);
    if (f(b) == 0) printf("%f\n",b);
    while (b - a > E){
        temp = a + (b - a) / 2;
        if (f(a) * f(temp) < 0) {
            b = temp;
        }
        else{
            a = temp;
        }
    }
    return temp;
}

double horde(FuncPtr1 f, double a, double b, double E){
    if (f(a) == 0) printf("%f\n",a);
    if (f(b) == 0) printf("%f\n",b);
    double xn,xn1;
    if (f(a) > 0 && f(b) < 0){
        xn = a - (b - a)/(f(b) -f(a))*f(a);
        xn1 = xn - (xn-a) / (f(xn) - f(a)) * f(xn);
        while (fabs(xn - xn1) > E){
            xn = xn1;
            xn1 = xn - (xn-a) / (f(xn) - f(a)) * f(xn);
        }
    }
    if (f(a) < 0 && f(b) > 0){
        xn = a - (b - a)/(f(b) - f(a)) * f(a);
        xn1 = xn - (b-xn) / (f(b) - f(xn)) * f(xn);
        while (fabs(xn - xn1) > E){
            xn = xn1;
            xn1 = xn - (b-xn) / (f(b) - f(xn)) * f(xn);
        }
    }
    //printf("p: %f\n", fabs(xn1-xn));
    return xn1;   
}

double nyuton(FuncPtr1 f,FuncPtr1 f2, double a, double b, double E){
    if (f(a) == 0) printf("%f\n",a);
    if (f(b) == 0) printf("%f\n",b);
    double xn, xn_1, x0;
    x0 = (b+a)/2;
    xn_1 = x0 - f(x0) / f2(x0);
    xn = xn_1 - f(xn_1)/f2(xn_1);
    while (fabs(xn - xn_1) > E){
        xn_1 = xn;
        xn = xn_1 - f(xn_1)/f(xn_1);
    }
    //printf("p: %f\n",fabs(xn - xn_1));
    return xn;
}

double iter(FuncPtr1 f, double a, double b, double E){
    if (fun(a) == 0) printf("%f\n",a);
    if (fun(b) == 0) printf("%f\n",b);
    double x0 = (a + b) / 2;
    double x = x0;
    double x_prev;
    int max_iter = 1000;
    int iter = 0;
    while (iter < max_iter){
        double fp = f(x);
        if (fabs(fp) < 1e-10){
            printf("-> 0\n");
            return INFINITY;
        }
        double lambda = 1.0 / fp;
        x_prev = x;
        x = x_prev - lambda * fun(x_prev);
        if (fabs(x - x_prev) < E){
            //printf("p: %f\n", fabs(x - x_prev));
            return x;
        }
        iter++;
    }
    printf(">%d\n", max_iter);
    return x;
}
double lagranj(double* xs, double* ys, int n, double x){
    double result = 0.0;
    for (int i = 0; i < n; i++){
        double basis = 1.0;
        for (int j = 0; j < n; j++){
            if (j != i){
                basis *= (x - xs[j]) / (xs[i] - xs[j]);
            }
        }
        result += ys[i] * basis;
    }

    return result;
}
double rectangle(FuncPtr1 f, double end, double start, int n){
    double r = 0;
    double h = (end - start) / n;
    for (int i = 0 ; i < n ; i++){
        r += f(start + h / 2 + i * h);
    }
    //printf("p = %f\n", (end - start) * h * h / 24);
    return r * h;
}
double trapezoid(FuncPtr1 f, double end, double start, int n){
    double r = 0;
    double h = (end - start) / n;
    for (int i = 1; i < n; i++) {
        r += f(start + i * h);
    }
    return h * ((f(end) + f(start)) / 2.0 + r);
}
double simpson(FuncPtr1 f, double end, double start, int n){
    if (n % 2 != 0) n++;
    
    double h = (end - start) / n;
    double r = f(start) + f(end);
    double odd_sum = 0;   
    double even_sum = 0;  
    
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            odd_sum += f(start + i * h);
        } else {
            even_sum += f(start + i * h);
        }
    }
    
    r += 4 * odd_sum + 2 * even_sum;
    return r * h / 3;
}
double renge(double a, double b){
    return fabs(a - b) / 3;
}
double* method_gause(double matrix[3][3], double vector[3]){
    double x1, x2, x3;
    plus(matrix, vector, 0, 1, -matrix[1][0] / matrix[0][0]);
    plus(matrix, vector, 0, 2, -matrix[2][0] / matrix[0][0]);
    plus(matrix, vector, 1, 2, -matrix[2][1] / matrix[1][1]);
    x3 = vector[2] / matrix[2][2];
    x2 = (vector[1] - matrix[1][2] * x3) / matrix[1][1];
    x1 = (vector[0] - matrix[0][2] * x3 - matrix[0][1] * x2) / matrix[0][0];
    return new double[3]{x1, x2, x3};
    /*plus(matrix, vector, 2, 1, -matrix[1][2] / matrix[2][2]);
    plus(matrix, vector, 2, 0, -matrix[0][2] / matrix[2][2]);
    plus(matrix, vector, 1, 0, -matrix[0][1] / matrix[1][1]);
    printf("x1 = %f\n", vector[0] / matrix[0][0]);
    printf("x2 = %f\n", vector[1] / matrix[1][1]);
    printf("x3 = %f\n", vector[2] / matrix[2][2]);
    */
}
double* method_gause_z(double matrix[3][3], double vector[3], double epsilon){
    double x1p,x2p,x3p, t1, t2, t3;
    x1p = 0;
    x2p = 0;
    x3p = 0;
    do {
        t1 = x1p;
        t2 = x2p;
        t3 = x3p;
        x1p = 1 / matrix[0][0] * (vector[0] - matrix[0][1] * t2 - matrix[0][2] * t3);
        x2p = 1 / matrix[1][1] * (vector[1] - matrix[1][0] * x1p - matrix[1][2] * t3);
        x3p = 1 / matrix[2][2] * (vector[2] - matrix[2][0] * x1p - matrix[2][1] * x2p);
        
    } while (fmax(fabs(x1p - t1), fmax(fabs(x2p - t2), fabs(x3p - t3))) > epsilon);
    return new double[3]{x1p, x2p, x3p};
}
void plus(double matrix[3][3], double vector[3],
     int k1, int k2, double m){
        vector[k2] += vector[k1] * m;
        matrix[k2][0] += matrix[k1][0] * m;
        matrix[k2][1] += matrix[k1][1] * m;
        matrix[k2][2] += matrix[k1][2] * m;
}
double* anton(FuncPtr2 f, double start, double y0, double step, int steps){
    double* result = new double[steps];
    double x = start;
    double y = y0;
    for (int i = 0 ; i < steps; i++){
        y = y + step * f(x, y);
        x = x + step;
        result[i] = y;
        //printf("%f\n", y);
    };
    return result;
}
double* renge_kuta(FuncPtr2 f, double start, double y0, double step, int steps){
    double* result = new double[steps];
    double x = start;
    double y = y0;
    double k1,k2,k3,k4;
    for (int i = 0 ; i < steps; i++){
        k1 = f(x, y);
        k2 = f(x + step / 2, y + (step / 2) * k1);
        k3 = f(x + step / 2, y + (step / 2) * k2);
        k4 = f(x + step, y + step * k3);
        y = y + (step / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x += step;
        //printf("%f\n", y);
        result[i] = y;
    }
    return result;
}