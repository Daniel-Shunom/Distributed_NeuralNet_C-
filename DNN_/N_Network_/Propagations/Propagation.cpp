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
        params.weights[i] = (float)rand()/(double)RAND_MAX;
        params.biases[i] = (float)rand()/(double)RAND_MAX;
    }
     
    std::cout << _init.init_weight << _init.init_bias;
};

//Ensuring input size mathces weight and bias size
std::string Propagation::error_check(std::vector<float> &_weights,
                                     std::vector<float> &_biases,
                                     std::vector<float> &input) 
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
std::vector<float> Propagation::forwardpass(std::vector<float> &_weights, 
                                            std::vector<float> &_biases, 
                                            std::vector<float> &input) {
    std::vector<float> Z(input.size());
    std::string Err = error_check(_weights, _biases, input);

    if (input.size() != _weights.size() || input.size() != _biases.size()) {
        std::cerr << "[ERROR]: " << Err;
    }

    for (int i = 0; i < input.size(); ++i) {
        Z[i] = _weights[i]*input[i] + _biases[i];
    }

    return Z;
}

//Sample sigmoid Activation
std::vector<float> Propagation::sigmoid_activations(std::vector<float> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    assert(Z.size() == params.input.size() && error_check(params.weights, 
                                                          params.biases, 
                                                          params.input) == "ok");
    std::vector<float> A(Z.size());

    for (int i = 0; i < Z.size(); ++i) {
        A[i] = 1/(1+std::exp(-Z[i]));
    }
    
    return Z;
}

//tanh activation function
std::vector<float> Propagation::tanh_activations(std::vector<float> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    std::vector<float> A(Z.size());

    for (int i = 0; i < Z.size(); ++i) {
        A[i] = tanh(Z[i]);
    }

    return A;
}

//relu activation functiuon
std::vector<float> Propagation::relu_activations(std::vector<float> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    std::vector<float> A(Z.size());

    std::transform(Z.begin(), Z.end(), A.begin(), 
                   [&](float x){return std::max(0.0f, x);});

    return A;
}

//leaky relu activation function
std::vector<float> Propagation::leaky_relu_activations(std::vector<float> &Z) {
    Z = forwardpass(params.weights, params.biases, params.input);
    std::vector<float> A(Z.size());

    std::transform(Z.begin(), Z.end(), A.begin(), 
                   [&](float x){return std::max(0.001f*x, x);});
    return A;
}

//cross entropy loss function
float Propagation::cross_entropy_loss(float &input_y, float &input_yhat) {
    float loss = -(input_y*log(input_yhat) + (1-input_y)*log(1-input_yhat));
    return loss;
}

//calculates cost
float Propagation::cost_function(float &cost) {
    cost = cross_entropy_loss(params.input_y, params.input_yhat)/params.input.size();
    return cost;
}