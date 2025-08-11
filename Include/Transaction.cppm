module;
#include <chrono>
#include <string>

export module Transaction;

export class Transaction
{
private:
    std::chrono::year_month_day date_ = std::chrono::January / 1 / 1970;
    float value_ = 0.0f;
    std::string description_ = "unknown";
    size_t categoryID_ = 0;

public:
    Transaction() = delete;
    ~Transaction() = default;
    Transaction(const std::chrono::year_month_day& date, const float value,
                const std::string_view description, const size_t categoryID);

    Transaction(const float value, const std::string_view description,
                const size_t categoryID);

    inline std::chrono::year_month_day GetDate() const { return this->date_; }
    inline float GetValue() const { return this->value_; }
    inline const std::string& GetDescription() const
    {
        return this->description_;
    }
    inline size_t GetCategoryID() const { return this->categoryID_; }

    void ModifyDate(const std::chrono::year_month_day& date);
    void ModifyValue(const float value);
    void ModifyDescription(const std::string_view description);
    void ModifyCategoryID(const size_t categoryID);
};
