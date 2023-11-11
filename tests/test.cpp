#include <gtest/gtest.h>

#include "PriceCalculator.h"

using namespace PriceCal;

TEST(PriceCalculator, PriceCalculator_should_return_100_when_given_cash_normal_and_price_100)
{
    // given
    PriceCalculator priceCalculator;
    // when
    double cash = priceCalculator.AcceptCash(DiscountType::CASS_NORMAL, 100.0);
    //then
    EXPECT_EQ(0, cash);
}