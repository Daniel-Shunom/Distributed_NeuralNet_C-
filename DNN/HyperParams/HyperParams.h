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

#define INPUT_LAYERS 2
#define HIDDEN_LAYERS 8
#define OUTPUT_LAYERS 2

#define INPUT_NODES 4
#define HIDDEN_NODES 20
#define OUTPUT_NODES 2
#define EPOCHS 12
#define LEARNING_RATE 0.01f

#include "../Propagations/Propagation.h"
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <cmath>

class HyperParams: public Propagation {
public:
    struct Node {
        vMatrix* Activations;
        std::vector<double> computed_activations;
        double learning_rate;

        //Eight hidden_node instantiations
        //each insantiation has 20 nodes in it
        //each node
        std::array<Node*, OUTPUT_NODES> input_nodes;
        std::array<Node*, HIDDEN_NODES> hidden_nodes;
        std::array<Node*, OUTPUT_NODES> output_nodes;
    };

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
    
    std::array<double, HIDDEN_NODES> allocate_memory(std::array<Node*, HIDDEN_NODES> input_nodes,
                                                     std::array<Node*, HIDDEN_NODES> next_nodes);

    std::vector<double> hidden_unit(std::vector<double> activations);
    std::vector<std::vector<double>> hidden_layer(std::array<Node*, HIDDEN_NODES> &input_nodes, 
                                                  std::array<Node*, HIDDEN_NODES> &next_nodes);

    std::vector<std::vector<double>> hidden_layer(std::vector<Node*> &input_nodes, 
                                                  std::vector<Node*> &next_nodes);
    
    //array form
    std::vector<Node> input_layer_constructor(std::vector<std::array<Node*, INPUT_NODES>> &input_nodes,
                                              std::vector<std::array<Node*, HIDDEN_NODES>> &hidden_nodes);
    //vector form
    std::vector<Node> input_layer_constructor(std::vector<Node*> &input_nodes,
                                              std::vector<Node*> &hidden_nodes);

    //array form
    std::vector<Node> output_layer_constructor(std::vector<std::array<Node*, HIDDEN_NODES>> &layers, 
                                               std::vector<std::array<Node*, OUTPUT_NODES>> &output_nodes);
    //vector form
    std::vector<Node> output_layer_constructor(std::vector<Node*> &layers, 
                                               std::vector<Node*> &output_nodes);
                 
                                               
    std::vector<Node> deep_net_constructor(std::vector<std::array<Node*, HIDDEN_NODES>> &layers);
    void change_learning_rate(double &learning_rate);

};