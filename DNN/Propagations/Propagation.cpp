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

//Ensuring input size mathces weight and bias size
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

//Forward propagation
vMatrix* Propagation::v_forwardpass(vMatrix* m, vMatrix* w, vMatrix* b) {
    vMatrix* mat = mp.v_matrix_multiply(m, w);
    vMatrix* Z = mp.v_matrix_add(mat, b);

    return Z;
}

//Sample sigmoid Activation
vMatrix* Propagation::v_sigmoid_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            Z->entries[i][j] = 1/(1+std::exp(-Z->entries[i][j]));;
        }
    }

    return Z;
}

//tanh activation function
vMatrix* Propagation::v_tanh_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            Z->entries[i][j] = tanh(Z->entries[i][j]);
        }
    }

    return Z;
}

//relu activation functiuon
vMatrix* Propagation::v_relu_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            int k = Z->entries[i][j];
            Z->entries[i][j] = std::max(0, k);
        }
    }

    return Z;
}

//leaky relu activation function
vMatrix* Propagation::v_leaky_relu_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            int k = Z->entries[i][j];
            int k1 = Z->entries[i][j]*0.0001;
            Z->entries[i][j] = std::max(k1, k);
        }
    }

    return Z;
}

//cross entropy loss function
double Propagation::cross_entropy_loss(double &input_y, double &input_yhat) {
    double loss = -(input_y*log(input_yhat) + (1-input_y)*log(1-input_yhat));
    return loss;
}

//calculates cost
double Propagation::cost_function(double &cost) {
    cost = cross_entropy_loss(params.input_y, params.input_yhat)/params.input.size();
    return cost;
}