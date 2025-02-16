#include "CacheMangr.h"

void NodeMangr::Store() {
    std::cout << "NodeManager Called\n";
}

void NodeMangr::TypeCache() {};

void NodeMangr::CacheTree(CacheCM node) {
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