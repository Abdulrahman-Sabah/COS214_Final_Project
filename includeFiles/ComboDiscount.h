#ifndef COMBODISCOUNT_H
#define COMBODISCOUNT_H

#include "DiscountStrategy.h"

class ComboDiscount : public DiscountStrategy {
    public:
    double applyDiscount(double totalPrice) override;
    ~ComboDiscount() override = default;
};

#endif