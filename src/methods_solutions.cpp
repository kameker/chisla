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
    printf("p: %f\n", fabs(xn1-xn));
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
    printf("p: %f\n",fabs(xn - xn_1));
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
            printf("p: %f\n", fabs(x - x_prev));
            return x;
        }
        iter++;
    }
    printf(">%d\n", max_iter);
    return x;
}