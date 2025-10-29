#include "SeasonalDiscount.h"

double SeasonalDiscount::applyDiscount(Order* order){
    double total = order->getTotalPrice();
    double discounted = 0.25 * total; 
    double newTotal = total - discounted;
    return newTotal;
}