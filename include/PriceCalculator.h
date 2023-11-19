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
        class Discount
        {
        public:
            virtual double AcceptCash(const double money) const noexcept = 0;
            virtual ~Discount() = default;
        };
        class Normal final : public Discount
        {
        public:
            double AcceptCash(const double money) const noexcept override
            {
                return money;
            };
        };
        class PercentOff final : public Discount
        {
        public:
            explicit PercentOff(const double rate) : rate(rate)
            {
            }
            double AcceptCash(const double money) const noexcept override
            {
                // const double discountRate = 0.9;
                return money * rate;
            };

        private:
            double rate;
        };
        class CashBack final : public Discount
        {
        public:
            double AcceptCash(const double money) const noexcept override
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