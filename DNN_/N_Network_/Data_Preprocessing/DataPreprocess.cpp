#include "DataPreprocess.h"

Data_Processor::Matrix* Data_Processor::matrix_create(int row, int cols) {
    Matrix *matrix = new Matrix;
    matrix->rows = row;
    matrix->cols = cols;
    matrix->entries = new double*[row];
    for (int i = 0; i < row; i++) {
        matrix->entries[i] = new double[cols];
    }
    return matrix;
}

void Data_Processor::matrix_fill(Matrix* m, int n) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->entries[i][j] = n;
        }
    }
}

void Data_Processor::matrix_free(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        delete m->entries[i];
    }
    delete m->entries;
    delete m;
    m = NULL;
}

void Data_Processor::matrix_print(Matrix* m) {
    std::cout << "[ROWS] " << m->rows << "[COLUMNS] " << m->cols << std::endl;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            std::cout << std::fixed << std::setprecision(3) << m->entries[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Data_Processor::Matrix* Data_Processor::matrix_copy(Matrix* m) {
    Matrix* mat = matrix_create(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            mat->entries[i][j] = m->entries[i][j];
        }
    }
    return mat;
}

void Data_Processor::matrix_save(Matrix* m, char* file_string) {
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