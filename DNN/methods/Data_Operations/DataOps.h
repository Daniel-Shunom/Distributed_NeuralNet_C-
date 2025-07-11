/*
Author: Daniel S. Jeremiah
Date: January 6, 2024

Description:
This file contains the Matrix operation functions for the neural 
network. Note that not all possible functions have been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/

#pragma once

#define MAX_CHAR 100

#include "../../types/types.h"
#include "../../cache/img_cache/img_cache.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>

class DataOps { 
public:
  struct Input {
    std::vector<float> weights;
    std::vector<float> biases;
    std::vector<float> input;
    float input_y;
    float label_yhat;
  };

  ImgCache& mem = ImgCache::getInstance();
  /// @brief Loads a vector matrix from a file
  /// @param file_string Path to the file
  /// @return Shared pointer to the loaded vector matrix
  matrix_obj v_matrix_load(std::string file_string);

  /// @brief Creates a new vector matrix with specified dimensions
  /// @param row Number of rows
  /// @param col Number of columns
  /// @return Shared pointer to the created vector matrix
  matrix_obj v_matrix_create(int row, int col);

  /// @brief Flattens a vector matrix along specified axis
  /// @param m Vector matrix to flatten
  /// @param axis Axis along which to flatten (0 for rows, 1 for columns)
  /// @return Shared pointer to the flattened vector matrix
  matrix_obj v_matrix_flatten(matrix_obj &m, int axis);

  /// @brief Creates a deep copy of a vector matrix
  /// @param m Vector matrix to copy
  /// @return Shared pointer to the copied vector matrix
  matrix_obj v_matrix_copy(matrix_obj &m);

  /// @brief Frees memory allocated for a vector matrix
  /// @param m Vector matrix to be freed
  void v_matrix_free(matrix_obj &m);

  /// @brief Saves a vector matrix to a file
  /// @param m Vector matrix to save
  /// @param file_String Path to save file
  void v_matrix_save(matrix_obj m, std::string file_String);

  /// @brief Fills vector matrix with random values
  /// @param m Vector matrix to randomize
  /// @param n Range for random values
  void v_matrix_randomize(matrix_obj &m, int n);

  /// @brief Fills vector matrix with a constant value
  /// @param m Vector matrix to fill
  /// @param n Value to fill with
  void v_matrix_fill(matrix_obj &m, int n);

  /// @brief Prints vector matrix contents to console
  /// @param m Vector matrix to print
  void v_matrix_print(matrix_obj &m);

  Matrix* matrix_load(std::string file_string);
  Matrix* matrix_flatten(Matrix *m, int axis);
  Matrix* matrix_create(int row, int col);
  Matrix* matrix_copy(Matrix* m);

  /// @brief Generates a random number from uniform distribution
  /// @param low Lower bound
  /// @param high Upper bound
  /// @return Random number between low and high
  double uniform_distribution(double low, double high);

  void matrix_save(Matrix *m, std::string file_String);
  void matrix_randomize(Matrix *m, int n);
  void matrix_fill(Matrix *m, int n);
  void matrix_print(Matrix *m);

  /// @brief Frees memory allocated for a matrix
  /// @param m Matrix to free
  void matrix_free(Matrix *m);

  /// @brief Finds index of maximum value in matrix
  /// @param m Matrix to search
  /// @return Index of maximum value
  int matrix_argmax(Matrix *m);

  /// @brief Finds index of maximum value in vector matrix
  /// @param m Vector matrix to search
  /// @return Index of maximum value
  int matrix_argmax(matrix_obj m);

  //void weight_update();
  //void weight_cache();
  //void bias_update();
  //void bias_cache();

  //void input_norm();
  //void input_sort();
  //void input_format();
  //void input_classify();

  //DataOps(/* args */);
  //~DataOps();
};
