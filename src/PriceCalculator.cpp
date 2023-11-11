#include "PriceCalculator.h"
using namespace PriceCal;

double PriceCalculator::AcceptCash(const DiscountType type, const double money) const noexcept
{
    double cash = 0.0;
    switch (type)
    {
        case DiscountType::CASS_NORMAL: {
            cash = money;
        }
        break;
        default:
            break;
    }
    return cash;
}
