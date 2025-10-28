/**
 * @file LavenderCreator.h
 * @brief Concrete factory for creating Lavender plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H

#include "Creator.h"

/**
 * @class LavenderCreator
 * @brief Concrete factory class for creating Lavender objects
 * 
 * This class implements the Factory Method pattern to create Lavender plants.
 * It extends the Creator base class to provide specific creation logic for lavender.
 */
class LavenderCreator : public Creator 
{
public:
    /**
     * @brief Default constructor
     */
    LavenderCreator();
    
    /**
     * @brief Factory method that creates a new Lavender plant
     * @return Pointer to a newly created Lavender plant
     */
    Plant* factoryMethod() const;
};

#endif
