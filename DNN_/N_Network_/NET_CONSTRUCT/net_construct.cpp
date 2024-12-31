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

std::tuple<std::function<void(std::vector<HyperParams::Node*>)>> 
                              MenuConstruct::configure_deepnet() {
    int layers;
    int nodes;
    std::cout << "Enter number of hidden layers: ";
    std::cin >> layers;
    std::cout << "Enter number of hidden nodes: ";
    std::cin >> nodes;

    std::tuple<std::function<void(std::vector<HyperParams::Node*>)>> net_config;
    std::function<void(std::vector<HyperParams::Node*>)> layer_config;
    std::function<void(std::vector<HyperParams::Node*>)> node_config;

    layer_config = [this, layers](std::vector<HyperParams::Node*> hidden_layers){
        this->hidden_layer(hidden_layers, hidden_layers);
    };

    node_config = [this, nodes](std::vector<HyperParams::Node*> hidden_nodes){
        //correct with actual hidden node constructor
        this->hidden_layer(hidden_nodes, hidden_nodes);
    };

    net_config = layer_config, node_config;

    return net_config;
}