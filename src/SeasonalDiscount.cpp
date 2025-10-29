#include "SeasonalDiscount.h"

double SeasonalDiscount::applyDiscount(double totalPrice){
    double discounted = totalPrice * 0.25; 
    double newTotal = totalPrice - discounted;
    return newTotal;
}