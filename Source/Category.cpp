module;
#include <format>
#include <fstream>
#include <ranges>
#include <sstream>
#include <string_view>
#include <unordered_map>

module Category;

void Categories::AddCategory(const size_t id, const std::string& name)
{
    categories_[id] = name;
}

const std::unordered_map<size_t, std::string>& Categories::GetCategories() const
{
    return this->categories_;
}

const std::string Categories::GetCategoryName(const size_t id) const
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
        std::string id;
        std::string token;

        if (!std::getline(ss, id, ';'))
            continue;

        if (!std::getline(ss, token, '\n'))
            continue;

        categories_[static_cast<size_t>(std::stol(id))] = token;
    }
}

void Categories::SaveToFile(const std::string filename) const
{
    std::ofstream file(filename);
    if (!file)
        throw(std::runtime_error(std::format(
            {"Failed to open file '{}'. Check path or permissions."},
            filename)));

    for (const auto& [id, name] : categories_)
        file << id << ';' << name << '\n';
}

CategoriesMap::const_iterator Categories::Find(const size_t findValue) const
{
    const auto it = categories_.find(findValue);
    if (it == categories_.end())
        throw std::runtime_error(
            std::format("No category found with key [{}]", findValue));

    return it;
}

CategoriesMap::const_iterator Categories::Find(std::string_view findValue) const
{
    const auto it =
        std::ranges::find_if(categories_, [&findValue](const auto& it)
                             { return it.second == findValue; });

    if (it == categories_.end())
        throw std::runtime_error(
            std::format("No category found with name [{}]", findValue));

    return it;
}
