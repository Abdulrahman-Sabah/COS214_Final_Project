#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
    public:
    Order();
    Order(const std::string& number, const std::string& itemList, int numItems, double totalPrice);
    ~Order();
    
    private:
    std::string number;
    std::string itemList;
    int numItems;
    double totalPrice;

};


#endif