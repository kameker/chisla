#include <stdio.h>
#include <cmath>
#include "methods_solutions.hpp"
#include "fun.hpp"


int main(){
    double xs[6]{0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
    double ys[6]{1.469, 1.033, 0.653, 0.261, -0.391, -2.075};
    printf("%f\n", lagranj(xs,ys,6,1));
    int y_count = 1920;
    double y_values[y_count];
    for (int i = 0; i < y_count; i++){
        y_values[i] = lagranj(xs,ys,6,(double)i);
    }
    
    save_plot("imgs/graph.bmp", y_values, y_count, 1920, 1080);
    return 0;
}