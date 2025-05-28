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
#include "../../types/types.h"
#include <sstream>
#include <memory>

class Image {
public:
    DataOps dp;

    /// @brief Extracts image data from a CSV file
    /// @param file_string csv file path
    /// @param num_imgs number of images to extract
    /// @return Image data as pixel values between 0 and 1
    std::vector<std::shared_ptr<Img>> csv_to_imgs(std::string file_string, int num_imgs);

    /// @brief Prints image data
    /// @param img input image
    void img_print(std::shared_ptr<Img> img);

    /// @brief deletes image data from memory
    /// @param img input image
    void img_free(std::shared_ptr<Img>img);

    /// @brief deletes image data from memory
    /// @param imgs input images
    /// @param n number of images
    void imgs_free(std::vector<std::shared_ptr<Img>>imgs, int n);
};