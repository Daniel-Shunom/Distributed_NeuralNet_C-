/*
Author: Daniel S. Jeremiah
Date: December 31, 2024

Description:
This file contains the propagation functions for the neural network. 
Note that not all possible functions have been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/

#include "./net_construct.h"
#include <iostream>

std::function<void(std::vector<float>)> MenuConstruct::select_activation() {
    int selection;
    std::cout << "Select Activation function\n\n";
    std::cout << "[1. tanh        Activation ]\n";
    std::cout << "[2. ReLU        Activation ]\n";
    std::cout << "[3. Leaky ReLU  Activation ]\n";
    std::cout << "[4. Sigmoid     Activation ]\n";
    std::cout << "Enter Selection: ";
    std::cin >> selection;
    
    std::function<void(std::vector<float>)> selectedFunction;
    switch (selection) {
        case 1:
            selectedFunction = [this](std::vector<float> input) {
                this->tanh_activations(input);};
            break;
        case 2:
            selectedFunction = [this](std::vector<float> input) {
                this->relu_activations(input);};
            break;
        case 3:
            selectedFunction = [this](std::vector<float> input) {
                this->leaky_relu_activations(input);};
            break;
        case 4:
            selectedFunction = [this](std::vector<float> input) {
                this->sigmoid_activations(input);};
            break;
        default:
            throw std::invalid_argument("INVALID SELECTION\n");
    }

    return selectedFunction;
}

MenuConstruct::deepNetTuple MenuConstruct::configure_deepnet() {
    int layers;
    int nodes;
    std::cout << "\n\n[LAYER PARAMETER SELECTION!]\n";
    std::cout << "Enter number of hidden layers: ";
    std::cin >> layers;
    std::cout << "Enter number of hidden nodes: ";
    std::cin >> nodes;

    deepNetTuple net_config;
    std::function<void(std::vector<HyperParams::Node*>)> layer_config;
    std::function<void(std::vector<HyperParams::Node*>)> node_config;

    layer_config = [this, layers](std::vector<HyperParams::Node*> hidden_layers){
        this->hidden_layer(hidden_layers, hidden_layers);
    };

    node_config = [this, nodes](std::vector<HyperParams::Node*> hidden_nodes) {
        //correct with actual hidden node constructor
        this->hidden_layer(hidden_nodes, hidden_nodes);
    };

    net_config = layer_config, node_config;

    return net_config;
}

MenuConstruct::ioTuple MenuConstruct::io_nodes_config() {
    int i_nodes;
    int o_nodes;
    std::cout << "Enter number of input nodes: ";
    std::cin >> i_nodes;
    std::cout << "Enter number of output nodes: ";
    std::cin >> o_nodes;

    ioTuple net_config;

    std::function<void(std::vector<HyperParams::Node*>, 
                       std::vector<HyperParams::Node*>)> layer_config;
    
    std::function<void(std::vector<HyperParams::Node*>, 
                       std::vector<HyperParams::Node*>)> node_config;

    layer_config = [this, i_nodes](std::vector<HyperParams::Node*> &input_layer,
                                   std::vector<HyperParams::Node*> &hidden_layers) 
    mutable {
        input_layer.resize(i_nodes),
        hidden_layers.resize(HIDDEN_NODES);
        this->input_layer_constructor(input_layer, hidden_layers);
    };

    node_config = [this, o_nodes](std::vector<HyperParams::Node*> &hidden_layers,
                                  std::vector<HyperParams::Node*> &output_nodes) 
    mutable {
        hidden_layers.resize(HIDDEN_NODES);
        output_nodes.resize(o_nodes);
        this->output_layer_constructor(hidden_layers, output_nodes);
    };

    net_config = std::make_tuple(layer_config, node_config);

    return net_config;
}

void MenuConstruct::instruction_eval(iSet x) {
    int length = x.size();
    std::cout << "\n[INSTRUCTION SET HAS "<< length <<" METHODS]\n";
}

int MenuConstruct::menu_configuration() {
    auto config1 = io_nodes_config();
    instructions.push_back(config1);

    auto config2 = configure_deepnet();
    instructions.push_back(config2);
    
    auto config3 = select_activation();
    instructions.push_back(config3);

    instruction_eval(instructions);

    return 0;
}