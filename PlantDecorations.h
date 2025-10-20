#ifndef PLANTDECORATIONS_H
#define PLANTDECORATIONS_H

#include <string>
#include "Plant.h"

using namespace std;

class PlantDecorations : public Plant {
protected:
    Plant* wrappedPlant;  // The plant being decorated
    
    virtual ~PlantDecorations() {
        // Note: Decide on ownership - should decorator delete wrapped plant?
        // For now, assuming decorator owns the wrapped plant
        delete wrappedPlant;
    }
    
public:
    PlantDecorations(Plant* item) : wrappedPlant(item) {}
    
    // Pure virtual methods that concrete decorators must implement
    virtual string description() = 0;
    virtual double price() = 0;
    virtual Plant* clone() = 0;
};

#endif