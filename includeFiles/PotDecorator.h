#ifndef POTDECORATOR_H
#define POTDECORATOR_H

/**
 * @file PotDecorator.h
 * @brief Adds pot decoration and cost to a plant.
 */

#include "PlantDecorations.h"

/**
 * @class PotDecorator
 * @brief Decorator for adding a pot.
 */
class PotDecorator : public PlantDecorations {
private:
    string potType;
    double potCost;

public:
    /**
     * @brief Constructor
     * @param item Plant to decorate
     * @param pot Pot type
     * @param cost Extra cost
     */
    PotDecorator(Plant* item, string pot, double cost);

    /// @return Description including pot
    string description() override;

    /// @return Price + pot cost
    double price() override;

    /// @return Cloned decorated plant
    Plant* clone() override;
};

#endif // POTDECORATOR_H
