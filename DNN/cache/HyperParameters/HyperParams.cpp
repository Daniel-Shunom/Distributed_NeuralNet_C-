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
#include "./HyperParams.h"

HyperParams::HyperParams() {
    //node.computed_activations = tanh_activations(params.input);
    node.learning_rate = LEARNING_RATE;
}

std::vector<double> HyperParams::hidden_unit(std::vector<double> activations) {
    return node.computed_activations;
}

void HyperParams::hidden_layer (
    rP_Nd &h_nodes, 
    rP_Nd &n_nodes, 
    int depth
) {
    const size_t h_n = h_nodes.size();
    const size_t n_n = n_nodes.size();
    if (depth == 0 || h_nodes.empty() || n_nodes.empty()) {
        return;
    }

    for (auto &n: h_nodes) {
        n = std::make_shared<Node>();
        n->next_node.resize(n_nodes.size());
        for (size_t i = 0; i < n_n; i++) {
            n->next_node.push_back(std::make_shared<Node>());
        }
    }

    for (std::shared_ptr<Node> n: n_nodes) {
        n = std::make_shared<Node>();
        for (size_t i = 0; i < n_n; i++) {
            n->next_node.push_back(std::make_shared<Node>());
        }
    }

    for (size_t i = 0; i < h_n; i++) {
        for (size_t j = 0; j < n_n; j++) {
            h_nodes[i]->next_node[j] = n_nodes[j];
        }
    }

    rP_Nd new_layer;
    hidden_layer(n_nodes, new_layer, depth-1);
    std::cout << "LAYER BUILDER FUNCTION CALLED\n";
};

void HyperParams::hidden_layer(
    Nd &h_nodes, 
    Nd &n_nodes, 
    LC &cache, 
    int depth
) {
    static int count = 0;
    const size_t h_n = h_nodes.size();
    const size_t n_n = n_nodes.size();
    std::cout << "LAYER BUILDER FUNCTION CALLED\n";

    for (auto &n: h_nodes) {
        n.next_node.resize(n_nodes.size());
    };

    for (size_t i = 0; i < h_n; i++) {
        for (size_t j = 0; j < n_n; j++) {
            n_nodes[j] = Node();
            h_nodes[i].next_node[j] = std::make_shared<Node>(n_nodes[j]);//std::make_shared<Node>(n_nodes[j]);
            n_nodes[j] = *(h_nodes[i].next_node[j]);
        }
    }

    cache.push_back(h_nodes);
    count++;

    std::cout << "[LAYER: " << count << " ] " << "h_nodes-> contains: " << h_n << " pointers\t";
    std::cout << "[LAYER: " << count << " ] " << "n_nodes-> contains: " << n_n << " pointers\t";
    std::cout << "[LAYER CACHE ITEMS: " << cache.size() << ']' << '\n';

    if (depth > 1) {
        Nd new_layer(n_nodes.size());
        hidden_layer(n_nodes, new_layer, cache, depth-1);
    }

    if (depth == 0 || h_nodes.empty() || n_nodes.empty()) {
        std::cout << "Exiting...\n";
        return;
    }
}

void HyperParams::hidden_layer_destructor(Nd &hidden_nodes, Nd &next_nodes, int depth) {
    size_t hidden_size = hidden_nodes.size();
    size_t next_size = next_nodes.size();
    for (size_t i = 0; i < hidden_size; i++) {
        for (size_t j = 0; j < next_size; j++) {
            std::cout << &next_nodes[j];
        }
        std::cout << &hidden_nodes[i];
    }
}


void HyperParams::parameter_initializer(Nd &input, std::shared_ptr<vMatrix> &m1) {
    static int count = 0;
    int weight_count = 0;

    std::tuple dims = returnDimensions(m1); 
    auto rows = std::get<0>(dims);
    auto cols = std::get<1>(dims);
    
    for (auto &node: input) {
        node.Weights = v_matrix_create(rows, cols);
        mem.ptr_freeze(node.Weights);
        v_matrix_randomize(node.Weights, 2);
        std::cout << "Node weight address: " << node.Weights << '\t';
        //v_matrix_print(node.Weights);

        node.Biases = v_matrix_create(rows, 1);
        mem.ptr_freeze(node.Biases);
        v_matrix_randomize(node.Biases, 2);
        //v_matrix_print(node.Biases);
        std::cout << "Node Bias address: " << node.Biases << "\n";

        weight_count++;
    }

    count++;
    std::cout << "Initialized parameters for layer: " << count << '\n';
    std::cout << "No of Weights: " << weight_count << '\n' << '\n';
}

void HyperParams::cache_initializer(LC &cache, std::shared_ptr<vMatrix> &m1) {
    std::cout << "\n\n[CACHE WEIGHTS INTIALIZER CALLED!]" << '\n';
    std::cout<< "[CACHE SIZE: " << cache.size() << "]\n" << '\n';
    if (!m1 || cache.empty()) {
        std::cout << "[ERROR: INVALID PARAMETERS!]" << '\n';
        return;
    }

    int static count = 0;
    const size_t cs = cache.size();

    for (size_t i = 0; i < cs - 1; i++) {
        for (size_t j = 0; j < cache[i].size(); j++) {
            for (size_t k = 0; k < cache[i][j].next_node.size(); k++) {
                if (i + 1 < cs) {
                    cache[i][j].next_node[k] = std::make_shared<Node>(cache[i + 1][j]);
                }
            }
        }
    }


    for (size_t i = 0; i < cs; i++) {
        parameter_initializer(cache[i], m1);

        count++;
        std::cout << "[CACHE WEIGHTS INTIALIZED AT LAYER: " << count << ']' <<"\n\n\n\n";
    }

    std::cout << "[CACHED LAYERS: " << count << ']' << '\n';
    std::cout << "[CACHE WEIGHTS INTIALIZED!]" <<'\n';
}

std::vector<Node> HyperParams::output_layer_constructor(Nd &layers, Nd &output_nodes) {
    std::vector<Node> layer_activations;
    for (int i = 0; i < HIDDEN_LAYERS; i++) {
        std::vector<std::vector<double>> layer_activations;
    }
    return layer_activations;
}

//change the learning rate
void constexpr HyperParams::change_learning_rate(double &new_rate) {
    node.learning_rate =  new_rate;
}

HyperParams::~HyperParams() {
    std::string Deallocator = "[DESTRUCTOR CALLED!]\n[DEALLOCATING MEMORY...]\n";
    //for (int i = 0; i < HIDDEN_NODES; i++) {
    //    delete node.hidden_nodes[i];
    //}
}