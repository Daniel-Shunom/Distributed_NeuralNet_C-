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

#include "Propagation.h"


Propagation::Propagation(){
    std::cout << _init.start_weight << _init.start_bias;

    for (int i = 0; i < params.weights.size(); i++) {
        params.weights[i] = (double)rand()/(double)RAND_MAX;
        params.biases[i] =  (double)rand()/(double)RAND_MAX;
    }
     
    std::cout << _init.init_weight << _init.init_bias;

    std::cout << "[WEIGHTS] ";
    for (int i = 0; i < params.weights.size(); i++) {
        std::cout << params.weights[i] << "  ";
    }
    std::cout << "\n";

    std::cout << "[BIASES ] ";
    for (int i = 0; i < params.biases.size(); i++) {
        std::cout << params.biases[i] << "  ";
    }
    std::cout << "\n\n";
};

std::string Propagation::error_check(std::vector<double> &_weights,
                                     std::vector<double> &_biases,
                                     std::vector<double> &input) 
{
    if(_weights.size() != input.size()) {
        return prop_error.weight_off;
    }
    if (_biases.size() != input.size()) {
        return prop_error.bias_off;
    }
    else {
        std::cout << "[GOOD TO GO!]\n\n";
    }
    return "ok";
}

std::shared_ptr<vMatrix> Propagation::v_forwardpass(std::shared_ptr<vMatrix> m, std::shared_ptr<vMatrix> w, std::shared_ptr<vMatrix> b) {
    std::shared_ptr<vMatrix> mat = mp.v_matrix_multiply(m, w);
    std::shared_ptr<vMatrix> Z = mp.v_matrix_add(mat, b);

    return Z;
}

std::shared_ptr<vMatrix> Propagation::v_sigmoid_activation(std::shared_ptr<vMatrix> Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            Z->entries[i][j] = 1/(1+std::exp(-Z->entries[i][j]));;
        }
    }

    return Z;
}

std::shared_ptr<vMatrix> Propagation::v_tanh_activation(std::shared_ptr<vMatrix> Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            Z->entries[i][j] = tanh(Z->entries[i][j]);
        }
    }

    return Z;
}

std::shared_ptr<vMatrix> Propagation::v_relu_activation(std::shared_ptr<vMatrix> Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            int k = Z->entries[i][j];
            Z->entries[i][j] = std::max(0, k);
        }
    }

    return Z;
}

std::shared_ptr<vMatrix> Propagation::v_leaky_relu_activation(std::shared_ptr<vMatrix> Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            int k = Z->entries[i][j];
            int k1 = Z->entries[i][j]*0.0001;
            Z->entries[i][j] = std::max(k1, k);
        }
    }

    return Z;
}

double Propagation::cross_entropy_loss(double &input_y, double &input_yhat) {
    double loss = -(input_y*log(input_yhat) + (1-input_y)*log(1-input_yhat));
    return loss;
}

double Propagation::cost_function(double &cost) {
    cost = cross_entropy_loss(params.input_y, params.input_yhat)/params.input.size();
    return cost;
}