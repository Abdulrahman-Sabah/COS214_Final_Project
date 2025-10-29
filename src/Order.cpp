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

std::string Order::getNumber() {
    return number;
}

std::string Order::getItemList() {
    return itemList;
}

int Order::getNumItems() {
    return numItems;
}

double Order::getTotalPrice() {
    return totalPrice;
}

DiscountStrategy* Order::getDiscount() {
    return discount;
}

void Order::setNumber(std::string number) {
    this->number = number;
}

void Order::setItemList(std::string itemList) {
    this->itemList = itemList;
}

void Order::setNumItems(int numItems) {
    this->numItems = numItems;
}

void Order::setTotalPrice(double totalPrice) {
    this->totalPrice = totalPrice;
}

void Order::setDiscount(DiscountStrategy* discount) {
    this->discount = discount;
}

void Order::processDiscount() {
    if (discount != nullptr) {
        totalPrice = discount->applyDiscount(this);
    }
}