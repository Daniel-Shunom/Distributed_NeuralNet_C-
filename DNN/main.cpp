/*
Author: Daniel S. Jeremiah
Date: January 1, 2025 

Description:
This file contains the propagation functions for the neural network. 
Note that not all possible functions have been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/

#include "./NET_CONSTRUCT/net_construct.h"
#include "./Data_Operations/MatrixOps.h"
#include <iostream>

int main() {
    //MenuConstruct m;
    //m.menu_configuration();
    MatrixOps mp;
    vMatrix* m1 = mp.v_matrix_create(10, 10);
    vMatrix* m2 = mp.v_matrix_create(10, 10);

    vMatrix* m3 = mp.v_matrix_create(4, 2);
    vMatrix* m4 = mp.v_matrix_create(2, 4);

    //m1->entries[0][0] = 1;
    //mp.v_matrix_fill(m1, rand()/RAND_MAX);
    //mp.v_matrix_print(m1);
    //std::cout << "\n\n";
//
    //m2->entries[0][0] = 1;
    //mp.v_matrix_fill(m2, rand()/RAND_MAX);
    //mp.v_matrix_print(m2);
    //std::cout << "\n\n";

    m3->entries[0][0] = 1;
    mp.v_matrix_fill(m3, rand()/RAND_MAX);
    mp.v_matrix_print(m3);
    std::cout << "\n\n";

    m4->entries[0][0] = 1;
    mp.v_matrix_fill(m4, rand()/RAND_MAX);
    mp.v_matrix_print(m4);
    std::cout << "\n\n";

    mp.v_matrix_randomize(m3, 3);
    mp.v_matrix_print(m3);
    std::cout << "\n\n";

    mp.v_matrix_randomize(m4, 3);
    mp.v_matrix_print(m4);
    std::cout << "\n\n";


    vMatrix* m5 = mp.v_matrix_create(m1->rows, m2->cols);
    m5 = mp.v_matrix_dot(m3, m4);
    mp.v_matrix_print(m5);
    return 0;
}