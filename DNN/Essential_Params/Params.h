/*
Author: Daniel S. Jeremiah
Date: January 8, 2024

Description:
This file contains the aliased for the parameters of the neural 
network. Note that not all possible functions have been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/

#pragma once

#include <vector>

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

typedef struct {
    std::vector<std::vector<double>> entries;
    int rows;
    int cols;
} Weight;

typedef struct {
    std::vector<std::vector<double>> entries;
    int rows;
    int cols;
} Bias;