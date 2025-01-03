#include <iostream>
#include <vector>

class Data_Processor { 
public:
    struct Input {
        std::vector<float> weights;
        std::vector<float> biases;
        std::vector<float> input;
        float input_y;
        float label_yhat;
    };

    void weight_update();
    void weight_cache();
    void bias_update();
    void bias_cache();

    void input_norm();
    void input_sort();
    void input_format();
    void input_classify();

    Data_Processor(/* args */);
    ~Data_Processor();
};
