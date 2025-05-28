#include "CacheMangr.h"
std::vector<std::shared_ptr<CacheMangr>> ParamMangr::ParamStore;
std::shared_ptr<NodeMangr> NodeMangr::instance;
std::vector<std::shared_ptr<CacheMangr>> NodeMangr::NodeStore;

bool CacheMangr::used() {
    std::cout << "used";
    return 0>1;
}

bool CacheMangr::activity() {
    std::cout << "activity";
    return 0>1;
}

std::shared_ptr<NodeMangr> NodeMangr::getNodeMangr() {
    return instance;
}

void NodeMangr::Store() {
    std::cout << "NodeManager Called\n";
}

template<typename RtnType, typename... Args>
NodeMangr::FuncObj<RtnType, Args...> 
NodeMangr::usedFunction(FuncObj<RtnType, Args...> func) {
    std::cout << "Collected Forward pass function";
    NodeFunction = func;
}

//void NodeMangr::TypeCache() {};

void NodeMangr::CacheTree(CacheCM &node) {
    bool is_used = used();
    auto traveler = [this](auto type) {
        while (!type) {
            CacheTree(type);
        }
    };

    is_used ? type_obj1 = node, traveler(type_obj1) 
    : type_obj2 = node, traveler(type_obj2);
}

void ParamMangr::Store() {
    std::cout << "ParamManager Called\n";
}

void NodeMangr::TypeCache() {
    NodeStore.push_back(type_obj2);
} 

void ParamMangr::TypeCache() {
    ParamStore.push_back(type_obj1);
}
