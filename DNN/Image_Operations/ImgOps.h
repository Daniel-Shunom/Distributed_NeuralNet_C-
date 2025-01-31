/*
Author: Daniel S. Jeremiah
Date: January 11, 2024

Description:
This file contains the Image operation functions for the neural 
network. Note that not all possible functions have been defined here. 
Additional functions will be included as the project scales.

Instructions:
- Do not change the function definitions as they are expected to remain constant.
- Ensure to follow the project guidelines for adding new functions.

*/


#pragma once

#include "../Data_Operations/MatrixOps.h"
#include "../Data_Operations/DataOps.h"
#include "../Essential_Params/Params.h"
#include <sstream>
#include <memory>

class Image {
public:
    DataOps dp;

    std::vector<std::shared_ptr<Img>> csv_to_imgs(std::string file_string, int num_imgs);
    void img_print(std::shared_ptr<Img> img);
    void img_free(std::shared_ptr<Img>img);
    void imgs_free(std::vector<std::shared_ptr<Img>>imgs, int n);
};