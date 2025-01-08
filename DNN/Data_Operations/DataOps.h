/*
Author: Daniel S. Jeremiah
Date: January 6, 2024

Description:
This file contains the Matrix operation functions for the neural 
network. Note that not all possible functions have been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/

#pragma once

#define MAX_CHAR 100
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

typedef struct {
    double** entries;
    int rows;
    int cols;
} Matrix;

typedef struct {
    std::vector<std::vector<double>> entries;
    int rows;
    int cols;
} vMatrix;

class DataOps { 
public:
    struct Input {
        std::vector<float> weights;
        std::vector<float> biases;
        std::vector<float> input;
        float input_y;
        float label_yhat;
    };
    vMatrix* v_matrix_load(char *file_string);
    vMatrix* v_matrix_create(int row, int col);
    vMatrix* v_matrix_flatten(vMatrix *m, int axis);
    vMatrix* v_matrix_copy(vMatrix* m);

    void v_matrix_save(vMatrix *m, char *file_String);
    void v_matrix_randomize(vMatrix *m, int n);
    void v_matrix_fill(vMatrix *m, int n);
    void v_matrix_print(vMatrix *m);
    void v_matrix_free(vMatrix *m);


    Matrix* matrix_load(char *file_string);
    Matrix* matrix_flatten(Matrix *m, int axis);
    Matrix* matrix_create(int row, int col);
    Matrix* matrix_copy(Matrix* m);

    double uniform_distribution(double low, double high);

    void matrix_save(Matrix *m, char *file_String);
    void matrix_randomize(Matrix *m, int n);
    void matrix_fill(Matrix *m, int n);
    void matrix_print(Matrix *m);
    void matrix_free(Matrix *m);

    int matrix_argmax(Matrix *m);
    int matrix_argmax(vMatrix *m);

    void weight_update();
    void weight_cache();
    void bias_update();
    void bias_cache();

    void input_norm();
    void input_sort();
    void input_format();
    void input_classify();

    DataOps(/* args */);
    ~DataOps();
};
