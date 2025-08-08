module;
#include <cstdint>
#include <string>
#include <unordered_map>

export module Category;

export class Categories
{
private:
    std::unordered_map<size_t, std::string> categories_;

public:
    void AddCategory(const size_t id, const std::string& name);
    const std::string GetCategoryName(const size_t id) const;
    const std::unordered_map<size_t, std::string>& GetCategories() const;
    void LoadFromFile(const std::string& filename);
    void SaveToFile(const std::string filename) const;
};
