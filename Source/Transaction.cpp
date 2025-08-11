module;
#include <chrono>
#include <string>
#include <string_view>

module Transaction;

Transaction::Transaction(const std::chrono::year_month_day& date,
                         const float value, const std::string_view description,
                         const size_t categoryID)
    : date_(date), value_(value), description_(description),
      categoryID_(categoryID) {};

Transaction::Transaction(const float value, const std::string_view description,
                         const size_t categoryID)
    : date_(std::chrono::floor<std::chrono::days>(
          std::chrono::system_clock::now())),
      value_(value), description_(description), categoryID_(categoryID) {};

void Transaction::ModifyDate(const std::chrono::year_month_day& date)
{
    this->date_ = date;
};
void Transaction::ModifyValue(const float value)
{
    this->value_ = value;
};
void Transaction::ModifyDescription(const std::string_view description)
{
    this->description_ = description;
};
void Transaction::ModifyCategoryID(const size_t categoryID)
{
    this->categoryID_ = categoryID;
};
