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
bool MatrixOps::checkDimensions(std::shared_ptr<vMatrix> m1, std::shared_ptr<vMatrix> m2) {
    return (m1->rows == m2->cols && m1->cols == m2->cols);
}

std::tuple<int, int> MatrixOps::returnDimensions(std::shared_ptr<vMatrix> m1) {
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_add(std::shared_ptr<vMatrix> m1, std::shared_ptr<vMatrix> m2) {
    
    if (!checkDimensions(m1, m2)) {
        throw std::invalid_argument(
            "Dimension Mismatch: "
        );
    }

    std::shared_ptr<vMatrix> m =  v_matrix_create(m1->rows, m1->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = m1->entries[i][j] + m2->entries[i][j];
        }
    }

    return m;
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_subtract(std::shared_ptr<vMatrix> m1, std::shared_ptr<vMatrix> m2) {
    
    if (!checkDimensions(m1, m2)) {
        throw std::invalid_argument(
            "Dimension Mismatch: "
        );
    }

    std::shared_ptr<vMatrix> m =  v_matrix_create(m1->rows, m1->cols);
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_multiply(std::shared_ptr<vMatrix> m1, std::shared_ptr<vMatrix> m2) {
    std::cout << "[CALCULATING MATRIX MULTIPLICATION...]\n";
    
    if (m1->cols != m2->rows) {
        throw std::invalid_argument(
            "Dimension Mismatch: "
        );
    }

    std::shared_ptr<vMatrix> m =  v_matrix_create(m1->rows, m2->cols);
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_dot(std::shared_ptr<vMatrix> m1, std::shared_ptr<vMatrix> m2) {
    
    if (m1->cols != m2->rows) {
        throw std::invalid_argument(
            "Dimension Mismatch: "
        );
    }

    std::shared_ptr<vMatrix> m =  v_matrix_create(m1->rows, m2->cols);
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_scale(double n, std::shared_ptr<vMatrix> m) {
    std::shared_ptr<vMatrix> mat = v_matrix_copy(m);
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_add_scalar(double n, std::shared_ptr<vMatrix> m) {
    std::shared_ptr<vMatrix> mat = v_matrix_copy(m);
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_apply(double (*func)(double), std::shared_ptr<vMatrix> m) {
    std::shared_ptr<vMatrix> mat = v_matrix_copy(m);
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

std::shared_ptr<vMatrix> MatrixOps::v_matrix_transpose(std::shared_ptr<vMatrix> m) {
    std::shared_ptr<vMatrix> mat = v_matrix_copy(m);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            mat->entries[i][j] = m->entries[i][j];
        }
    }

    return mat;
}