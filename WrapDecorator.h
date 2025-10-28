/**
 * @file WrapDecorator.h
 * @brief Concrete decorator for adding wrapping to plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef WRAPDECORATOR_H
#define WRAPDECORATOR_H

#include "PlantDecorations.h"

/**
 * @class WrapDecorator
 * @brief Concrete decorator that adds wrapping functionality to plants
 * 
 * This decorator adds wrapping features to plants, including wrap type and cost.
 * It extends the PlantDecorations base class to provide specific wrapping decoration.
 */
class WrapDecorator : public PlantDecorations {
private:
    string wrapType; ///< Type of wrapping being added
    double wrapCost; ///< Cost of the wrapping decoration

public:
    /**
     * @brief Constructor for WrapDecorator
     * @param item The plant to decorate with wrapping
     * @param wrap The type of wrapping to add
     * @param cost The cost of the wrapping
     */
    WrapDecorator(Plant* item, string wrap, double cost);
    
    /**
     * @brief Gets the description including wrapping information
     * @return String description of the plant with wrapping
     */
    string description() override;
    
    /**
     * @brief Gets the total price including wrapping cost
     * @return Total price of plant plus wrapping
     */
    double price() override;
    
    /**
     * @brief Creates a clone of the wrap-decorated plant
     * @return Pointer to cloned wrap-decorated plant
     */
    Plant* clone() override;
};

#endif