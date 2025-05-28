#pragma once

#include "../../types/types.h"
#include <vector>
#include <iostream>
#include <initializer_list>

class MemManager {
private:
    MemManager() = default;
    static MemManager my_instance;
    static std::vector<matrix_obj> MemCache;
public:
    static MemManager& getInstance();
    void ptr_freeze(matrix_obj &object1);
    void ptr_release();
    void mem_size();
};

