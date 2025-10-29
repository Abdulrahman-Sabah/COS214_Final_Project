#include "LoyaltyDiscount.h"

double LoyaltyDiscount::applyDiscount(Order* order){
    double total = order->getTotalPrice();
    double discounted = 0.05 * total; 
    double newTotal = total - discounted;
    return newTotal;
}