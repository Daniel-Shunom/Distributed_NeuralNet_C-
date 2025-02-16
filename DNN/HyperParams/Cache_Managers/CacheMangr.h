#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>

class ParamMangr;
class NodeManagr;

class CacheMangr {
public:   
    virtual void TypeCache() const = 0;
    virtual void Store() const = 0;
    bool activity();
    bool used();

    typedef std::shared_ptr<CacheMangr> CacheCM;
    std::shared_ptr<CacheMangr> type_obj1;
    std::shared_ptr<CacheMangr> type_obj2;
    virtual void CacheTree(CacheCM) = 0;
};

class ParamMangr: CacheMangr {
    static std::vector<std::shared_ptr<CacheMangr>> ParamStore;
    void TypeCache();
    void Store();
    void CacheTree(CacheCM);
};

class NodeMangr: CacheMangr {
    static std::vector<std::shared_ptr<CacheMangr>> NodeStore;
    void TypeCache();
    void Store();
    void CacheTree(CacheCM);

    void layer_bundler();
    bool regularize();
    void gradient();
};