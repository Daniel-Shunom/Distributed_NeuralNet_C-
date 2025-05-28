#pragma once

#include "../../types/types.h"
#include <vector>
#include <iostream>
#include <initializer_list>

class MemManager {
private:
    MemManager() = default;
    static MemManager my_instance;
    static std::vector<std::shared_ptr<vMatrix>> MemCache;
public:
    static MemManager& getInstance();
    void ptr_freeze(std::shared_ptr<vMatrix> &object1);
    void ptr_release();
    void mem_size();
};

