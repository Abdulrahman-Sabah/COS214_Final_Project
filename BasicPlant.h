/**
 * @file BasicPlant.h
 * @brief Basic concrete implementation of Plant class
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef BASICPLANT_H
#define BASICPLANT_H

#include "Plant.h"

/**
 * @class BasicPlant
 * @brief Simple concrete implementation of the Plant interface
 * 
 * BasicPlant provides a straightforward implementation of the Plant abstract class
 * with basic properties and functionality. It can be used as a generic plant type
 * or as a base for more specialized plant implementations.
 */
class BasicPlant : public Plant {
private:
    double basePrice;        ///< Base price of the plant
    string plantDescription; ///< Description of the plant

public:
    /**
     * @brief Constructor for BasicPlant
     * @param name Name of the plant
     * @param description Description of the plant
     * @param price Base price of the plant
     * @param careType Type of care required (default: "Basic")
     * @param state Current state of the plant (default: "Healthy")
     * @param season Optimal season for the plant (default: "AllSeason")
     */
    BasicPlant(string name, string description, double price, 
               string careType = "Basic", string state = "Healthy", 
               string season = "AllSeason");
    
    /**
     * @brief Gets the description of the plant
     * @return String containing the plant description
     */
    string description() override;
    
    /**
     * @brief Gets the price of the plant
     * @return Double representing the plant price
     */
    double price() override;
    
    /**
     * @brief Creates a clone of this plant
     * @return Pointer to a new BasicPlant object that is a copy of this one
     */
    Plant* clone() override;
};

#endif