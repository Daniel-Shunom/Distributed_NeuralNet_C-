#include <iostream>
#include <vector>
#include <functional>
#include "./Propagations/Propagation.h"
#include "./HyperParams/HyperParams.h"

class MenuConstruct: Propagation, HyperParams {
private:
public:
    Propagation menu_props;
    HyperParams h_params;
    std::function<void(std::vector<float>)> select_activation();
    std::function<void(std::vector<float>)> output_nodes_config();
    std::tuple<std::function<void(std::vector<HyperParams::Node*>)>> configure_deepnet();
};