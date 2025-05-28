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
#include <memory>


#ifdef _WIN32
  #include <conio.h>
  int read_arrow() {
    int c = _getch();
    if (c == 0 || c == 0xE0) {
      int code = _getch();
      if (code == 72) return +1;
      if (code == 80) return -1;
    }
    return 0;
  }

  int read_key() {
    int c = _getch();
    if (c == '\r') return '\n';
    return c;
  }

#else 
  #include <termios.h>
  #include <unistd.h>
  
  struct TermRaw {
    termios oldt;
    TermRaw() {
      tcgetattr(STDIN_FILENO, &oldt);
      termios raw = oldt;
      raw.c_lflag &= ~(ICANON | ECHO);
      raw.c_cc[VMIN] = 1;
      raw.c_cc[VTIME] = 0;
      tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }
    ~TermRaw() {
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
  };

  int read_arrow() {
    char buf[3];
    if (read(STDIN_FILENO, buf, 1) != 1) return 0;
    if (buf[0] != '\x1b') return 0;
    if (read(STDIN_FILENO, buf+1, 2) != 2) return 0;
    if (buf[1] == '[') {
      if (buf[2] == 'A') return +1;
      if (buf[2] == 'B') return -1;
    }
    return 0;
  }

  int read_key() {
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) return 0;
    return c;
  }
#endif

void clear_screen() { std::cout << "\033[2J\033[H"; }
void invert_on() { std::cout << "\033[7m"; }
void invert_off() { std::cout << "\033[0m"; }

MenuConstruct::actv_func MenuConstruct::select_activation() {
  struct Item { std::string label; std::function<matrix_obj(matrix_obj)> fn; };
  std::vector<Item> items = {
    {"Tanh        activation", [this](matrix_obj p){ return this->v_tanh_activation(p); }},
    {"ReLU        activation", [this](matrix_obj p){ return this->v_relu_activation(p); }},
    {"Leaky ReLU  activation", [this](matrix_obj p){ return this->v_leaky_relu_activation(p); }},
    {"Sigmoid     activation", [this](matrix_obj p){ return this->v_sigmoid_activation(p); }}
  };

  int cursor = 0;

  #ifndef _WIN32
    TermRaw tr;
  #endif

  while (true) {
    clear_screen();
    std::cout << "select activation function\n\n";
    for (int i = 0; i < (int)items.size(); ++i) {
      if (i == cursor) invert_on();
      std::cout << " " << items[i].label << "\n";
      if (i == cursor) invert_off();
    }

    int delta = read_arrow();
    if (delta != 0) {
      int n = items.size();
      cursor = (cursor + n + (delta == +1 ? -1 : +1)) % n;
    } else if (read_key() == '\n') {
      break;
    }
  }
    
  return items[cursor].fn;
}

MenuConstruct::net_config MenuConstruct::configure_deepnet() {
  int layers, nodes, depth;
  std::cout << "\n\n[LAYER PARAMETER SELECTION!]\n";
  std::cout << "Enter number of hidden layers: ";
  std::cin >> layers;
  std::cout << "Enter hidden layer depth: ";
  std::cin >> depth;
  std::cout << "Enter number of hidden nodes: ";
  std::cin >> nodes;

  net_config net_config;
  std::function<void(Nd, Nd)> layer_config, node_config;
  
  layer_config = [this, layers, depth](Nd hidden_layers, Nd next_layer) {
    this->hidden_layer(hidden_layers, next_layer, layer_cache, depth);
  };

  node_config = [this, nodes, depth](Nd hidden_nodes, Nd next_layer) {
    this->hidden_layer(hidden_nodes, next_layer, layer_cache, depth);
  };

  return std::make_pair(layer_config, node_config);
}

MenuConstruct::io_config MenuConstruct::io_nodes_config() {
  int i_nodes;
  int o_nodes;
  std::cout << "Enter number of input nodes: ";
  std::cin >> i_nodes;
  std::cout << "Enter number of output nodes: ";
  std::cin >> o_nodes;
    
  std::cout << "\n[CURRENT WEIGHTS]\n";
  for (int i = 0; i < params.weights.size(); i++) {
    std::cout << params.weights[i] << "  ";
  }
  std::cout << "\n\n";

  io_config net_config;

  std::function<void(Nd, Nd)> layer_config;
  std::function<void(Nd, Nd)> node_config;

  layer_config = [this, i_nodes](Nd &input_layer, Nd &hidden_layers) {
    input_layer.resize(i_nodes),
    hidden_layers.resize(HIDDEN_NODES);
    this->hidden_layer(input_layer, hidden_layers, layer_cache, depth);
  };

  node_config = [this, o_nodes](Nd &hidden_layers, Nd &output_nodes) {
    hidden_layers.resize(HIDDEN_NODES);
    output_nodes.resize(o_nodes);
    this->hidden_layer(hidden_layers, output_nodes, layer_cache, depth);
  };

  return std::make_pair(layer_config, node_config);
}

void MenuConstruct::instruction_eval(instr_set x) {
  std::cout << "\n[INSTRUCTION SET HAS "<< x.size() <<" METHODS]\n";
}

int MenuConstruct::menu_configuration() {
  instructions.push_back(select_activation());
  instructions.push_back(io_nodes_config());
  instructions.push_back(configure_deepnet());
  instruction_eval(instructions);

  return 0;
}
