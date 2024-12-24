/*
Author: Daniel S. Jeremiah
Date: December 23, 2024

Description:
This file contains the propagation functions for the neural network. 
Note that not all possible functions have been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/
#ifndef PROPAGATION
#define PROPAGATION

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

class Propagation {
public: 
    struct Parameters {
        std::vector<float> weights;
        std::vector<float> biases;
        std::vector<float> input;
        float input_y;
        float input_yhat;
    };
    
    struct Errors {
        std::string weight_off = "WEIGHT VECTOR DOES NOT MATCH INPUT VECTOR\n";
        std::string bias_off = "BIAS VECTOR DOES NOT MATCH INPUT VECTOR\n";
    };
    
    struct Initializer {
        std::string start_weight = "[INITIALIZING WEIGHTS....]\n";
        std::string start_bias = "[INITIALIZING BIASES....]\n";

        std::string init_weight = "[WEIGHTS INITIALIZED!]\n";
        std::string init_bias = "[BIASES INITIALIZED!]\n";
    };


    Parameters params;
    Errors prop_error;
    Initializer _init;
    
    std::string error_check(std::vector<float> _weights, 
                            std::vector<float> _biases,
                            std::vector<float> input);

    Propagation();
    std::vector<float> forwardpass(std::vector<float> _weights, 
                                   std::vector<float> _biases, 
                                   std::vector<float> input);

    std::vector<float> sigmoid_activations(std::vector<float> Z);
    std::vector<float> tanh_activations(std::vector<float> Z);
    std::vector<float> relu_activations(std::vector<float> Z);
    std::vector<float> leaky_relu_activations(std::vector<float> Z);

    float cross_entropy_loss(float input_y, float label_yhat);

    float cost_function(float cost);
};

#endif