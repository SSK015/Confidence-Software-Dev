#include <gtest/gtest.h>

#include "PriceCalculator.h"

using namespace PriceCalc;

TEST(PriceCalculator, should_return_100_when_given_cash_normal_and_price_100)
{
    // given
    PriceCalculator priceCalculator;
    DiscountType discountType = DiscountType::CASH_NORMAL;
    double money = 100.0;

    // when
    double cash = priceCalculator.AcceptCash(discountType, money);

    // then
    EXPECT_DOUBLE_EQ(100.0, cash);
}

TEST(PriceCalculator, should_return_90_when_cash_percent_off_10_and_price_100)
{
    // given
    PriceCalculator priceCalculator;
    DiscountType discountType = DiscountType::CASH_PERCENTOFF_10;
    double money = 100.0;

    // when
    double cash = priceCalculator.AcceptCash(discountType, money);

    // then
    EXPECT_DOUBLE_EQ(90.0, cash);
}

TEST(PriceCalculator, should_return_80_when_cash_percent_off_20_and_price_100)
{
    // given
    PriceCalculator priceCalculator;
    DiscountType discountType = DiscountType::CASH_PERCENTOFF_20;
    double money = 100.0;

    // when
    double cash = priceCalculator.AcceptCash(discountType, money);

    // then
    EXPECT_DOUBLE_EQ(80.0, cash);
}

TEST(PriceCalculator, should_return_70_when_cash_percent_off_30_and_price_100)
{
    // given
    PriceCalculator priceCalculator;
    DiscountType discountType = DiscountType::CASH_PERCENTOFF_30;
    double money = 100.0;

    // when
    double cash = priceCalculator.AcceptCash(discountType, money);

    // then
    EXPECT_DOUBLE_EQ(70.0, cash);
}

TEST(PriceCalculator, should_return_90_when_given_cash_back_and_price_90)
{
    // given
    PriceCalculator priceCalculator;
    DiscountType discountType = DiscountType::CASH_BACK;
    double money = 90.0;

    // when
    double cash = priceCalculator.AcceptCash(discountType, money);

    // then
    EXPECT_DOUBLE_EQ(90.0, cash);
}

TEST(PriceCalculator, should_return_80_when_given_cash_back_and_price_100)
{
    // given
    PriceCalculator priceCalculator;
    DiscountType discountType = DiscountType::CASH_BACK;
    double money = 100.0;

    // when
    double cash = priceCalculator.AcceptCash(discountType, money);

    // then
    EXPECT_DOUBLE_EQ(80.0, cash);
}
