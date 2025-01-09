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

bool MatrixOps::checkDimensions(Matrix* m1, Matrix* m2) {
    return (m1->rows == m2->rows && m1->cols == m2->cols);
}

bool MatrixOps::checkDimensions(vMatrix* m1, vMatrix* m2) {
    return (m1->rows == m2->cols && m1->cols == m2->cols);
}

Matrix* MatrixOps::matrix_add(Matrix* m1, Matrix* m2) {
    
    if (!checkDimensions(m1, m2)) {
        throw std::invalid_argument(
            "Dimesion mismatch: "
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

vMatrix* MatrixOps::v_matrix_add(vMatrix* m1, vMatrix* m2) {
    
    if (!checkDimensions(m1, m2)) {
        throw std::invalid_argument(
            "Dimesion mismatch: "
        );
    }

    vMatrix* m =  v_matrix_create(m1->rows, m1->cols);
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
            "Dimesion mismatch: "
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

vMatrix* MatrixOps::v_matrix_subtract(vMatrix* m1, vMatrix* m2) {
    
    if (!checkDimensions(m1, m2)) {
        throw std::invalid_argument(
            "Dimesion mismatch: "
        );
    }

    vMatrix* m =  v_matrix_create(m1->rows, m1->cols);
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
            "Dimesion mismatch: "
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

vMatrix* MatrixOps::v_matrix_multiply(vMatrix* m1, vMatrix* m2) {
    
    if (!checkDimensions(m1, m2)) {
        throw std::invalid_argument(
            "Dimesion mismatch: "
        );
    }

    vMatrix* m =  v_matrix_create(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            m->entries[i][j] = m1->entries[i][j] * m2->entries[i][j];
        }
    }

    return m;
}

Matrix* MatrixOps::matrix_dot(Matrix* m1, Matrix* m2) {
    
    if (m1->rows != m2->cols) {
        throw std::invalid_argument(
            "Dimesion mismatch: "
        );
    }

    Matrix* m =  matrix_create(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            double sum = 0;
            for (int k = 0; k < m2->rows; m++) {
                sum += m1->entries[i][k] * m2->entries[k][j];
            }
            m->entries[i][j] =sum;
        }
    }

    return m;
}

vMatrix* MatrixOps::v_matrix_dot(vMatrix* m1, vMatrix* m2) {
    
    if (m1->rows != m2->cols) {
        throw std::invalid_argument(
            "Dimesion mismatch: "
        );
    }

    vMatrix* m =  v_matrix_create(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            double sum = 0;
            for (int k = 0; k < m2->rows; m++) {
                sum += m1->entries[i][k] * m2->entries[k][j];
            }
            m->entries[i][j] =sum;
        }
    }

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

vMatrix* MatrixOps::v_matrix_scale(double n, vMatrix* m) {
    vMatrix* mat = v_matrix_copy(m);
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

vMatrix* MatrixOps::v_matrix_add_scalar(double n, vMatrix* m) {
    vMatrix* mat = v_matrix_copy(m);
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

vMatrix* MatrixOps::v_matrix_apply(double (*func)(double), vMatrix* m) {
    vMatrix *mat = v_matrix_copy(m);
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

vMatrix* MatrixOps::v_matrix_transpose(vMatrix* m) {
    vMatrix* mat = v_matrix_copy(m);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            mat->entries[i][j] = m->entries[i][j];
        }
    }

    return mat;
}