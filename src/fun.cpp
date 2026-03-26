#include  "fun.hpp"
#include <math.h>

double fun(double x){
    return (2 + cos(x))*sin(2*x) - 1;
}

double funp(double x){
    return 4*cos(2*x) + 2* cos(2 * x) * cos(x) - sin(x) * sin(2 * x);
}
double funpp(double x){
    return -8*sin(2*x)-5*sin(2*x)*cos(x) - 4 * cos(2*x) * sin(x);
}