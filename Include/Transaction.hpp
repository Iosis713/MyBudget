#pragma once
#include <chrono>
#include <string>

class Transaction
{
  private:
    std::chrono::year_month_day date_ = std::chrono::January / 1 / 1970;
    float value_ = 0.0f;
    std::string description = "unknown";
    size_t categoryID_ = 0;

  public:
    Transaction();
    ~Transaction();
};
