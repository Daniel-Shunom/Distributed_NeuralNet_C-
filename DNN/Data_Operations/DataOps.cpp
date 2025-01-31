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

//Creates an array matrix with (int row) rows and (int cols) columns
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

//Creates a vector matrix with (int row) rows and (int cols) columns
vMatrix* DataOps::v_matrix_create(int row, int cols) {
    vMatrix *matrix = new vMatrix;
    matrix->rows = row;
    matrix->cols = cols;
    matrix->entries.resize(row, std::vector<double>(cols));
      
    return matrix;
}

//Fills an array matrix with values of (int n)
void DataOps::matrix_fill(Matrix* m, int n) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = n;
        }
    }
}

//Fillsl a vector matrix with values of (int n)
void DataOps::v_matrix_fill(vMatrix* m, int n) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = n;
        }
    }
}

//Frees an array matrix from heap*
void DataOps::matrix_free(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        delete m->entries[i];
    }
    delete m->entries;
    delete m;
    m = NULL;
}

//Frees a vector matrix from heap
void DataOps::v_matrix_free(vMatrix *m) {
    for (int i = 0; i < m->rows; i++) {
        delete &m->entries[i];
    }
    delete &m->entries;
    delete m;
    m = NULL;
}

//Prints an array matrix
void DataOps::matrix_print(Matrix* m) {
    std::cout << "[ROWS] " << m->rows << "[COLUMNS] " << m->cols << std::endl;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            std::cout << std::fixed << std::setprecision(3) << m->entries[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//Prints a vector matrix
void DataOps::v_matrix_print(vMatrix* m) {
    std::cout << "[ROWS] " << m->rows << "  ||  [COLUMNS] " << m->cols << std::endl;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            std::cout << std::fixed << std::setprecision(3) << m->entries[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

//Copies an array matrix
Matrix* DataOps::matrix_copy(Matrix* m) {
    Matrix* mat = matrix_create(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            mat->entries[i][j] = m->entries[i][j];
        }
    }

    return mat;
}

//Copies a vector matrix
vMatrix* DataOps::v_matrix_copy(vMatrix* m) {
    vMatrix* mat = v_matrix_create(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            mat->entries[i][j] = m->entries[i][j];
        }
    }

    return mat;
}

//Saves an array matrix
void DataOps::matrix_save(Matrix* m, char* file_string) {
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

//Saves a vector matrix
void DataOps::v_matrix_save(vMatrix* m, char* file_string) {
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

//Loads and array matrix
Matrix* DataOps::matrix_load(char *file_string) {
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

//Loads a vector matrix
vMatrix* DataOps::v_matrix_load(char *file_string) {
    std::ifstream file(file_string);
    if (!file) {
        std::cerr << "Error opening file: " << file_string << std::endl;
        return nullptr;
    }

    int rows, cols;
    file >> rows >> cols;

    vMatrix* m = v_matrix_create(rows, cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            file >> m->entries[i][j];
        }
    }

    std::cout << "LOADED MATRIX FROM" << file_string << std::endl;
    return m;
}

//Finds a uniform distribution 
double DataOps::uniform_distribution(double low, double high) {
    double difference = high - low;
    int scale = 10000;
    int scaled_difference = difference * scale;
    
    return low + (1.0 * (rand() % scaled_difference)/scale);
}

//Randomizes vector matrix with values seeded by (int n)
void DataOps::matrix_randomize(Matrix* m, int n) {
    double min = -1.0/sqrt(n);
    double max = 1.0/sqrt(n);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = uniform_distribution(min, max);
        }
    }
}

//Randomizes vector matrix with values seeded by (int n)
void DataOps::v_matrix_randomize(vMatrix* m, int n) {
    double min = -1.0/sqrt(n);
    double max = 1.0/sqrt(n);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = uniform_distribution(min, max);
        }
    }
}

//Performs argmax on array matrix
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

//Performs argmax on vector matrix
int DataOps::matrix_argmax (vMatrix* m) {
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


//flattens array matrix into one dimension
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


//Flattens vector matrix into one dimension 
vMatrix* DataOps::v_matrix_flatten(vMatrix* m, int axis) { 
    // Axis = 0 -> Column Vector, Axis = 1 -> Row Vector 
    vMatrix* mat; if (axis == 0) { 
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