#include "PriceCalculator.h"

#include <cmath>

namespace PriceCalc
{
    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        double cash = 0.0;

        switch (discountType)
        {
        case DiscountType::CASH_NORMAL:
        {
            cash = Normal(money);
            break;
        }

        case DiscountType::CASH_PERCENTOFF_10:
        {
            const double discountRate = 0.9;

            cash = money * discountRate;
            break;
        }

        case DiscountType::CASH_PERCENTOFF_20:
        {
            const double discountRate = 0.8;

            cash = money * discountRate;
            break;
        }

        case DiscountType::CASH_PERCENTOFF_30:
        {
            const double discountRate = 0.7;

            cash = money * discountRate;
            break;
        }

        case DiscountType::CASH_BACK:
        {
            const double threshold = 100.0;
            const double cashback = 20.0;

            cash = money - std::floor(money / threshold) * cashback;

            break;
        }
        }

        return cash;
    }
} // namespace PriceCalc