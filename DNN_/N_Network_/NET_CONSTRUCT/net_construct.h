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
#ifndef _MENU_CONSTRUCT_
#define _MENU_CONSTRUCT_

#include <iostream>
#include <vector>
#include <functional>
#include "../Propagations/Propagation.h"
#include "../HyperParams/HyperParams.h"

class MenuConstruct: Propagation, HyperParams {
private:
public:
    Propagation menu_props;
    HyperParams h_params;
    
    std::function<void(std::vector<float>)> select_activation();

    std::tuple<std::function<void(std::vector<HyperParams::Node*>, 
                                  std::vector<HyperParams::Node*>)>,
               std::function<void(std::vector<HyperParams::Node*>, 
                                  std::vector<HyperParams::Node*>)>> io_nodes_config();

    std::tuple<std::function<void(std::vector<HyperParams::Node*>)>> configure_deepnet();
    int menu_configuration();
};


#endif