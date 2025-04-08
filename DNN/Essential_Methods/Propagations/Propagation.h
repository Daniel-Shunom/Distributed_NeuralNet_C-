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

#pragma once

#include "../Data_Operations/DataOps.h"
#include "../Data_Operations/MatrixOps.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

class Propagation: public MatrixOps {
public: 
    struct Parameters {
        std::vector<double> weights;
        std::vector<double> biases;
        std::vector<double> input;
        double input_y;
        double input_yhat;
        Parameters(): weights(5), biases(5), input(5) {};
    };
    
    struct Errors {
        std::string weight_off   = "WEIGHT VECTOR DOES NOT MATCH INPUT VECTOR\n";
        std::string bias_off     = "BIAS VECTOR DOES NOT MATCH INPUT VECTOR\n";
    };
    
    struct Initializer {
        std::string start_weight = "[INITIALIZING WEIGHTS....]\n";
        std::string start_bias   = "[INITIALIZING BIASES.....]\n\n";

        std::string init_weight  = "[WEIGHTS INITIALIZED!]\n";
        std::string init_bias    = "[BIASES INITIALIZED! ]\n\n";
    };


    Parameters params;
    Errors prop_error;
    Initializer _init;
    MatrixOps mp;
    
    Propagation();
    
    /// @brief Performs the forward pass calculation Z = Wx + b
    /// @param m Input matrix
    /// @param w Weights matrix
    /// @param b Bias matrix
    /// @return vMatrix Z
    std::shared_ptr<vMatrix> v_forwardpass (
	    std::shared_ptr<vMatrix> m, 
	    std::shared_ptr<vMatrix> w, 
	    std::shared_ptr<vMatrix> b
    );

    /// @brief Sigmoid Activation function
    /// @param m Input matrix
    /// @return activated matrix A
    std::shared_ptr<vMatrix> v_sigmoid_activation(std::shared_ptr<vMatrix> m);

    /// @brief Tanh Activation function
    /// @param m Input matrix
    /// @return activated matrix A
    std::shared_ptr<vMatrix> v_tanh_activation(std::shared_ptr<vMatrix> m);

    /// @brief ReLU Activation function
    /// @param m Input matrix
    /// @return activated matrix A
    std::shared_ptr<vMatrix> v_relu_activation(std::shared_ptr<vMatrix> m);
    
    /// @brief Leaky ReLU Activation function
    /// @param m Input matrix
    /// @return activated matrix A
    std::shared_ptr<vMatrix> v_leaky_relu_activation(std::shared_ptr<vMatrix> m);
    
    /// @brief Cross Entropy Loss function
    /// @param input_y 
    /// @param label_yhat 
    /// @return Cross Entropy Loss
    double v_cross_entropy_loss (
	    std::shared_ptr<vMatrix> &input_y, 
	    std::shared_ptr<vMatrix> &label_yhat
    );

    double cross_entropy_loss(double &input_y, double &label_yhat);

    /// @brief Cost function
    /// @param cost 
    /// @return Cost of iteration in Epoch
    double cost_function(double &cost);
    
    /// @brief Checks if the input size matches the weight and bias size
    /// @param _weights 
    /// @param _biases 
    /// @param input 
    /// @return Returns error message if input size does not match weight and bias size
    std::string error_check (
	    std::vector<double> &_weights, 
	    std::vector<double> &_biases,
        std::vector<double> &input
    );

};
