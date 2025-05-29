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

#include "./menu/menu.h"
#include "./methods/Data_Operations/MatrixOps.h"
#include "./methods/Image_Operations/ImgOps.h"
#include "./cache/Lifetime_Managers/MemManager.h"
#include "./alg/alg.h"
#include <iostream>

int main() {
    using tub = std::variant<
        std::shared_ptr<Image>, 
        std::shared_ptr<MatrixOps>, 
        std::shared_ptr<MenuConstruct>, 
        std::shared_ptr<MemManager>
    >;
    std::vector<tub> tubby;
 
    MemManager& manager = MemManager::getInstance();
    std::shared_ptr<MenuConstruct> mc = std::make_shared<MenuConstruct>();
    /*std::shared_ptr<MatrixOps> mp = std::make_shared<MatrixOps>();
    std::shared_ptr<Image> img = std::make_shared<Image>();

    std::shared_ptr<MenuConstruct> mcc = mc;
    std::shared_ptr<MatrixOps> mpp = mp;
    std::shared_ptr<Image> imgg = img;
    Alg alg;

    tubby.push_back(imgg);
    tubby.push_back(mpp);
    tubby.push_back(mcc);

    //once input nodes are in cache, the input node vector 
    Nd input_nodes(4);
    Nd next_nodes(6);

    int depth = 7;
    LC layer_cache;

    //So this is stupid
    //Apparently the ifstream reads the correct file path to be
    //the path relative to where the execute command is called
    //so in this case you have to be in the project root directory
    //to figure use this specifc relative path
    std::vector<std::shared_ptr<Img>> x = img->csv_to_imgs("./F_MNIST/fashion-mnist_test.csv", 10);
    img->img_print(x[8]);  
    mc->hidden_layer(input_nodes, next_nodes, layer_cache, depth);
    mc->cache_initializer(layer_cache, x[0]->img_data);
    
    std::cout << std::endl;
    for (auto const &n: layer_cache[5][4].next_node) {
        std::cout << "Layer 5 Points to Node: " << n << '\n';
    }
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < layer_cache[6].size(); i++) {
        std::cout << "Layer 6 Nodes: " << &layer_cache[6][i] << '\n';
    }
    std::cout << std::endl;
    std::cout << std::endl;


    manager.mem_size();
    std::tuple<int, int> pos = mp->returnDimensions(layer_cache[6][4].Weights);
    std::cout << "Row: " <<std::get<0>(pos) << '\n';
    std::cout << "Col: " <<std::get<1>(pos) << '\n';

    //mp->v_matrix_multiply(layer_cache[6][4].Weights, layer_cache[5][4].Weights);
    vMatrix temp = *x[0]->img_data;
    alg.set_input_lyr(layer_cache, x[0]->img_data);
    alg.forwardprop(layer_cache);


    manager.ptr_release();
    tubby.clear();/**/
    mc->menu_configuration();
    return 0;
}
