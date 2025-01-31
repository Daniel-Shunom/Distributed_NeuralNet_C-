/*
Author: Daniel S. Jeremiah
Date: January 1, 2025 

Description:
This file contains the entrypoint for the program. 
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

    std::shared_ptr<vMatrix> m1 = mp.v_matrix_create(10, 10);
    std::shared_ptr<vMatrix> m2 = mp.v_matrix_create(10, 10);

    std::shared_ptr<vMatrix> m3 = mp.v_matrix_create(4, 2);
    std::shared_ptr<vMatrix> m4 = mp.v_matrix_create(2, 4);

    Nd input_nodes(2);
    Nd next_nodes(3);

    int depth = 437;
    LC layer_cache;
    mc.hidden_layer(input_nodes, next_nodes, layer_cache, depth);

    //ifstream pathing is relative from the location of the executable
    std::vector<std::shared_ptr<Img>> x = img.csv_to_imgs("../../F_MNIST/fashion-mnist_test.csv", 30);

    //img.img_print(x[12]);

    mc.cache_initializer(layer_cache, x[0]->img_data);

    std::tuple<int, int> pos = mp.returnDimensions(input_nodes[0].Weights);
    std::cout << "Row: " <<std::get<0>(pos) <<std::endl;
    std::cout << "Col: " <<std::get<1>(pos) <<std::endl;

    mp.v_matrix_print(input_nodes[0].Weights);
    mp.v_matrix_multiply(input_nodes[0].Weights, next_nodes[0].Weights);

    return 0;
}