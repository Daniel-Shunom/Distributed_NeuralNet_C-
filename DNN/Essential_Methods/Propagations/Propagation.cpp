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

#include "./Propagation.h"

std::string Propagation::error_check(
  std::vector<double> &_weights,
  std::vector<double> &_biases,
  std::vector<double> &input
) {
    if(_weights.size() != input.size()) {
        return prop_error.weight_off;
    }
    if (_biases.size() != input.size()) {
        return prop_error.bias_off;
    }
    else {
        std::cout << "[GOOD TO GO!]\n\n";
    }
    return "ok";
}

std::shared_ptr<vMatrix> Propagation::apply_func(
  std::shared_ptr<vMatrix> m,
  double (*func)(double)
) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      m->entries[i][j] = func(m->entries[i][j]);
    }
  }
  return m;
}

std::shared_ptr<vMatrix> Propagation::v_forwardpass(
  std::shared_ptr<vMatrix> m, 
  std::shared_ptr<vMatrix> w, 
  std::shared_ptr<vMatrix> b
) {
  return mp.v_matrix_add(mp.v_matrix_multiply(m, w), b);
}

std::shared_ptr<vMatrix> Propagation::v_sigmoid_activation(std::shared_ptr<vMatrix> Z) {
  return apply_func(Z, [](double x){ return 1/(1+std::exp(x)); });
}

std::shared_ptr<vMatrix> Propagation::v_tanh_activation(std::shared_ptr<vMatrix> Z) {
  return apply_func(Z, tanh);
}

std::shared_ptr<vMatrix> Propagation::v_relu_activation(std::shared_ptr<vMatrix> Z) {
  return apply_func(Z, [](double x){ return std::max(0.0, x); });
}

std::shared_ptr<vMatrix> Propagation::v_leaky_relu_activation(std::shared_ptr<vMatrix> Z) {
  return apply_func(Z, [](double x){ return std::max(0.0001*x, x); });
}

double Propagation::cross_entropy_loss(double &input_y, double &input_yhat) {
  return -(input_y*log(input_yhat) + (1-input_y)*log(1-input_yhat));
}

double Propagation::cost_function(double &cost) {
  return cross_entropy_loss(params.input_y, params.input_yhat)/params.input.size();
}
