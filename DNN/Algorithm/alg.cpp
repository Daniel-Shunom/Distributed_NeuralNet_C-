#include "./alg.h"

void Alg::set_input_lyr(LC &cache, std::shared_ptr<vMatrix> mx) {
    DataOps d;
    std::cout<< "setting input layer\n";
    for (auto &nd: cache[0]) {
        std::cout<< "begining operation\n";
        nd.inputs = d.v_matrix_copy(mx);
    }
    std::cout<< "set layer\n";
}

std::shared_ptr<vMatrix> Alg::calc_prod(MatrixOps m, Node v) {
    std::shared_ptr<vMatrix> temp = m.v_matrix_multiply(v.inputs, v.Weights);
    std::shared_ptr<vMatrix> tmp = m.v_matrix_add(temp, v.Biases); 
    return tmp;
}

void Alg::forwardprop(LC &cache) {
    std::cout<< "pass called \n";
    Propagation p;
    MatrixOps m;
    std::shared_ptr<vMatrix> mx;
    size_t csh = cache.size();
    int idx = 0;
    for (auto &lyr: cache) {
        idx++;
        std::shared_ptr<vMatrix> sum;
        size_t l = lyr.size();
        for (size_t i = 0; i<l-1; i++) {
            mx = calc_prod(m, lyr[i]);
            lyr[i].Activations = p.v_tanh_activation(mx);
            sum = m.v_matrix_add(sum, lyr[i].Activations);
            *lyr[idx+1].inputs = *sum;
        }
        NetCache.insert(std::make_pair(idx, *sum));
    }
}