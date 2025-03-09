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

#include "../../Essential_Methods/Propagations/Propagation.h"
#include "../Cache_Managers/CacheMangr.h"
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

    std::shared_ptr<NodeMangr> manager = NodeMangr::getNodeMangr();

    Node node;
    H_Params h_params;

    HyperParams();
    ~HyperParams();
    
    std::array<double, HIDDEN_NODES> allocate_memory(rP_Nd input_nodes, rP_Nd next_nodes);

    std::vector<double> hidden_unit(std::vector<double> activations);

    /// @brief Frees up memory consumed by hidden layer
    /// @param input_nodes Input vector of nodes
    /// @param next_nodes vector with Size of next layer
    /// @param depth depth of the hidden layer
    void hidden_layer_destructor(Nd &input_nodes, Nd &next_nodes, int depth);

    /// @brief Overloaded hidden_layer function with templatized arrays
    /// @param input_nodes input array of nodes
    /// @param next_nodes input array of next layer nodes
    /// @param depth depth of the hidden layer
    template<typename ...args>
    void hidden_layer(args... obj);

    /// @brief overloaded hidden_layer_destructor with templatized arrays
    /// @param input_nodes input array of nodes
    /// @param next_nodes input array of next layer nodes
    void hidden_layer_destructor(rP_Nd &input_nodes, rP_Nd &next_nodes);

    /// @brief Intializes weights and biases for each Node
    /// @param input input node
    /// @param m1 Matrix pointer to image reference
    void parameter_initializer(Nd &input, std::shared_ptr<vMatrix> &m1);

    /// @brief Intializes Node parameters for each layer in cache
    /// @param input Layer cache vector
    /// @param m1 Image refrence 
    void cache_initializer(LC &input, std::shared_ptr<vMatrix> &m1);

    /// @brief To change the learning rate
    /// @param learning_rate new learning rate
    void constexpr change_learning_rate(double &learning_rate);

    //array form
    std::vector<Node> input_layer_constructor(std::vector<rI_Nd> &input_nodes, std::vector<rP_Nd> &hidden_nodes);
    std::vector<Node> output_layer_constructor(std::vector<rP_Nd> &layers, std::vector<rO_Nd> &output_nodes);
    
    //vector form
    std::vector<Node> input_layer_constructor(Nd &input_nodes, Nd &hidden_nodes);
    std::vector<Node> output_layer_constructor(Nd &layers, Nd &output_nodes);
                                               
    std::vector<Node> deep_net_constructor(std::vector<rP_Nd> &layers);
};