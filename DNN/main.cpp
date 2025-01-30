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

int main() {
    MenuConstruct mc;
    MatrixOps mp;
    Image img;

    //m.menu_configuration();

    vMatrix* m1 = mp.v_matrix_create(10, 10);
    vMatrix* m2 = mp.v_matrix_create(10, 10);

    vMatrix* m3 = mp.v_matrix_create(4, 2);
    vMatrix* m4 = mp.v_matrix_create(2, 4);

    Nd input_nodes(2);
    Nd next_nodes(3);

    int depth = 7;
    LC layer_cache;
    mc.hidden_layer(input_nodes, next_nodes, layer_cache, depth);
    Img** x = img.csv_to_imgs("C:/Users/danie/Distributed_NeuralNet_C-/F_MNIST/fashion-mnist_test.csv", 30);
    //img.img_print(x[12]);

    mc.cache_initializer(layer_cache, x[0]->img_data);

    return 0;
}