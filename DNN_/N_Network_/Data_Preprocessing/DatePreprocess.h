#include <iostream>
#include <vector>

class Data_Process { 
public:
    struct Input {
        std::vector<float> weights;
        std::vector<float> biases;
        std::vector<float> input;
        float input_y;
        float label_yhat;
    };

    Data_Process(/* args */);
    ~Data_Process();
};
