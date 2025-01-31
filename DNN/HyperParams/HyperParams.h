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

#include "../Propagations/Propagation.h"
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <cmath>

class HyperParams: public Propagation {
public:
    struct H_Params {
        int layers;
        int nodes;
        double learning_rate;

        std::vector<double> weights;
        std::vector<int> biases;

        std::vector<double> input_x;
        std::vector<double> x_hat;
        std::array<double, HIDDEN_LAYERS> hidden_layers;
        H_Params *data;
    };

    Node node;
    H_Params h_params;

    HyperParams();
    ~HyperParams();
    
    std::array<double, HIDDEN_NODES> allocate_memory(rP_Nd input_nodes, rP_Nd next_nodes);

    std::vector<double> hidden_unit(std::vector<double> activations);

    void hidden_layer(Nd &input_nodes, Nd &next_nodes, LC &cache, int depth);
    void hidden_layer_destructor(Nd &input_nodes, Nd &next_nodes, int depth);
    void hidden_layer(rP_Nd &input_nodes, rP_Nd &next_nodes, int depth);
    void hidden_layer_destructor(rP_Nd &input_nodes, rP_Nd &next_nodes);
    void parameter_initializer(Nd &input, std::shared_ptr<vMatrix> m1);
    void cache_initializer(LC &input, std::shared_ptr<vMatrix> m1);
    void change_learning_rate(double &learning_rate);

    //array form
    std::vector<Node> input_layer_constructor(std::vector<rI_Nd> &input_nodes, std::vector<rP_Nd> &hidden_nodes);
    std::vector<Node> output_layer_constructor(std::vector<rP_Nd> &layers, std::vector<rO_Nd> &output_nodes);
    
    //vector form
    std::vector<Node> input_layer_constructor(Nd &input_nodes, Nd &hidden_nodes);
    std::vector<Node> output_layer_constructor(Nd &layers, Nd &output_nodes);
                                               
    std::vector<Node> deep_net_constructor(std::vector<rP_Nd> &layers);
};