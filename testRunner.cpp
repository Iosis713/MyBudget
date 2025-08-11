#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <chrono>
#include <filesystem>

import Category;
import Transaction;

class CategoriesFixture : public testing::Test
{
public:
    Categories categories;
    void SetUp() override;
};

TEST_F(CategoriesFixture, SaveToLoadFromFileTest)
{
    Categories targetCategories;

    categories.SaveToFile("testfile.csv");
    targetCategories.LoadFromFile("testfile.csv");

    bool result = true;
    for (const auto& [id, name] : categories.GetCategories())
    {
        result &= targetCategories.GetCategoryName(id) == name;
    }

    ASSERT_TRUE(result);
    std::filesystem::remove("testfile.csv");
}

TEST_F(CategoriesFixture, InvalidLoadFromFile)
{
    ASSERT_THROW(categories.LoadFromFile("SomeInvalidFile"),
                 std::runtime_error);
}

TEST_F(CategoriesFixture, FindByIDPositive)
{
    const std::string result = categories.Find(2)->second;

    ASSERT_EQ(result, "SecondCategory");
}

TEST_F(CategoriesFixture, FindByIDThrow)
{
    ASSERT_THROW(categories.Find(-1), std::runtime_error);
}

TEST_F(CategoriesFixture, FindByNamePositive)
{
    const std::string expectedValue = "FirstCategory";
    const std::string result = categories.Find(expectedValue)->second;

    ASSERT_EQ(result, expectedValue);
}

TEST_F(CategoriesFixture, FindByNameThrow)
{
    ASSERT_THROW(categories.Find("NoName"), std::runtime_error);
}

////////////////////////////////////////////////////////////////

using namespace std::chrono_literals;

class TransactionFixture : public testing::Test
{
public:
    Transaction transactionFixture{
        std::chrono::year_month_day(2025y, std::chrono::August, 11d), 100.f,
        "Description", 1};
};

TEST_F(TransactionFixture, ModifyDateTest)
{
    using namespace std::chrono;
    const auto expectedDate =
        std::chrono::year_month_day{2025y, std::chrono::August, 10d};

    transactionFixture.ModifyDate(expectedDate);

    ASSERT_EQ(transactionFixture.GetDate(), expectedDate);
}

TEST_F(TransactionFixture, ModifyValueTest)
{
    const float expectedValue = 90.f;

    transactionFixture.ModifyValue(expectedValue);

    ASSERT_EQ(transactionFixture.GetValue(), expectedValue);
}

TEST_F(TransactionFixture, ModifyDescriptionTest)
{
    const std::string expectedDescription = "NewDescription";

    transactionFixture.ModifyDescription(expectedDescription);

    ASSERT_EQ(transactionFixture.GetDescription(), expectedDescription);
}

TEST_F(TransactionFixture, ModifyCategoryIDTest)
{
    const size_t expectedID = 2;

    transactionFixture.ModifyCategoryID(expectedID);

    ASSERT_EQ(transactionFixture.GetCategoryID(), expectedID);
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
    categories.AddCategory(3, "ThirdCategory");
}