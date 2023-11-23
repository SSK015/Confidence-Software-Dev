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
    class Discount
    {
    public:
        virtual double AcceptCash(const double money) const noexcept = 0;
        virtual ~Discount() = default;
    };

    class Normal final : public Discount
    {
    public:
        static Normal &getInstance()
        {
            static Normal instance;
            return instance;
        }
        double AcceptCash(const double money) const noexcept override
        {
            return money;
        }

    private:
        Normal()
        {
            std::cout << "Construct Function of Normal" << std::endl;
        }
    };

    class PercentOff final : public Discount
    {
    public:
        static PercentOff &getInstance()
        {
            static PercentOff instance;
            return instance;
        }

        void setRate(double newRate)
        {
            rate = newRate;
        }

        double AcceptCash(const double money) const noexcept override
        {
            return money * rate;
        }

    private:
        double rate;
        PercentOff() : rate(1.0)
        {
            std::cout << "Construct Function of PercentOff" << std::endl;
        }
    };

    class CashBack final : public Discount
    {
    public:
        static CashBack &getInstance()
        {
            static CashBack instance;
            return instance;
        }
        double AcceptCash(const double money) const noexcept override
        {
            const double threshold = 100.0;
            const double cashback = 20.0;
            return money - std::floor(money / threshold) * cashback;
        }

    private:
        CashBack()
        {
            std::cout << "Construct Function of CashBack" << std::endl;
        }
    };

    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const noexcept
        {
            switch (discountType)
            {
            case DiscountType::CASH_NORMAL:
                return Normal::getInstance().AcceptCash(money);
            case DiscountType::CASH_PERCENTOFF_10:
                PercentOff::getInstance().setRate(0.9);
                return PercentOff::getInstance().AcceptCash(money);
            case DiscountType::CASH_PERCENTOFF_20:
                PercentOff::getInstance().setRate(0.8);
                return PercentOff::getInstance().AcceptCash(money);
            case DiscountType::CASH_PERCENTOFF_30:
                PercentOff::getInstance().setRate(0.7);
                return PercentOff::getInstance().AcceptCash(money);
            case DiscountType::CASH_BACK:
                return CashBack::getInstance().AcceptCash(money);
            default:
                return Normal::getInstance().AcceptCash(money);
            }
        }
        PriceCalculator()
        {
        }
    };
} // namespace PriceCalc