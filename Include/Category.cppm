module;
#include <cstdint>
#include <string>
#include <unordered_map>

export module Category;

export struct Category
{
    size_t id_;
    std::string name_;
};

export class Categories
{
private:
    std::unordered_map<size_t, Category> categories_;

public:
    void AddCategory(const size_t id, const std::string& name);
    const Category& GetCategory(const size_t id) const;
    const std::unordered_map<size_t, Category>& GetCategories() const
    {
        return this->categories_;
    }
    void LoadFromFile(const std::string& filename);
    void SaveToFile(const std::string filename) const;
};
