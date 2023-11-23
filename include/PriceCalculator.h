#pragma once

#include <cmath>
#include <memory>
#include <functional>
#include <iostream>

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
    class IDiscountStrategy
    {
    public:
        virtual double AcceptCash(const double money) const = 0;
        virtual ~IDiscountStrategy() = default;
    };

    class NormalStrategy final : public IDiscountStrategy
    {
    public:
        static NormalStrategy &getInstance()
        {
            static NormalStrategy instance;
            return instance;
        }

        double AcceptCash(const double money) const override
        {
            return money;
        }

    private:
        NormalStrategy()
        {
            std::cout << "Construct Function of Normal!" << std::endl;
        };
    };

    class PercentOffStrategy final : public IDiscountStrategy
    {
    public:
        static PercentOffStrategy &getInstance()
        {
            static PercentOffStrategy instance;
            return instance;
        }

        void setRate(double newRate)
        {
            rate = newRate;
        }

        double AcceptCash(const double money) const override
        {
            return money * rate;
        }

    private:
        double rate;
        PercentOffStrategy() : rate(1.0)
        {
            std::cout << "Construct Function of PercentOff!" << std::endl;
        }
    };

    class CashBackStrategy final : public IDiscountStrategy
    {
    public:
        static CashBackStrategy &getInstance()
        {
            static CashBackStrategy instance;
            return instance;
        }

        double AcceptCash(const double money) const override
        {
            const double threshold = 100.0;
            const double cashback = 20.0;
            return money - std::floor(money / threshold) * cashback;
        }

    private:
        CashBackStrategy()
        {
            std::cout << "Construct Function of CashBack" << std::endl;
        };
    };

    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const
        {
            const IDiscountStrategy *strategy;
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
    };
}
