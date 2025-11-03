#ifndef WRAPDECORATOR_H
#define WRAPDECORATOR_H

/**
 * @file WrapDecorator.h
 * @brief Adds wrapping decoration and cost to a plant.
 */

#include "PlantDecorations.h"

/**
 * @class WrapDecorator
 * @brief Decorator for adding wrapping.
 */
class WrapDecorator : public PlantDecorations {
private:
    string wrapType;
    double wrapCost;

public:
    /**
     * @brief Constructor
     * @param item Plant to decorate
     * @param wrap Wrap type
     * @param cost Extra cost
     */
    WrapDecorator(Plant* item, string wrap, double cost);

    /// @return Description including wrap
    string description() override;

    /// @return Price + wrap cost
    double price() override;

    /// @return Cloned wrapped plant
    Plant* clone() override;
};

#endif // WRAPDECORATOR_H
