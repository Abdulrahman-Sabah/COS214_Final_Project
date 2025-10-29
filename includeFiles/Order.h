#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "DiscountStrategy.h"

class Order {
    public:
    Order();
    Order(std::string number, std::string itemList, int numItems, double totalPrice, DiscountStrategy* discount);
    ~Order();
    std::string getNumber();
    std::string getItemList();
    int getNumItems();
    double getTotalPrice();
    DiscountStrategy* getDiscount();
    void setNumber(std::string number);
    void setItemList(std::string itemList); 
    void setNumItems(int numItems);
    void setTotalPrice(double totalPrice);
    void setDiscount(DiscountStrategy* discount);
    void processDiscount();

    private:
    std::string number;
    std::string itemList;
    int numItems;
    double totalPrice;
    DiscountStrategy* discount;
};


#endif