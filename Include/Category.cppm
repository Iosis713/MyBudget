module;
#include <cstdint>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>

export module Category;
export using CategoriesMap = std::unordered_map<size_t, std::string>;
export using CategoriesPair = std::pair<size_t, std::string>;

export class Categories
{
private:
    CategoriesMap categories_;

public:
    void AddCategory(const size_t id, const std::string& name);
    const std::string GetCategoryName(const size_t id) const;
    const std::unordered_map<size_t, std::string>& GetCategories() const;
    void LoadFromFile(const std::string& filename);
    void SaveToFile(const std::string filename) const;
    CategoriesMap::const_iterator Find(const size_t findValue) const;
    CategoriesMap::const_iterator Find(std::string_view findValue) const;
};
