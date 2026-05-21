#include <stdio.h>
#include <cmath>
#include "methods_solutions.hpp"
#include "fun.hpp"

void a(){
    double y01 = 10/3;
    double start1 = 0;
    double end1 = 0.9;
    double step1 = 0.001;
    int steps1 = (int)((end1 - start1) / step1) + 1;
    printf("%d\n",steps1);
    double* result1 = anton(fun28, start1, y01, step1, steps1);
    double* result2 = anton(fun28, start1, y01, step1 / 2, steps1);
    printf("P = %f\n", renge(result1[9], result2[9]));
    save_plot("anton.bmp", result1,steps1, 800, 600);
    delete[] result1;
}
void b(){
    double y02 = 1;
    double start2 = 1;
    double end2 = 20;
    double step2 = 0.01;
    int steps2 = (int)((end2 - start2) / step2) + 1;
    double* result2 = renge_kuta(f13, start2, y02, step2, steps2);
    double* result1 = renge_kuta(f13, start2, y02, step2, steps2);
    printf("P = %f\n", renge(result1[9], result2[9]));
    save_plot("renge_kuta.bmp", result2,steps2, 800, 600);
    delete[] result2;
}
int main(){
    a();
    b();
    return 0;
}