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

std::vector<std::shared_ptr<Img>> Image::csv_to_imgs(std::string file_string, int num_imgs) {
  std::ifstream file(file_string, std::ios::in);
  if(!file.is_open()) {
    std::cerr << "Error: Could not open file " << file_string << std::endl;
    std::exit(EXIT_FAILURE);    
    return {};
  }

  std::vector<std::shared_ptr<Img>> imgs(num_imgs);
  std::string row;

  std::getline(file, row);
  int i = 0;
  while (std::getline(file, row) && i < num_imgs) {
    imgs[i] = std::make_shared<Img>(); 
    imgs[i]->img_data = dp.v_matrix_create(28, 28);

    std::istringstream ss(row);
    std::string token;

    int j = 0;
    while (std::getline(ss, token, ',')) {
      j == 0 ? imgs[i]->label = std::stoi(token)
        : imgs[i]->img_data->entries[(j-1)/28][(j-1)%28] = std::stoi(token)/256.0;
      j++;
    }
    i++;
  }

  file.close();
  return imgs;
}

void Image::img_print(std::shared_ptr<Img> img) {
  std::cout << "Image Label: " << img->label << std::endl << std::endl;
  dp.v_matrix_print(img->img_data);
}

void Image::img_free(std::shared_ptr<Img> img) {
  dp.v_matrix_free(img->img_data);
}

void Image::imgs_free(std::vector<std::shared_ptr<Img>> imgs, int n) {
  for (int i = 0; i < n; i++) { img_free(imgs[i]); }
}
