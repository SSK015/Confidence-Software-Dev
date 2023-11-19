#pragma once

#include <cmath>
#include <memory>

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
        class Normal final
        {
        public:
            double AcceptCash(const double money) const noexcept
            {
                return money;
            };
        };
        class PercentOff final
        {
        public:
            double AcceptCash(const double money) const noexcept
            {
                const double discountRate = 0.9;
                return money * discountRate;
            };
        };
        class CashBack final
        {
        public:
            double AcceptCash(const double money) const noexcept
            {
                const double threshold = 100.0;
                const double cashback = 20.0;

                double cash = money - std::floor(money / threshold) * cashback;
                // break;
                return cash;
            };
        };
    };
} // namespace PriceCalc