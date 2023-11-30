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
    class Strategy
    {
    public:
        virtual double AcceptCash(const double money) const = 0;
        virtual ~Strategy() = default;
    };

    class NormalStrategy final : public Strategy
    {
    public:
        static NormalStrategy &getInstance();
        double AcceptCash(const double money) const override;

    private:
        NormalStrategy();
    };

    class PercentOffStrategy final : public Strategy
    {
    public:
        static PercentOffStrategy &getInstance();
        void setRate(double newRate);
        double AcceptCash(const double money) const override;

    private:
        double rate;
        PercentOffStrategy();
    };

    class CashBackStrategy final : public Strategy
    {
    public:
        static CashBackStrategy &getInstance();
        double AcceptCash(const double money) const override;

    private:
        CashBackStrategy();
    };

    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const;
    };
}
