#ifndef LOYALTYDISCOUNT_H
#define LOYALTYDISCOUNT_H

#include "DiscountStrategy.h"

class LoyaltyDiscount : public DiscountStrategy {
    public:
    double applyDiscount(Order* order) override;
    ~LoyaltyDiscount() override = default;
};

#endif