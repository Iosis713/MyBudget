#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <filesystem>

import Category;

class CategoriesFixture : public testing::Test
{
public:
    Categories categories;
    void SetUp() override;
};

TEST_F(CategoriesFixture, SaveToLoadFromFileTest)
{
    // GIVEN
    Categories targetCategories;

    // WHEN
    categories.SaveToFile("testfile.csv");
    targetCategories.LoadFromFile("testfile.csv");

    bool result = true;
    for (const auto& [id, category] : categories.GetCategories())
    {
        result &=
            targetCategories.GetCategory(category.id_).name_ == category.name_;
    }

    ASSERT_TRUE(result);
    std::filesystem::remove("testfile.csv");
}

TEST_F(CategoriesFixture, InvalidLoadFromFile)
{
    // GIVEN WHEN THEN
    ASSERT_THROW(categories.LoadFromFile("SomeInvalidFile"),
                 std::runtime_error);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void CategoriesFixture::SetUp()
{
    categories.AddCategory(1, "FirstCategory");
    categories.AddCategory(2, "SecondCategory");
}