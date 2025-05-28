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
#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include "../methods/Propagations/Propagation.h"
#include "../cache/HyperParameters/HyperParams.h"
#include <variant>

class MenuConstruct: public HyperParams {
private:
public:
    typedef std::function<void(matrix_obj)> iAselect;
    typedef std::tuple<std::function<void(Nd, Nd)>> deepNetTuple;
    typedef std::tuple<std::function<void(Nd, Nd)>, 
                       std::function<void(Nd, Nd)>> ioTuple;
    typedef std::vector<std::variant<ioTuple, deepNetTuple, iAselect>> iSet;
    
    iSet instructions;
    int depth;
    LC layer_cache;

    /// @brief Select menu for activation functions
    /// @return Selected activation function ad a function pointer
    iAselect select_activation();
    
    /// @brief Configure the deep neural network
    /// @return Configuration as a tuple
    ioTuple io_nodes_config();

    /// @brief Configure the deep neural network
    /// @return Selected activation function ad a function pointer
    deepNetTuple configure_deepnet();

    /// @brief Checks length of instruction set
    /// @param A Variant Container of Instructions
    void instruction_eval(iSet A);
                               
    /// @brief Starts Deep Neural Network Configuration
    /// @return Exits the configuration program
    int menu_configuration();
};
