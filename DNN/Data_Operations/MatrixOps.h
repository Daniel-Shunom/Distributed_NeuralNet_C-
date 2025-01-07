/*
Author: Daniel S. Jeremiah
Date: January 6, 2024

Description:
This file contains the Matrix operation functions for the neural 
network and input data. Note that not all possible functions have 
been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/

#ifndef MATRIX_OPS
#define MATRIX_OPS

#include "DataOps.h"
#include <iostream>

class MatrixOps
{
private:
    /* data */
public:
    Matrix* matrix_add(Matrix* m1, Matrix* m2);
    Matrix* matrix_subtract(Matrix* m1, Matrix* m2);
    Matrix* matrix_multiply(Matrix* m1, Matrix* m2);
    Matrix* matrix_divide(Matrix* m1, Matrix* m2);
    Matrix* matrix_scale(double n, Matrix* m);
    Matrix* matrix_dot(Matrix* m1, Matrix* m2);
    Matrix* matrix_apply(double (*func)(double), Matrix* m);
    Matrix* matrix_transpose(Matrix m1, Matrix m2);
    Matrix* matrix_add_scalar(double n, Matrix* m);

    MatrixOps(/* args */);
    ~MatrixOps();
};


#endif