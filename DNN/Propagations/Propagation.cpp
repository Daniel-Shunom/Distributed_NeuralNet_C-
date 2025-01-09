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
std::vector<double> Propagation::forwardpass(std::vector<double> &_weights, 
                                            std::vector<double> &_biases, 
                                            std::vector<double> &input) {
    std::vector<double> Z(input.size());
    std::string Err = error_check(_weights, _biases, input);

    if (input.size() != _weights.size() || input.size() != _biases.size()) {
        std::cerr << "[ERROR]: " << Err;
    }

    for (int i = 0; i < input.size(); ++i) {
        Z[i] = _weights[i]*input[i] + _biases[i];
    }

    return Z;
}

vMatrix* Propagation::v_forwardpass(vMatrix* m, vMatrix* w, vMatrix* b) {
    vMatrix* mat = mp.v_matrix_multiply(m, w);
    vMatrix* Z = mp.v_matrix_add(mat, b);

    return Z;
}

//Sample sigmoid Activation
std::vector<double> Propagation::sigmoid_activations(std::vector<double> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    std::vector<double> A(Z.size());

    for (int i = 0; i < Z.size(); ++i) {
        A[i] = 1/(1+std::exp(-Z[i]));
    }
    
    return Z;
}

vMatrix* Propagation::v_sigmoid_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            Z->entries[i][j] = 1/(1+std::exp(-Z->entries[i][j]));;
        }
    }
}

//tanh activation function
std::vector<double> Propagation::tanh_activations(std::vector<double> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    std::vector<double> A(Z.size());

    for (int i = 0; i < Z.size(); ++i) {
        A[i] = tanh(Z[i]);
    }

    return A;
}

vMatrix* Propagation::v_tanh_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            Z->entries[i][j] = tanh(Z->entries[i][j]);
        }
    }
}

//relu activation functiuon
std::vector<double> Propagation::relu_activations(std::vector<double> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    std::vector<double> A(Z.size());

    std::transform(Z.begin(), Z.end(), A.begin(), 
                   [&](double x){return std::max(0.0, x);});

    return A;
}

vMatrix* Propagation::v_relu_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            int k = Z->entries[i][j];
            Z->entries[i][j] = std::max(0, k);
        }
    }
}

//leaky relu activation function
std::vector<double> Propagation::leaky_relu_activations(std::vector<double> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    std::vector<double> A(Z.size());

    std::transform(Z.begin(), Z.end(), A.begin(), 
                   [&](double x){return std::max(0.001f*x, x);});
    return A;
}

vMatrix* Propagation::v_leaky_relu_activation(vMatrix* Z) {
    for (int i = 0; i < Z->rows; i++) {
        for (int j = 0; j < Z->cols; j++) {
            int k = Z->entries[i][j];
            int k1 = Z->entries[i][j]*0.0001;
            Z->entries[i][j] = std::max(k1, k);
        }
    }
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