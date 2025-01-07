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