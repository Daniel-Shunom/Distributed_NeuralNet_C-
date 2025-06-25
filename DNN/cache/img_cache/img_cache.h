#pragma once

#include "../../types/types.h"
#include <vector>
#include <iostream>
#include <initializer_list>

class ImgCache {
private:
  ImgCache() = default;
  static ImgCache my_instance;
  static std::vector<matrix_obj> MemCache;
public:
  static ImgCache& getInstance();
  void ptr_freeze(matrix_obj &object1);
  void ptr_release();
  void mem_size();
};

