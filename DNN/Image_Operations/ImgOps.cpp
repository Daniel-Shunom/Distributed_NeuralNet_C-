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

#include "ImgOps.h"

Img** Image::csv_to_imgs(char* file_string, int num_imgs) {
    std::ifstream file(file_string);
    if(!file.is_open()) {
        std::cerr << "Error: Could not open file" << std::endl;
        return nullptr;
    }

    Img** imgs = new Img* [num_imgs];
    std::string row;

    std::getline(file, row);
    int i = 0;
    while (std::getline(file, row) && i < num_imgs) {
        imgs[i] = new Img; 
        imgs[i]->img_data = dp.v_matrix_create(28, 28);

        std::istringstream ss(row);
        std::string token;

        int j = 0;
        while (std::getline(ss, token, ',')) {
            if (j == 0) {
                imgs[i]->label = std::stoi(token);
            } else {
                imgs[i]->img_data->entries[(j-1)/28][(j-1)%28] = std::stoi(token)/256.0;
            }
            j++;
        }
        i++;
    }

    file.close();
    return imgs;
}

void Image::img_print(Img* img) {
    dp.v_matrix_print(img->img_data);
    std::cout << "Image Label: " << img->label << std::endl;
}

void Image::img_free(Img* img) {
    dp.v_matrix_free(img->img_data);
    delete img;
}

void Image::imgs_free(Img **imgs, int n) {
    for (int i = 0; i < n; i++) {
        img_free(imgs[i]);
    }

    delete[] imgs;
}
