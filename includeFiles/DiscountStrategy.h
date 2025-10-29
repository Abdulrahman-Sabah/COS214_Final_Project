#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class Order; 

class DiscountStrategy {
    public:
    virtual double applyDiscount(double totalPrice) = 0;
    virtual ~DiscountStrategy() = default;
};

#endif