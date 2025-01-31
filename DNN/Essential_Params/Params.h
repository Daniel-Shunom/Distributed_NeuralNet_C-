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

#define INPUT_LAYERS 2
#define HIDDEN_LAYERS 8
#define OUTPUT_LAYERS 2

#define INPUT_NODES 4
#define HIDDEN_NODES 20
#define OUTPUT_NODES 2
#define EPOCHS 12
#define LEARNING_RATE 0.01f


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

typedef struct {
    vMatrix* img_data;
    int label;
} Img;

struct Node {
    vMatrix* inputs;
    vMatrix* Weights;
    vMatrix* Biases;
    vMatrix* Activations;
    
    std::vector<double> computed_activations;
    double learning_rate;
    std::vector<Node*> next_node;
};

typedef std::array<Node*, INPUT_NODES> rI_Nd;
typedef std::array<Node*, HIDDEN_NODES> rP_Nd;
typedef std::array<Node*, OUTPUT_NODES> rO_Nd;
typedef std::vector<Node> Nd;
typedef std::vector<Node*> P_Nd;
typedef std::vector<Nd> LC;