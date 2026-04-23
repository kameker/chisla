#include "methods_solutions.hpp"
#include "fun.hpp"
#include <stdio.h>
#include <math.h>
double bisec(double a, double b, double E){
    double temp;
    if (fun(a) == 0) printf("%f\n",a);
    if (fun(b) == 0) printf("%f\n",b);
    while (b - a > E){
        temp = a + (b - a) / 2;
        if (fun(a) * fun(temp) < 0) {
            b = temp;
        }
        else{
            a = temp;
        }
    }
    return temp;
}

double horde(double a, double b, double E){
    if (fun(a) == 0) printf("%f\n",a);
    if (fun(b) == 0) printf("%f\n",b);
    double xn,xn1;
    if (fun(a) > 0 && fun(b) < 0){
        xn = a - (b - a)/(fun(b) -fun(a))*fun(a);
        xn1 = xn - (xn-a) / (fun(xn) - fun(a)) * fun(xn);
        while (fabs(xn - xn1) > E){
            xn = xn1;
            xn1 = xn - (xn-a) / (fun(xn) - fun(a)) * fun(xn);
        }
    }
    if (fun(a) < 0 && fun(b) > 0){
        xn = a - (b - a)/(fun(b) - fun(a)) * fun(a);
        xn1 = xn - (b-xn) / (fun(b) - fun(xn)) * fun(xn);
        while (fabs(xn - xn1) > E){
            xn = xn1;
            xn1 = xn - (b-xn) / (fun(b) - fun(xn)) * fun(xn);
        }
    }
    //printf("p: %f\n", fabs(xn1-xn));
    return xn1;   
}

double nyuton(double a, double b, double E){
    if (fun(a) == 0) printf("%f\n",a);
    if (fun(b) == 0) printf("%f\n",b);
    double xn, xn_1, x0;
    x0 = (b+a)/2;
    xn_1 = x0 - fun(x0) / funp(x0);
    xn = xn_1 - fun(xn_1)/funp(xn_1);
    while (fabs(xn - xn_1) > E){
        xn_1 = xn;
        xn = xn_1 - fun(xn_1)/funp(xn_1);
    }
    //printf("p: %f\n",fabs(xn - xn_1));
    return xn;
}

double iter(double a, double b, double E){
    if (fun(a) == 0) printf("%f\n",a);
    if (fun(b) == 0) printf("%f\n",b);
    double x0 = (a + b) / 2;
    double x = x0;
    double x_prev;
    int max_iter = 1000;
    int iter = 0;
    while (iter < max_iter){
        double fp = funp(x);
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
double rectangle(double end, double start, int n){
    double r = 0;
    double h = (end - start) / n;
    for (int i = 0 ; i < n ; i++){
        r += fun3(start + h / 2 + i * h);
    }
    //printf("p = %f\n", (end - start) * h * h / 24);
    return r * h;
}
double trapezoid(double end, double start, int n){
    double r = 0;
    double h = (end - start) / n;
    for (int i = 1; i < n; i++) {
        r += fun4(start + i * h);
    }
    return h * ((fun4(end) + fun4(start)) / 2.0 + r);
}
double simpson(double end, double start, int n){
    if (n % 2 != 0) n++;
    
    double h = (end - start) / n;
    double r = fun5(start) + fun5(end);
    double odd_sum = 0;   
    double even_sum = 0;  
    
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            odd_sum += fun5(start + i * h);
        } else {
            even_sum += fun5(start + i * h);
        }
    }
    
    r += 4 * odd_sum + 2 * even_sum;
    return r * h / 3;
}
double renge(double a, double b){
    return fabs(a - b) / 3;
}