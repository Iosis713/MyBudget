module;
#include <format>
#include <fstream>
#include <sstream>

module Category;

void Categories::AddCategory(const size_t id, const std::string& name)
{
    categories_[id] = {Category{id, name}};
}

const Category& Categories::GetCategory(const size_t id) const
{
    return categories_.at(id);
}

void Categories::LoadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw(std::runtime_error(std::format(
            {"Invalid filename {}. Please check location of the file."},
            filename)));

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        Category category;

        if (!std::getline(ss, token, ';'))
            continue;
        category.id_ = static_cast<size_t>(std::stol(token));

        if (!std::getline(ss, token, '\n'))
            continue;
        category.name_ = token;

        categories_[category.id_] = category;
    }
}

void Categories::SaveToFile(const std::string filename) const
{
    std::ofstream file(filename);
    if (!file)
        throw(std::runtime_error(std::format(
            {"Failed to open file '{}'. Check path or permissions."},
            filename)));

    for (const auto& [id, category] : categories_)
        file << id << ';' << category.name_ << '\n';
}