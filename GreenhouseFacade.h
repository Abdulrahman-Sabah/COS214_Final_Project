/**
 * @file GreenhouseFacade.h
 * @brief Facade pattern implementation for greenhouse operations
 * @author COS214 Students
 * @date 2024
 */

#ifndef GREENHOUSEFACADE_H
#define GREENHOUSEFACADE_H

#include <vector>
#include <string>
#include <iostream>
#include "Plant.h"
#include "SucculentBuilder.h"

/**
 * @class GreenhouseFacade
 * @brief Provides a simplified interface to complex greenhouse subsystems
 * 
 * This class implements the Facade pattern to provide a simple interface
 * for greenhouse operations, hiding the complexity of plant management,
 * inventory tracking, and builder patterns from the client.
 */
class GreenhouseFacade
{
    private:
        std::vector<Plant*> invent; ///< Inventory of plants
        SucculentBuilder* succulentBuilder; ///< Builder for succulent plants
    
    public:
        /**
         * @brief Default constructor that initializes the facade
         */
        GreenhouseFacade();
        
        /**
         * @brief Destructor that cleans up resources
         */
        ~GreenhouseFacade();
        
        /**
         * @brief Sells a plant by removing it from inventory
         * @param name Name of the plant to sell
         */
        void sellPlant(const std::string& name);
        
        /**
         * @brief Displays the current inventory of plants
         */
        void showInventory() const;
};

#endif