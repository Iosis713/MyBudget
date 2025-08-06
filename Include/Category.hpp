#pragma once
#include <cstdint>
#include <fstream>
#include <string>
#include <unordered_map>

struct Category
{
    size_t id_;
    std::string name_;
};

class Categories
{
private:
    std::unordered_map<size_t, Category> categories_;

public:
    void AddCategory(const size_t id, const std::string& name);
    const Category& GetCategory(const size_t id) const;
    bool LoadFromFile(const std::string& filename);
};
