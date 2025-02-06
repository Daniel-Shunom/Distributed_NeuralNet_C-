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
#include "./HyperParams/MemManager.h"
#include <iostream>

int main() {
    using tub = std::variant<std::shared_ptr<Image>, 
                std::shared_ptr<MatrixOps>, 
                std::shared_ptr<MenuConstruct>, 
                std::shared_ptr<MemManager>>;
    std::vector<tub> tubby;
 
    MemManager& manager = MemManager::getInstance();
    std::shared_ptr<MenuConstruct> mc = std::make_shared<MenuConstruct>();
    std::shared_ptr<MatrixOps> mp = std::make_shared<MatrixOps>();
    std::shared_ptr<Image> img = std::make_shared<Image>();

    std::shared_ptr<MenuConstruct> mcc = mc;
    std::shared_ptr<MatrixOps> mpp = mp;
    std::shared_ptr<Image> imgg = img;

    tubby.push_back(imgg);
    tubby.push_back(mpp);
    tubby.push_back(mcc);

    Nd input_nodes(2);
    Nd next_nodes(3);

    int depth = 2;
    LC layer_cache;

    //ifstream pathing is relative from the location of the executable
    std::vector<std::shared_ptr<Img>> x = img->csv_to_imgs("../../F_MNIST/fashion-mnist_test.csv", 30);
    img->img_print(x[12]);

    mc->hidden_layer(input_nodes, next_nodes, layer_cache, depth);
    mc->cache_initializer(layer_cache, x[0]->img_data);
    
    if (!input_nodes[0].Weights) {
        std::cout << "WEIGHT OBJECT DOES NOT EXIST\n";
    } else {
        std::cout << "ALL GOOD\n";
    }
    
    manager.mem_size();
    std::tuple<int, int> pos = mp->returnDimensions(input_nodes[0].Weights);
    std::cout << "Row: " <<std::get<0>(pos) << '\n';
    std::cout << "Col: " <<std::get<1>(pos) << '\n';

    mp->v_matrix_print(input_nodes[0].Weights);
    mp->v_matrix_multiply(input_nodes[0].Weights, next_nodes[0].Weights);

    manager.ptr_release();
    tubby.clear();
    return 0;
}