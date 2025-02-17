#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>

//class ParamMangr;
//class NodeManagr;

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
private:
    static std::shared_ptr<NodeMangr> instance;
    NodeMangr();
public:
    /// @brief Returns singleton instance of NodeMangr
    /// @return NodeMangr shared_ptr
    static std::shared_ptr<NodeMangr> getNodeMangr();

    /// @brief  tbh idk what to do with this yet.
    static std::vector<std::shared_ptr<CacheMangr>> NodeStore;

    /// @brief 
    void TypeCache();

    /// @brief Store for NodeMangr tracked params
    void Store();

    /// @brief Builds the cache tree for Autograd usage
    /// @param node 
    void CacheTree(CacheCM &node);

    /// @brief Layer bundler method. Function TBD
    void layer_bundler();

    /// @brief Determines if regularization method can be excuted on Node.
    /// @return Return bool confirming method execution
    bool regularize();

    /// @brief Stores gradient props of Node
    void gradient();
};