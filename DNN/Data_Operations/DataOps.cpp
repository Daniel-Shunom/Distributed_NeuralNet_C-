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

#include "DataOps.h"

Matrix* DataOps::matrix_create(int row, int cols) {
    Matrix *matrix = new Matrix;
    matrix->rows = row;
    matrix->cols = cols;
    matrix->entries = new double*[row];
    for (int i = 0; i < row; i++) {
        matrix->entries[i] = new double[cols];
    }
      
    return matrix;
}

std::shared_ptr<vMatrix> DataOps::v_matrix_create(int row, int cols) {
    std::shared_ptr<vMatrix> matrix = std::make_shared<vMatrix>();
    matrix->rows = row;
    matrix->cols = cols;
    matrix->entries.resize(row, std::vector<double>(cols));
      
    return matrix;
}

void DataOps::matrix_fill(Matrix* m, int n) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = n;
        }
    }
}

void DataOps::v_matrix_fill(std::shared_ptr<vMatrix> m, int n) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = n;
        }
    }
}

void DataOps::matrix_free(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        delete m->entries[i];
    }
    delete m->entries;
    delete m;
    m = NULL;
}

void DataOps::v_matrix_free(std::shared_ptr<vMatrix> m) {
    for (int i = 0; i < m->rows; i++) {
        delete &m->entries[i];
    }
    delete &m->entries;
    //delete m;
    m = NULL;
}

void DataOps::matrix_print(Matrix* m) {
    std::cout << "[ROWS] " << m->rows << "[COLUMNS] " << m->cols << std::endl;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            std::cout << std::fixed << std::setprecision(3) << m->entries[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DataOps::v_matrix_print(std::shared_ptr<vMatrix> m) {
    std::cout << "[ROWS] " << m->rows << "  ||  [COLUMNS] " << m->cols << std::endl;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            std::cout << std::fixed << std::setprecision(3) << m->entries[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix* DataOps::matrix_copy(Matrix* m) {
    Matrix* mat = matrix_create(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            mat->entries[i][j] = m->entries[i][j];
        }
    }

    return mat;
}

std::shared_ptr<vMatrix> DataOps::v_matrix_copy(std::shared_ptr<vMatrix> m) {
    std::shared_ptr<vMatrix> mat = v_matrix_create(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            mat->entries[i][j] = m->entries[i][j];
        }
    }

    return mat;
}

void DataOps::matrix_save(Matrix* m, std::string file_string) {
    std::ofstream file(file_string); 
    if (!file) { 
        std::cerr << "Error opening file: " << file_string << std::endl; 
        return; 
    } 

    file << m->rows << std::endl; 
    file << m->cols << std::endl; 

    for (int i = 0; i < m->rows; ++i) { 
        for (int j = 0; j < m->cols; ++j) { 
            file << std::fixed << std::setprecision(6) << m->entries[i][j] << std::endl; 
        } 
    } 

    std::cout << "Successfully saved matrix to " << file_string << std::endl; 
    file.close();
}

void DataOps::v_matrix_save(std::shared_ptr<vMatrix> m, std::string file_string) {
    std::ofstream file(file_string); 
    if (!file) { 
        std::cerr << "Error opening file: " << file_string << std::endl; 
        return; 
    } 

    file << m->rows << std::endl; 
    file << m->cols << std::endl; 

    for (int i = 0; i < m->rows; ++i) { 
        for (int j = 0; j < m->cols; ++j) { 
            file << std::fixed << std::setprecision(6) << m->entries[i][j] << std::endl; 
        } 
    } 

    std::cout << "Successfully saved matrix to " << file_string << std::endl; 
    file.close();
}

Matrix* DataOps::matrix_load(std::string file_string) {
    std::ifstream file(file_string);
    if (!file) {
        std::cerr << "Error opening file: " << file_string << std::endl;
        return nullptr;
    }

    int rows, cols;
    file >> rows >> cols;

    Matrix* m = matrix_create(rows, cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            file >> m->entries[i][j];
        }
    }

    std::cout << "LOADED MATRIX FROM" << file_string << std::endl;
    return m;
}

std::shared_ptr<vMatrix> DataOps::v_matrix_load(std::string file_string) {
    std::ifstream file(file_string);
    if (!file) {
        std::cerr << "Error opening file: " << file_string << std::endl;
        return nullptr;
    }

    int rows, cols;
    file >> rows >> cols;

    std::shared_ptr<vMatrix> m = v_matrix_create(rows, cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            file >> m->entries[i][j];
        }
    }

    std::cout << "LOADED MATRIX FROM" << file_string << std::endl;
    return m;
}

double DataOps::uniform_distribution(double low, double high) {
    double difference = high - low;
    int scale = 10000;
    int scaled_difference = difference * scale;
    
    return low + (1.0 * (rand() % scaled_difference)/scale);
}

void DataOps::matrix_randomize(Matrix* m, int n) {
    double min = -1.0/sqrt(n);
    double max = 1.0/sqrt(n);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = uniform_distribution(min, max);
        }
    }
}

void DataOps::v_matrix_randomize(std::shared_ptr<vMatrix> m, int n) {
    double min = -1.0/sqrt(n);
    double max = 1.0/sqrt(n);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = uniform_distribution(min, max);
        }
    }
}

int DataOps::matrix_argmax (Matrix* m) {
    double max_score = 0;
    int max_idx = 0;
    for (int i = 0; i < m->rows; i++) {
        if (m->entries[i][0] > max_score) {
            max_score = m->entries[i][0];
            max_idx = i;
        }
    }

    return max_idx;
}

int DataOps::matrix_argmax (std::shared_ptr<vMatrix> m) {
    double max_score = 0;
    int max_idx = 0;
    for (int i = 0; i < m->rows; i++) {
        if (m->entries[i][0] > max_score) {
            max_score = m->entries[i][0];
            max_idx = i;
        }
    }

    return max_idx;
}


Matrix* DataOps::matrix_flatten(Matrix* m, int axis) { 
    // Axis = 0 -> Column Vector, Axis = 1 -> Row Vector 
    Matrix* mat; if (axis == 0) { 
        mat = matrix_create(m->rows * m->cols, 1); 
    } 
    else if (axis == 1) { 
        mat = matrix_create(1, m->rows * m->cols); 
    } 
    else { 
        std::cerr << "Argument to matrix_flatten must be 0 or 1" << std::endl; 
        exit(EXIT_FAILURE); 
    } 
    
    for (int i = 0; i < m->rows; ++i) { 
        for (int j = 0; j < m->cols; ++j) { 
            if (axis == 0) { 
                mat->entries[i * m->cols + j][0] = m->entries[i][j];
            } 
            else if (axis == 1) { 
                mat->entries[0][i * m->cols + j] = m->entries[i][j];
            } 
        } 
    }

    return mat;
}


std::shared_ptr<vMatrix> DataOps::v_matrix_flatten(std::shared_ptr<vMatrix> m, int axis) { 
    // Axis = 0 -> Column Vector, Axis = 1 -> Row Vector 
    std::shared_ptr<vMatrix> mat; if (axis == 0) { 
        mat = v_matrix_create(m->rows * m->cols, 1); 
    } 
    else if (axis == 1) { 
        mat = v_matrix_create(1, m->rows * m->cols); 
    } 
    else { 
        std::cerr << "Argument to matrix_flatten must be 0 or 1" << std::endl; 
        exit(EXIT_FAILURE); 
    } 
    
    for (int i = 0; i < m->rows; ++i) { 
        for (int j = 0; j < m->cols; ++j) { 
            if (axis == 0) { 
                mat->entries[i * m->cols + j][0] = m->entries[i][j];
            } 
            else if (axis == 1) { 
                mat->entries[0][i * m->cols + j] = m->entries[i][j];
            } 
        } 
    }

    return mat;
}