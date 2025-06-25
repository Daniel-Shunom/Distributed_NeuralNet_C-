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
  using func_store = std::function<void(Nd, Nd)>;

  using actv_func = std::function<void(matrix_obj)>;
  using net_config = std::pair<func_store, func_store>;
  using io_config = std::pair<func_store, func_store>;
  using instr_set = std::vector<std::variant<io_config, actv_func>>;

  instr_set instructions;
  int depth;
  LC layer_cache;

  actv_func select_activation();
  io_config io_nodes_config();
  net_config configure_deepnet();
  void instruction_eval(instr_set A);
public:                    
  /// @brief Starts Deep Neural Network Configuration
  /// @return Exits the configuration program
  int menu_configuration();
};
