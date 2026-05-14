#include <stdio.h>
#include <cmath>
#include "methods_solutions.hpp"
#include "fun.hpp"


int main(){
    double matrix[3][3] = {{3.01, -0.14, -0.15},
                           {1.11,  0.13, -0.75},
                           {0.17, -2.11,  0.71}};
    double vector[3]    =  {1.00,  0.13,  0.17};
    double* roots = method_gause(matrix,vector);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%3.3f ",matrix[i][j]);
        }
        printf(" == %3.3f\n", vector[i]);
    }
    printf("x1 = %f\n", roots[0]);
    printf("x2 = %f\n", roots[1]);
    printf("x3 = %f\n", roots[2]);

    double matrix2[3][3] = {{0.21, -0.18,  0.75},
                            {0.13,  0.75, -0.11},
                            {3.01, -0.33,  0.11}};
    double vector2[3]    =  {0.11,  2,  0.13};
    double* roots2 = method_gause_z(matrix2, vector2, 0.001);
    printf("x1 = %f\n", roots2[0]);
    printf("x2 = %f\n", roots2[1]);
    printf("x3 = %f\n", roots2[2]);
    //printf("%f %f %f\n", matrix[2][0], matrix[2][1], matrix[2][2]);
    return 0;
}