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
#include <sstream>

typedef struct {
    vMatrix* img_data;
    int label;
} Img;

class Image {
public:
    DataOps dp;

    Img** csv_to_imgs(char* file_string, int num_imgs);
    void img_print(Img* img);
    void img_free(Img *img);
    void imgs_free(Img **imgs, int n);
};