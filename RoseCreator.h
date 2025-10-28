/**
 * @file RoseCreator.h
 * @brief Concrete factory for creating Rose plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef ROSECREATOR_H
#define ROSECREATOR_H

#include "Creator.h"

/**
 * @class RoseCreator
 * @brief Concrete factory class for creating Rose objects
 * 
 * This class implements the Factory Method pattern to create Rose plants.
 * It extends the Creator base class to provide specific creation logic for roses.
 */
class RoseCreator : public Creator {
public:
    /**
     * @brief Default constructor
     */
    RoseCreator();
    
    /**
     * @brief Factory method that creates a new Rose plant
     * @return Pointer to a newly created Rose plant
     */
    Plant* factoryMethod() const override;
};

#endif
