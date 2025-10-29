#include "ComboDiscount.h"

double ComboDiscount::applyDiscount(Order* order){
    double total = order->getTotalPrice();
    double discounted = 0.10 * total; 
    double newTotal = total - discounted;
    return newTotal;
}