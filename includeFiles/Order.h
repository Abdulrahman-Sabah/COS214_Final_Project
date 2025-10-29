#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "DiscountStrategy.h"

class Order {
    public:
    Order();
    Order(std::string number, std::string itemList, int numItems, double totalPrice, DiscountStrategy* discount);
    ~Order();

    private:
    std::string number;
    std::string itemList;
    int numItems;
    double totalPrice;
    DiscountStrategy* discount;
};


#endif