#include "Order.h"

Order::Order(){
    number = "#0";
    itemList = "";
    numItems = 0;
    totalPrice = 0.0;
    discount = nullptr;
}

Order::Order(std::string number, std::string itemList, int numItems, double totalPrice, DiscountStrategy* discount){
    this->number = number;
    this->itemList = itemList;
    this->numItems = numItems;
    this->totalPrice = totalPrice;
    this->discount = discount;
}

Order::~Order(){
}