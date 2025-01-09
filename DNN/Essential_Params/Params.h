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
} Weights;

typedef struct {
    std::vector<std::vector<double>> entries;
    int rows;
    int cols;
} Bias;