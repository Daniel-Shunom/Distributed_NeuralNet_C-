#pragma once 
#include <unordered_map>
#include "../Essential_Params/Params.h"
#include "../Essential_Methods/Data_Operations/MatrixOps.h"
#include "../Essential_Methods/Data_Operations/DataOps.h"
#include "../Essential_Methods/Propagations/Propagation.h"


class Alg {
public:
    std::unordered_map<int, vMatrix> NetCache = {};
    std::shared_ptr<vMatrix> calc_prod(MatrixOps m, Node v);
    void set_input_lyr(LC &cache, std::shared_ptr<vMatrix> mx);
    //void backprop();
    void forwardprop(LC &cache);
    //void param_cache();
};