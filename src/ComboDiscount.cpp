#include "ComboDiscount.h"

double ComboDiscount::applyDiscount(double totalPrice){
    double discounted = totalPrice * 0.1; 
    double newTotal = totalPrice - discounted;
    return newTotal;
}