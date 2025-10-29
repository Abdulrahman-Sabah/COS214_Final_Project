#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorations.h"

class PotDecorator : public PlantDecorations {
private:
    string potType;
    double potCost;

public:
    PotDecorator(Plant* item, string pot, double cost);
    
    string description() override;
    double price() override;
    Plant* clone() override;
};

#endif