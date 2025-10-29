#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include "Order.h"; 

class DiscountStrategy {
    public:
    virtual double applyDiscount(Order* order) = 0;
    virtual ~DiscountStrategy() = default;
};

#endif