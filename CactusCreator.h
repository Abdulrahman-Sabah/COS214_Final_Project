/**
 * @file CactusCreator.h
 * @brief Concrete creator for cactus plants in Factory Method pattern
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef CACTUSCREATOR_H
#define CACTUSCREATOR_H

#include "Creator.h"

/**
 * @class CactusCreator
 * @brief Concrete factory for creating Cactus plant objects
 * 
 * CactusCreator implements the Factory Method pattern to create
 * Cactus plant instances. This allows the greenhouse system to
 * create cactus plants without knowing the specific construction details.
 */
class CactusCreator : public Creator 
{
public:
    /**
     * @brief Default constructor for CactusCreator
     */
    CactusCreator() = default;
    
    /**
     * @brief Factory method to create a new Cactus plant
     * @return Pointer to a newly created Cactus object
     * 
     * This method implements the abstract factory method to create
     * a specific Cactus plant with appropriate default settings.
     */
    Plant* factoryMethod() const override; 
};

#endif
