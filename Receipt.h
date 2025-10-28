#ifndef RECEIPT_H
#define RECEIPT_H

#include <vector>
#include "Plant.h"

class Receipt
{
    private:
        std::vector<Plant*> purchasedPlants;
        double totalAmount;
    
    public:
        void addPlant(Plant* plant);
        void printReceipt() const;
};

#endif