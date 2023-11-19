#pragma once

enum class DiscountType
{
    CASH_NORMAL,
    CASH_PERCENTOFF_10,
    CASH_PERCENTOFF_20,
    CASH_PERCENTOFF_30,
    CASH_BACK,
};

namespace PriceCalc
{
    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const noexcept;

    private:
        double Normal(const double money) const noexcept
        {
            return money;
        };

        double PercentOff(const double money) const noexcept
        {
            const double discountRate = 0.9;
            return money * discountRate;
        };
    };
} // namespace PriceCalc