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

//HyperParams class constructor initializes Node struct members
//with input parameters
HyperParams::HyperParams() {
    //node.computed_activations = tanh_activations(params.input);
    node.learning_rate = LEARNING_RATE;
}

//returns the computed activations
std::vector<double> HyperParams::hidden_unit(std::vector<double> activations) {
    return node.computed_activations;
}

//This is designed to iterate over h_params.hidden_nodes, and for each outer iteration
// an innner iteration is performed to connect the nodes of that current layer to the 
// nodes of the next layer.
std::vector<std::vector<double>> HyperParams::hidden_layer(std::array<Node*, HIDDEN_NODES> &h_nodes,
                                                           std::array<Node*, HIDDEN_NODES> &n_nodes) {
    //initializing hidden layer matrix
    std::vector<std::vector<double>> activations(2, std::vector<double>(HIDDEN_NODES, 0.0f));

    for (int i = 0; i < h_nodes.size(); i++) {
        if (h_nodes[i]) {
            for (int j = 0; j < n_nodes.size(); j++) {
                n_nodes[j]->Activations->entries = node.Activations->entries;
                h_nodes[i]->hidden_nodes[j] = n_nodes[j];
                activations[i][j] = h_nodes[i]->computed_activations[j];
            }
        }
    }

    //we will cache this in a map
    //for calculating backpropagation
    //in the
    return activations;
}

void HyperParams::hidden_layer_destructor(std::vector<Node*> &hidden_nodes, std::vector<Node*> &next_nodes) {
    for (int i = 0; i < hidden_nodes.size(); i++) {
        for (int j = 0; j < next_nodes.size(); j++) {
            delete next_nodes[j];
        }
        delete hidden_nodes[i];
    }
}

//overloaded function using vectors
std::vector<std::vector<double>> HyperParams::hidden_layer(std::vector<Node*> &h_nodes,
                                                          std::vector<Node*> &n_nodes) {
    std::vector<std::vector<double>> activations(2, std::vector<double>(HIDDEN_NODES, 0.0f));
    for (int i = 0; i < h_nodes.size(); i++) {
        if (h_nodes[i]) {
            for (int j = 0; j < n_nodes.size(); j++) {
                n_nodes[j]->Activations->entries = node.Activations->entries;
                h_nodes[i]->hidden_nodes[j] = n_nodes[j];
                activations[i][j] = h_nodes[i]->computed_activations[j];
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
        std::vector<std::vector<double>> layer_activations = hidden_layer(layers[i], 
                                                                         layers[i+1]);
    }
    return layer_activations;
}

std::vector<HyperParams::Node> HyperParams::input_layer_constructor(std::vector<Node*> &input_nodes,
                                                                    std::vector<Node*> &layers) {
    std::vector<Node> layer_activations;
    for (int i = 0; i < INPUT_NODES; i++) {
        std::vector<std::vector<double>> layer_activations = hidden_layer(input_nodes, 
                                                                         layers);
    }
    return layer_activations;
}

std::vector<HyperParams::Node> HyperParams::output_layer_constructor(std::vector<Node*> &layers,
                                                                     std::vector<Node*> &output_nodes) {
    std::vector<Node> layer_activations;
    for (int i = 0; i < HIDDEN_LAYERS; i++) {
        std::vector<std::vector<double>> layer_activations = hidden_layer(layers, 
                                                                         output_nodes);
    }
    return layer_activations;
}

//change the learning rate
void HyperParams::change_learning_rate(double &new_rate) {
    node.learning_rate =  new_rate;
}

HyperParams::~HyperParams() {
    std::string Deallocator = "[DESTRUCTOR CALLED!]\n[DEALLOCATING MEMORY...]\n";
    for (int i = 0; i < HIDDEN_NODES; i++) {
        delete node.hidden_nodes[i];
    }
}