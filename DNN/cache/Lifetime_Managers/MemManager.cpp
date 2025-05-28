#include "MemManager.h"

// Defined static members
MemManager MemManager::my_instance;
std::vector<std::shared_ptr<vMatrix>> MemManager::MemCache;

void MemManager::mem_size() {
    std::cout << "Memory Cache Size: " << MemCache.size() << '\n';
}

void MemManager::ptr_freeze(std::shared_ptr<vMatrix> &object1) {
    MemCache.push_back(object1);
}

MemManager& MemManager::getInstance() {
    return my_instance;
}

void MemManager::ptr_release() {
    MemCache.clear();
}

