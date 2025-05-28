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

#pragma once

#include "DataOps.h"
#include <iostream>
#include <variant>
#include <tuple>

class MatrixOps: public DataOps {
private:
    /* data */
public:
    static bool checkDimensions(Matrix* m1, Matrix* m2);

    /// @brief Compares the dimensions of two vector matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return bool
    static bool checkDimensions(matrix_obj m1, matrix_obj m2);

    /// @brief Returns the dimensions of a vector matrix
    /// @param m1 Reference image matrix
    /// @return Row and column dimensions
    static std::tuple<int, int> returnDimensions(matrix_obj m1);

    /// @brief Overloaded add function with array matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return sum of the two matrices
    Matrix* matrix_add(Matrix* m1, Matrix* m2);

    /// @brief Subtracts two array matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return difference of the two matrices
    Matrix* matrix_subtract(Matrix* m1, Matrix* m2);
    
    /// @brief Multiplies two array matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return product of the two matrices
    Matrix* matrix_multiply(Matrix* m1, Matrix* m2);

    /// @brief Divides two array matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return division of the two matrices
    Matrix* matrix_divide(Matrix* m1, Matrix* m2);

    /// @brief Scales an array matrix
    /// @param n matrix 1
    /// @param m matrix 2
    /// @return scaled matrix
    Matrix* matrix_scale(double n, Matrix* m);

    /// @brief Computes the dot product of two array matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return dot product of the two matrices
    Matrix* matrix_dot(Matrix* m1, Matrix* m2);

    /// @brief Applies a function to an array matrix
    /// @param func pointer to function
    /// @param m input matrix
    /// @return resulting matrix
    Matrix* matrix_apply(double (*func)(double), Matrix* m);

    /// @brief Transposes an array matrix
    /// @param m1 input matrix
    /// @return transposed matrix
    Matrix* matrix_transpose(Matrix* m1);

    /// @brief Adds a scalar to an array matrix
    /// @param n scalar value
    /// @param m input matrix
    /// @return resulting matrix
    Matrix* matrix_add_scalar(double n, Matrix* m);

    /// @brief Adds two vector matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return sum of the two matrices
    matrix_obj v_matrix_add(matrix_obj m1, matrix_obj m2);

    /// @brief Subtracts two vector matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return difference of the two matrices
    matrix_obj v_matrix_subtract(matrix_obj m1, matrix_obj m2);

    /// @brief Multiplies two vector matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return product of the two matrices
    matrix_obj v_matrix_multiply(matrix_obj m1, matrix_obj m2);
    
    /// @brief Divides two vector matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return division of the two matrices
    matrix_obj v_matrix_divide(matrix_obj m1, matrix_obj m2);

    /// @brief Scales a vector matrix
    /// @param n value to scale by
    /// @param m input matrix
    /// @return scaled matrix
    matrix_obj v_matrix_scale(double n, matrix_obj m);

    /// @brief Computes the dot product of two vector matrices
    /// @param m1 matrix 1
    /// @param m2 matrix 2
    /// @return dot product of the two matrices
    matrix_obj v_matrix_dot(matrix_obj m1, matrix_obj m2);

    /// @brief Applies a function to a vector matrix
    /// @param func function pointer
    /// @param m input matrix
    /// @return resulting matrix
    matrix_obj v_matrix_apply(double (*func)(double), matrix_obj m);

    /// @brief Transposes a vector matrix
    /// @param m1 input matrix
    /// @return transposed matrix
    matrix_obj v_matrix_transpose(matrix_obj m1);

    /// @brief adds a scalar to a vector matrix
    /// @param n scalar value
    /// @param m input matrix
    /// @return resulting matrix
    matrix_obj v_matrix_add_scalar(double n, matrix_obj m);
    
    //MatrixOps(/* args */);
    //~MatrixOps();
};
