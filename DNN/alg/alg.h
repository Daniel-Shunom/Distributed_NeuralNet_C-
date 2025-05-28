#pragma once 
#include <unordered_map>
#include "../types/types.h"
#include "../methods/Data_Operations/MatrixOps.h"
#include "../methods/Data_Operations/DataOps.h"
#include "../methods/Propagations/Propagation.h"


class Alg {
public:
    std::unordered_map<int, vMatrix> NetCache = {};
    matrix_obj calc_prod(MatrixOps m, Node v);
    void set_input_lyr(LC &cache, matrix_obj mx);
    //void backprop();
    void forwardprop(LC &cache);
    //void param_cache();
};