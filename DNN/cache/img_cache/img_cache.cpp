#include "img_cache.h"

// Defined static members
ImgCache ImgCache::my_instance;
std::vector<matrix_obj> ImgCache::MemCache;

void ImgCache::mem_size() {
    std::cout << "Memory Cache Size: " << MemCache.size() << '\n';
}

void ImgCache::ptr_freeze(matrix_obj &object1) {
    MemCache.push_back(object1);
}

ImgCache& ImgCache::getInstance() {
    return my_instance;
}

void ImgCache::ptr_release() {
    MemCache.clear();
}

