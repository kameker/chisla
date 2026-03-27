#include <stdio.h>
#include "methods_solutions.hpp"


int main(){
    double E;
    E = 0.001;
    printf("N x: %f\n", iter(0,1,E));
    printf("N x: %f\n", iter(1,2,E));
    printf("N x: %f\n", iter(2,4,E));
    return 0;
}