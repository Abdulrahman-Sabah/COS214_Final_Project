/**
 * @file Lavender.h
 * @brief Header file for the Lavender plant class
 * @author COS214 Students
 * @date 2024
 */

#ifndef LAVENDER_H
#define LAVENDER_H

#include "Plant.h"

/**
 * @class Lavender
 * @brief Represents a lavender plant with specific characteristics
 * 
 * This class extends the Plant base class to provide specific implementation
 * for lavender plants, including their unique care requirements, pricing,
 * and cloning behavior.
 */
class Lavender : public Plant
{
    public:
    /**
     * @brief Default constructor that creates a lavender with default properties
     */
    Lavender();
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    ~Lavender();
    
    /**
     * @brief Gets a description of the lavender
     * @return String description of the lavender plant
     */
    std::string description() override;
    
    /**
     * @brief Gets the price of the lavender
     * @return Price of the lavender as a double
     */
    double price() override;
    
    /**
     * @brief Creates a clone of this lavender
     * @return Pointer to a cloned Lavender object
     */
    Plant* clone() override;
};

#endif