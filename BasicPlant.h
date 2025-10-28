#ifndef BASICPLANT_H
#define BASICPLANT_H

#include "Plant.h"

class BasicPlant : public Plant {
private:
    double basePrice;
    string plantDescription;

public:
    BasicPlant(string name, string description, double price, 
               string careType = "Basic", string state = "Healthy", 
               string season = "AllSeason");
    
    string description() override;
    double price() override;
    Plant* clone() override;
};

#endif