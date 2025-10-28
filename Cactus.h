
/**
 * @file Cactus.h
 * @brief Concrete plant implementation for cactus plants
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef CACTUS_H
#define CACTUS_H

#include "Plant.h"

/**
 * @class Cactus
 * @brief Concrete implementation of Plant for cactus plants
 * 
 * The Cactus class represents a specific type of plant with low water requirements
 * and high heat tolerance. It implements the Prototype pattern allowing for
 * cloning of cactus instances. Cacti typically require minimal care and are
 * well-suited for dry climates.
 */
class Cactus : public Plant 
{
public:
    /**
     * @brief Default constructor for Cactus
     * 
     * Initializes a cactus with default properties:
     * - Name: "Cactus"
     * - Care Type: "Low" 
     * - Initial State: "Seedling"
     * - Optimal Season: "Summer"
     */
    Cactus();
    
    /**
     * @brief Destructor for Cactus
     */
    ~Cactus();
    
    /**
     * @brief Gets the description of the cactus
     * @return String describing the cactus characteristics
     */
    std::string description() override;
    
    /**
     * @brief Gets the price of the cactus
     * @return Double representing the price in the appropriate currency
     */
    double price() override;
    
    /**
     * @brief Creates a clone of this cactus instance
     * @return Pointer to a new Cactus object that is a copy of this instance
     * 
     * Implements the Prototype pattern for creating plant copies
     */
    Plant* clone() override;
};

#endif