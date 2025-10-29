#include "LoyaltyDiscount.h"

double LoyaltyDiscount::applyDiscount(double totalPrice){
    double discounted = totalPrice * 0.05; 
    double newTotal = totalPrice - discounted;
    return newTotal;
}