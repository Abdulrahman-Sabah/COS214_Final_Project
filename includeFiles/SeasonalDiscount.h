#ifndef SEASONALDISCOUNT_H
#define SEASONALDISCOUNT_H

#include "DiscountStrategy.h"   

class SeasonalDiscount : public DiscountStrategy {
    public:
    double applyDiscount(double totalPrice) override;
    ~SeasonalDiscount() override = default;
};

#endif