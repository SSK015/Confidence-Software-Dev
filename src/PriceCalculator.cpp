#include "PriceCalculator.h"

namespace PriceCalc
{
    NormalStrategy &NormalStrategy::getInstance()
    {
        static NormalStrategy instance;
        return instance;
    }

    double NormalStrategy::AcceptCash(const double money) const
    {
        return money;
    }

    NormalStrategy::NormalStrategy()
    {
        std::cout << "Construct Function of Normal!" << std::endl;
    }

    PercentOffStrategy &PercentOffStrategy::getInstance()
    {
        static PercentOffStrategy instance;
        return instance;
    }

    void PercentOffStrategy::setRate(double newRate)
    {
        rate = newRate;
    }

    double PercentOffStrategy::AcceptCash(const double money) const
    {
        return money * rate;
    }

    PercentOffStrategy::PercentOffStrategy() : rate(1.0)
    {
        std::cout << "Construct Function of PercentOff!" << std::endl;
    }

    CashBackStrategy &CashBackStrategy::getInstance()
    {
        static CashBackStrategy instance;
        return instance;
    }

    double CashBackStrategy::AcceptCash(const double money) const
    {
        const double threshold = 100.0;
        const double cashback = 20.0;
        return money - std::floor(money / threshold) * cashback;
    }

    CashBackStrategy::CashBackStrategy()
    {
        std::cout << "Construct Function of CashBack" << std::endl;
    }

    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const
    {
        const Strategy *strategy;
        switch (discountType)
        {
        case DiscountType::CASH_NORMAL:
            strategy = &NormalStrategy::getInstance();
            break;
        case DiscountType::CASH_PERCENTOFF_10:
            PercentOffStrategy::getInstance().setRate(0.9);
            strategy = &PercentOffStrategy::getInstance();
            break;
        case DiscountType::CASH_PERCENTOFF_20:
            PercentOffStrategy::getInstance().setRate(0.8);
            strategy = &PercentOffStrategy::getInstance();
            break;
        case DiscountType::CASH_PERCENTOFF_30:
            PercentOffStrategy::getInstance().setRate(0.7);
            strategy = &PercentOffStrategy::getInstance();
            break;
        case DiscountType::CASH_BACK:
            strategy = &CashBackStrategy::getInstance();
            break;
        default:
            strategy = &NormalStrategy::getInstance();
            break;
        }

        return strategy->AcceptCash(money);
    }
}
