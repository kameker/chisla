#include <stdio.h>
#include <cmath>
#include "methods_solutions.hpp"
#include "fun.hpp"
# define M_PI           3.14159265358979323846
#define N 100000


int main(){
    printf("Rectangle: %f\n", rectangle(0.5, 0, N));
    printf("Error Rectangle: %f\n", renge(rectangle(0.5, 0, N),rectangle(0.5, 0, N) / 2));
    printf("Trapezoid: %f\n", trapezoid(2, 0, N));
    printf("Error Trapezoid: %f\n", renge(trapezoid(2, 0, N),trapezoid(2, 0, N / 2)));
    printf("Simpson: %f\n", simpson(M_PI / 3, 0, N));
    printf("Error Simpson: %f\n", renge(simpson(M_PI / 3, 0, N), simpson(M_PI / 3, 0, N / 2)));
    return 0;
}