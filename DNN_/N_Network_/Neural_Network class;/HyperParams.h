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

#ifndef HYPER_PARAMS
#define HYPER_PARAMS

#define INPUT_LAYERS 2
#define HIDDEN_LAYERS 8
#define OUTPUT_LAYERS 2

#define INPUT_NODES 4
#define HIDDEN_NODES 20
#define OUTPUT_NODES 2
#define EPOCHS 12
#define LEARNING_RATE 0.01f

#include "../Propagations/Propagation.cpp"
#include "../Propagations/Propagation.h"
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <cmath>

class HyperParams {
public:
    struct Node {
        std::vector<float> computed_activations;
        float learning_rate;

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
        float learning_rate;

        std::vector<float> weights;
        std::vector<int> biases;

        std::vector<float> input_x;
        std::vector<float> x_hat;
        std::array<float, HIDDEN_LAYERS> hidden_layers;
        H_Params *data;
    };

    Node node;
    H_Params h_params;

    HyperParams();
    ~HyperParams();
    
    std::array<float, HIDDEN_NODES> allocate_memory(std::array<Node*, HIDDEN_NODES> input_nodes,
                                                    std::array<Node*, HIDDEN_NODES> next_nodes);
    std::vector<float> hidden_unit(std::vector<float> activations);
    std::vector<std::vector<float>> hidden_layer(std::array<Node*, HIDDEN_NODES> &input_nodes, 
                      std::array<Node*, HIDDEN_NODES> &next_nodes);
    std::vector<Node> deep_net_constructor(std::vector<std::array<Node*, HIDDEN_NODES>>& layers);
    void change_learning_rate(float &learning_rate);

};



#endif