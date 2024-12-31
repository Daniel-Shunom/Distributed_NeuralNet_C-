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

#include <iostream>
#include "HyperParams.h"

//Instantion of Propagation class
Propagation props;

//HyperParams class constructor initializes Node struct members
//with input parameters
HyperParams::HyperParams() {
    node.computed_activations = props.tanh_activations(props.params.input);
    node.learning_rate = LEARNING_RATE;
}

//To allocate memory at compile time
std::array<float, HIDDEN_NODES> HyperParams::allocate_memory(std::array<Node*, HIDDEN_NODES> hidden_nodes,
                                                             std::array<Node*, HIDDEN_NODES> next_nodes) {}

//returns the computed activations
//might be too abstracted
std::vector<float> HyperParams::hidden_unit(std::vector<float> activations) {
    return node.computed_activations;
}

//This is designed to iterate over h_params.hidden_nodes, and for each outer iteration
// an innner iteration is performed to connect the nodes of that current layer to the 
// nodes of the next layer.
std::vector<std::vector<float>> HyperParams::hidden_layer(std::array<Node*, HIDDEN_NODES> &hidden_nodes,
                                                          std::array<Node*, HIDDEN_NODES> &next_nodes) {
    //initializing hidden layer matrix
    std::vector<std::vector<float>> activations(2, std::vector<float>(HIDDEN_NODES, 0.0f));

    for (int i = 0; i < hidden_nodes.size(); i++) {
        if (hidden_nodes[i]) {
            for (int j = 0; j < next_nodes.size(); j++) {
                next_nodes[j]->computed_activations = node.computed_activations;
                hidden_nodes[i]->hidden_nodes[j] = next_nodes[j];
                activations[i][j] = hidden_nodes[i]->computed_activations[j];
            }
        }
    }
    return activations;
}

//overloaded function using vectors
std::vector<std::vector<float>> HyperParams::hidden_layer(std::vector<Node*> &hidden_nodes,
                                                          std::vector<Node*> &next_nodes) {
    std::vector<std::vector<float>> activations(2, std::vector<float>(HIDDEN_NODES, 0.0f));
    for (int i = 0; i < hidden_nodes.size(); i++) {
        if (hidden_nodes[i]) {
            for (int j = 0; j < next_nodes.size(); j++) {
                next_nodes[j]->computed_activations = node.computed_activations;
                hidden_nodes[i]->hidden_nodes[j] = next_nodes[j];
                activations[i][j] = hidden_nodes[i]->computed_activations[j];
            }
        }
    }
    return activations;
}

//This constructs the deep net with all interconnected nodes
std::vector<HyperParams::Node> HyperParams::deep_net_constructor(std::vector<
                                                                 std::array<Node*, 
                                                                 HIDDEN_NODES>> &layers) {
    std::vector<Node> layer_activations;
    for (int i = 0; i < HIDDEN_LAYERS; i++) {
        std::vector<std::vector<float>> layer_activations = hidden_layer(layers[i], 
                                                                         layers[i+1]);
    }
    return layer_activations;
}

std::vector<HyperParams::Node> HyperParams::input_layer_constructor(std::vector<Node*> &input_nodes,
                                                                    std::vector<Node*> &layers) {
    std::vector<Node> layer_activations;
    for (int i = 0; i < INPUT_NODES; i++) {
        std::vector<std::vector<float>> layer_activations = hidden_layer(input_nodes, 
                                                                         layers);
    }
    return layer_activations;
}

std::vector<HyperParams::Node> HyperParams::output_layer_constructor(std::vector<Node*> &layers,
                                                                     std::vector<Node*> &output_nodes) {
    std::vector<Node> layer_activations;
    for (int i = 0; i < HIDDEN_LAYERS; i++) {
        std::vector<std::vector<float>> layer_activations = hidden_layer(layers, 
                                                                         output_nodes);
    }
    return layer_activations;
}

//change the learning rate
void HyperParams::change_learning_rate(float &new_rate) {
    node.learning_rate =  new_rate;
}

HyperParams::~HyperParams() {
    std::string Deallocator = "[DESTRUCTOR CALLED!]\n[DEALLOCATING MEMORY...]\n";
    for (int i = 0; i < HIDDEN_NODES; i++) {
        delete node.hidden_nodes[i];
    }
}