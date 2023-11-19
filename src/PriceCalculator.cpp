#include "PriceCalculator.h"

#include <cmath>
#include <unordered_map>

namespace PriceCalc
{
    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        // double cash = 0.0;
        std::unordered_map<DiscountType, std::unique_ptr<Discount>> discountMap;

        discountMap.emplace(DiscountType::CASH_NORMAL, std::make_unique<Normal>());
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, std::make_unique<PercentOff>(0.9));
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, std::make_unique<PercentOff>(0.8));
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, std::make_unique<PercentOff>(0.7));
        discountMap.emplace(DiscountType::CASH_BACK, std::make_unique<CashBack>());

        return discountMap.find(discountType)->second->AcceptCash(money);

        // std::unique_ptr<Discount> discount;

        // switch (discountType)
        // {
        // case DiscountType::CASH_NORMAL:
        // {
        //     discount = std::make_unique<Normal>();
        //     break;
        // }

        // case DiscountType::CASH_PERCENTOFF_10:
        // {
        //     discount = std::make_unique<PercentOff>(0.9);
        //     break;
        // }

        // case DiscountType::CASH_PERCENTOFF_20:
        // {
        //     discount = std::make_unique<PercentOff>(0.8);
        //     break;
        // }

        // case DiscountType::CASH_PERCENTOFF_30:
        // {
        //     discount = std::make_unique<PercentOff>(0.7);
        //     break;
        // }

        // case DiscountType::CASH_BACK:
        // {
        //     discount = std::make_unique<CashBack>();
        //     break;
        // }
        // }
        // cash = discount->AcceptCash(money);
        // return cash;
    }
} // namespace PriceCalc