#pragma once

namespace PriceCal
{
enum class DiscountType{CASS_NORMAL, PERCENTOFF, CASH_BACK};

class PriceCalculator final
{
public:
    double AcceptCash(const DiscountType type, const double money) const noexcept;
};
};