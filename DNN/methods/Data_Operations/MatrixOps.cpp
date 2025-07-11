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

#include "MatrixOps.h"

//Checks dimensions of array matrices
bool MatrixOps::checkDimensions(Matrix* m1, Matrix* m2) {
  return (m1->rows == m2->rows && m1->cols == m2->cols);
}

//Checks dimensions of vector matrices
bool MatrixOps::checkDimensions(matrix_obj m1, matrix_obj m2) {
  return (m1->rows == m2->cols && m1->cols == m2->cols);
}

std::tuple<int, int> MatrixOps::returnDimensions(matrix_obj m1) {
  int rows = m1->rows;
  int cols = m1->rows;
  std::cout <<"[DIMENSIONs: " << rows << " rows, " << cols << " columns]" << '\n';

  return std::make_tuple(rows, cols);
}

Matrix* MatrixOps::matrix_add(Matrix* m1, Matrix* m2) {

  if (!checkDimensions(m1, m2)) {
    throw std::invalid_argument(
      "Dimension Mismatch: "
    );
  }

  Matrix* m =  matrix_create(m1->rows, m1->cols);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      m->entries[i][j] = m1->entries[i][j] + m2->entries[i][j];
    }
  }

  return m;
}

matrix_obj MatrixOps::v_matrix_add(matrix_obj m1, matrix_obj m2) {
  std::cout << "Add function called\n";

  // Check if dimensions are compatible for broadcasting
  if (m1->rows == m2->rows && m1->cols == m2->cols) {
    // Case 1: Both matrices have the same dimensions (standard addition)
    auto m = v_matrix_create(m1->rows, m1->cols);
    for (int i = 0; i < m->rows; ++i) {
      for (int j = 0; j < m->cols; ++j) {
        m->entries[i][j] = m1->entries[i][j] + m2->entries[i][j];
      }
    }
    return m;
  } else if (m2->rows == 1 && m1->cols == m2->cols) {
    // Case 2: Broadcasting a 1xN matrix (row vector) to an MxN matrix
    auto m = v_matrix_create(m1->rows, m1->cols);
    for (int i = 0; i < m->rows; ++i) {
      for (int j = 0; j < m->cols; ++j) {
        // Add the corresponding column element from the row vector
        m->entries[i][j] = m1->entries[i][j] + m2->entries[0][j];
      }
    }
    std::cout<< "done adding [case 1]\n";
    return m;
  } else if (m2->cols == 1 && m1->rows == m2->rows) {
    // Case 3: Broadcasting an Mx1 matrix (column vector) to an MxN matrix
    auto m = v_matrix_create(m1->rows, m1->cols);
    for (int i = 0; i < m->rows; ++i) {
      for (int j = 0; j < m->cols; ++j) {
        // Add the corresponding row element from the column vector
        m->entries[i][j] = m1->entries[i][j] + m2->entries[i][0];
      }
    }
    std::cout<< "done adding [case 2]\n";
    return m;
  } else {
    throw std::invalid_argument(
      "Dimension Mismatch: Matrices cannot be added due to incompatible shapes."
    );
  }
  std::cout<< "done adding \n";
}


Matrix* MatrixOps::matrix_subtract(Matrix* m1, Matrix* m2) {

  if (!checkDimensions(m1, m2)) {
    throw std::invalid_argument(
      "Dimension Mismatch: "
    );
  }

  Matrix* m =  matrix_create(m1->rows, m1->cols);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      m->entries[i][j] = m1->entries[i][j] - m2->entries[i][j];
    }
  }

  return m;
}

matrix_obj MatrixOps::v_matrix_subtract(matrix_obj m1, matrix_obj m2) {

  if (!checkDimensions(m1, m2)) {
    throw std::invalid_argument(
      "Dimension Mismatch: "
    );
  }

  matrix_obj m =  v_matrix_create(m1->rows, m1->cols);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      m->entries[i][j] = m1->entries[i][j] - m2->entries[i][j];
    }
  }

  return m;
}

Matrix* MatrixOps::matrix_multiply(Matrix* m1, Matrix* m2) {

  if (!checkDimensions(m1, m2)) {
    throw std::invalid_argument(
      "Dimension Mismatch: "
    );
  }

  Matrix* m =  matrix_create(m1->rows, m1->cols);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m2->cols; j++) {
      m->entries[i][j] = m1->entries[i][j] * m2->entries[i][j];
    }
  }

  return m;
}

matrix_obj MatrixOps::v_matrix_multiply(matrix_obj m1, matrix_obj m2) {
  std::cout << "[CALCULATING MATRIX MULTIPLICATION...]\n";

  if (m1->cols != m2->rows) {
    throw std::invalid_argument(
      "Dimension Mismatch: "
    );
  }

  matrix_obj m =  v_matrix_create(m1->rows, m2->cols);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m2->cols; j++) {
      double sum = 0;
      for (int k = 0; k < m2->rows; k++) {
        sum += m1->entries[i][k] * m2->entries[k][j];
      }
      m->entries[i][j] =sum;
    }
  }

  std::cout << "[MATRIX CALCULATION DONE!]\n";
  return m;
}

Matrix* MatrixOps::matrix_dot(Matrix* m1, Matrix* m2) {

  if (m1->rows != m2->cols) {
    throw std::invalid_argument(
      "Dimension Mismatch: "
    );
  }

  Matrix* m =  matrix_create(m1->rows, m1->cols);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m2->cols; j++) {
      double sum = 0;
      for (int k = 0; k < m1->rows; k++) {
        sum += m1->entries[i][k] * m2->entries[k][j];
      }
      m->entries[i][j] =sum;
    }
  }

  return m;
}

matrix_obj MatrixOps::v_matrix_dot(matrix_obj m1, matrix_obj m2) {

  if (m1->cols != m2->rows) {
    throw std::invalid_argument(
      "Dimension Mismatch: "
    );
  }

  matrix_obj m =  v_matrix_create(m1->rows, m2->cols);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m2->cols; j++) {
      double sum = 0;
      for (int k = 0; k < m2->rows; k++) {
        sum += m1->entries[i][k] * m2->entries[k][j];
      }
      m->entries[i][j] =sum;
    }
  }

  v_matrix_print(m);
  return m;
}

Matrix* MatrixOps::matrix_scale(double n, Matrix* m) {
  Matrix* mat = matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] *= n;
    }
  }

  return mat;
}

matrix_obj MatrixOps::v_matrix_scale(double n, matrix_obj m) {
  matrix_obj mat = v_matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] *= n;
    }
  }

  return mat;
}

Matrix* MatrixOps::matrix_add_scalar(double n, Matrix* m) {
  Matrix* mat = matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] += n;
    }
  }

  return mat;
}

matrix_obj MatrixOps::v_matrix_add_scalar(double n, matrix_obj m) {
  matrix_obj mat = v_matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] += n;
    }
  }

  return mat;
}

Matrix* MatrixOps::matrix_apply(double (*func)(double), Matrix* m) {
  Matrix *mat = matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] = (*func)(m->entries[i][j]);
    }
  }

  return mat;
}

matrix_obj MatrixOps::v_matrix_apply(double (*func)(double), matrix_obj m) {
  matrix_obj mat = v_matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] = (*func)(m->entries[i][j]);
    }
  }

  return mat;
}

Matrix* MatrixOps::matrix_transpose(Matrix* m) {
  Matrix* mat = matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] = m->entries[i][j];
    }
  }

  return mat;
}

matrix_obj MatrixOps::v_matrix_transpose(matrix_obj m) {
  matrix_obj mat = v_matrix_copy(m);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] = m->entries[i][j];
    }
  }

  return mat;
}
