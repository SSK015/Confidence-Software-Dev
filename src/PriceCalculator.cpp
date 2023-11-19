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
            std::unique_ptr<Normal> normal = std::make_unique<Normal>();
            cash = normal->AcceptCash(money);
            break;
        }

        case DiscountType::CASH_PERCENTOFF_10:
        {
            std::unique_ptr<PercentOff> percentOff = std::make_unique<PercentOff>();
            cash = percentOff->AcceptCash(money);
            // cash = PercentOff(money);
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
            std::unique_ptr<CashBack> cashBack = std::make_unique<CashBack>();
            cash = cashBack->AcceptCash(money);
            break;
        }
        }

        return cash;
    }
} // namespace PriceCalc