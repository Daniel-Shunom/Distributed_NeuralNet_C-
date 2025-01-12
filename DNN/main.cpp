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
#include "./Image_Operations/ImgOps.h"
#include <iostream>
//#include "../F_MNIST/fashion-mnist_test.csv"

int main() {
    //MenuConstruct m;
    //m.menu_configuration();
    MatrixOps mp;
    Image img;
    vMatrix* m1 = mp.v_matrix_create(10, 10);
    vMatrix* m2 = mp.v_matrix_create(10, 10);

    vMatrix* m3 = mp.v_matrix_create(4, 2);
    vMatrix* m4 = mp.v_matrix_create(2, 4);

    int val = 2;
    Img** image = img.csv_to_imgs(
        "C:/Users/danie/OneDrive/Desktop/C++/F_MNIST/fashion-mnist_test.csv", 
        val
    );
    
    for (int i = 0; i < val; i++) {
        img.img_print(image[i]);
    }
    //mp.v_matrix_print(image[0]->img_data);
    return 0;
}