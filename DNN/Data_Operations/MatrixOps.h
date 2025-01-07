#ifndef MATRIX_OPS
#define MATRIX_OPS

#include "DataOps.h"
#include <iostream>

class MatrixOps
{
private:
    /* data */
public:
    DataOps::Matrix* matrix_add();
    DataOps::Matrix* matrix_subtract();
    DataOps::Matrix* matrix_multiply();
    DataOps::Matrix* matrix_divide();
    DataOps::Matrix* matrix_scale();
    DataOps::Matrix* matrix_dot();
    DataOps::Matrix* matrix_transpose();
    DataOps::Matrix* matrix_add_scalar();

    MatrixOps(/* args */);
    ~MatrixOps();
};


#endif