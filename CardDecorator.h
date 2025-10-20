
#ifndef CARDDECORATOR_H
#define CARDDECORATOR_H
#include "PlantDecorations.h"

class CardDecorator : public PlantDecorations {
private:
    string message;
    double cardCost;

public:
    CardDecorator(Plant* item, string msg, double cost);
    
    string description() override;
    double price() override;
    Plant* clone() override;
};

#endif