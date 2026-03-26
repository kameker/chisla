#include <stdio.h>
#include "methods_solutions.hpp"


int main(){
    double a,b,E;
    E = 0.001;
    printf("N x: %f\n", nyuton(0,1,E));
    printf("N x: %f\n", nyuton(1,2,E));
    printf("N x: %f\n", nyuton(2,4,E));
    return 0;
}