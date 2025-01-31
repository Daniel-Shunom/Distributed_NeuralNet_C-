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
#include <stdexcept>
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
void HyperParams::hidden_layer(rP_Nd &h_nodes,
                               rP_Nd &n_nodes,
                               int depth) {
    
    if (depth == 0 || h_nodes.empty() || n_nodes.empty()) {
        return;
    }

    for (Node* &n: h_nodes) {
        n = new Node();
        for (int i = 0; i < n_nodes.size(); i++) {
            n->next_node.push_back(new Node());
        }
    }

    for (Node* n: n_nodes) {
        n = new Node();
        for (int i = 0; i < n_nodes.size(); i++) {
            n->next_node.push_back(new Node());
        }
    }

    for (int i = 0; i < h_nodes.size(); i++) {
        for (int j = 0; j < n_nodes.size(); j++) {
            h_nodes[i]->next_node[j] = n_nodes[j];
        }
    }

    rP_Nd new_layer;

    hidden_layer(n_nodes, new_layer, depth-1);
    std::cout << "LAYER BUILDER FUNCTION CALLED\n";
}

void HyperParams::hidden_layer_destructor(Nd &hidden_nodes, Nd &next_nodes, int depth) {
    
    for (int i = 0; i < hidden_nodes.size(); i++) {
        for (int j = 0; j < next_nodes.size(); j++) {
            std::cout << &next_nodes[j];
        }
        std::cout << &hidden_nodes[i];
    }
}

//Constructs a fully connected Neural Network with (int depth) layers
void HyperParams::hidden_layer(Nd &h_nodes, Nd &n_nodes, LC &cache, int depth) {
    std::cout << "LAYER BUILDER FUNCTION CALLED\n";
    static int count = 0;

    for (auto &n: h_nodes) {
        n.next_node.resize(n_nodes.size());
    };

    for (int i = 0; i < h_nodes.size(); i++) {
        for (int j = 0; j < n_nodes.size(); j++) {
            h_nodes[i].next_node[j] = &n_nodes[j];
        }
    }

    count++;
    cache.push_back(h_nodes);

    std::cout << "[LAYER: " << count << " ] " <<"h_nodes-> contains: " << h_nodes.size() << " pointers\n";
    std::cout << "[LAYER: " << count << " ] " << "n_nodes-> contains: " << n_nodes.size() << " items\n";

    std::cout << "[LAYER CACHE ITEMS: " << cache.size() << ']' << std::endl;
    std::cout << std::endl;

    if (depth > 1) {
        Nd new_layer(n_nodes.size());
        
        hidden_layer(n_nodes, new_layer, cache, depth-1);
    }

    if (depth == 0 || h_nodes.empty() || n_nodes.empty()) {
        return;
    }
}


//Intializes Node Weights and Biases with random Floats
void HyperParams::parameter_initializer(Nd &input, vMatrix* m1) {
    static int count = 0;

    std::tuple dims = returnDimensions(m1); 
    auto rows = std::get<0>(dims);
    auto cols = std::get<1>(dims);
     
    for (int i = 0; i < input.size(); i++) {
        for (auto &next_n: input[i].next_node) {
            if (!next_n) {
                std::cout<< "Creating new node...\n"; 
                next_n = new Node();
            }
        }

        input[i].Weights = v_matrix_create(rows, cols);
        input[i].Biases = v_matrix_create(rows, 1);

        v_matrix_randomize(input[i].Weights, 2);
        v_matrix_randomize(input[i].Biases, 2);
    }

    count++;
    std::cout << "Initialized parameters for layer: " << count << std::endl;
}

//Calls parameter_intializer on each layer stored in the cache
void HyperParams::cache_initializer(LC &cache, vMatrix* m1) {
    std::cout << "\n\n[CACHE WEIGHTS INTIALIZER CALLED!]" << std::endl;
    std::cout<< "[CACHE SIZE: " << cache.size() << "]\n" << std::endl;
    if (!m1 || cache.empty()) {
        std::cout << "[ERROR: INVALID PARAMETERS!]" << std::endl;
        return;
    }

    int static count = 0;

    for (int i = 0; i < cache.size(); i++) {
        parameter_initializer(cache[i], m1);
        count++;
        std::cout << "[CACHE WEIGHTS INTIALIZED AT LAYER: " << count << ']' <<std::endl;
    }

    std::cout << "[CACHED LAYERS: " << count << ']' << std::endl;
    std::cout << "[CACHE WEIGHTS INTIALIZED!]" <<std::endl;
}

std::vector<Node> HyperParams::output_layer_constructor(Nd &layers,
                                                        Nd &output_nodes) 
                                                        {
    std::vector<Node> layer_activations;
    for (int i = 0; i < HIDDEN_LAYERS; i++) {
        std::vector<std::vector<double>> layer_activations;
    }
    return layer_activations;
}

//change the learning rate
void HyperParams::change_learning_rate(double &new_rate) {
    node.learning_rate =  new_rate;
}

HyperParams::~HyperParams() {
    std::string Deallocator = "[DESTRUCTOR CALLED!]\n[DEALLOCATING MEMORY...]\n";
    //for (int i = 0; i < HIDDEN_NODES; i++) {
    //    delete node.hidden_nodes[i];
    //}
}