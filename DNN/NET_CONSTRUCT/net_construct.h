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
#include "../Propagations/Propagation.h"
#include "../HyperParams/HyperParams.h"
#include <variant>

class MenuConstruct: public HyperParams {
private:
public:
    typedef std::function<void(vMatrix*)> iAselect;
    typedef std::tuple<std::function<void(Nd, Nd)>> deepNetTuple;
    typedef std::tuple<std::function<void(Nd, Nd)>, 
                       std::function<void(Nd, Nd)>> ioTuple;
    typedef std::vector<std::variant<ioTuple, deepNetTuple, iAselect>> iSet;

    iSet instructions;
    int depth;
    LC layer_cache;

    iAselect select_activation();
    ioTuple io_nodes_config();
    deepNetTuple configure_deepnet();

    void instruction_eval(iSet A);
                               
    
    int menu_configuration();
};