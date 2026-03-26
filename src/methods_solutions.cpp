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