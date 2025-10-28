/**
 * @file AddWater.h
 * @brief Concrete command for watering plant operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef ADDWATER_H
#define ADDWATER_H

#include "Commands.h"

/**
 * @class AddWater
 * @brief Concrete command implementation for watering plants
 * 
 * This class implements the Command pattern for plant watering operations.
 * It encapsulates the plant identification and watering parameters needed
 * to execute the watering action.
 */
class AddWater : public Commands {
private:
    std::string plantId; /**< Unique identifier for the plant to be watered */

public:
    /**
     * @brief Constructs an AddWater command for the specified plant
     * @param id The unique plant identifier
     */
    AddWater(const std::string& id);
    
    /**
     * @brief Gets the command type
     * @return String "AddWater" identifying this command type
     */
    std::string getType() const override;
    
    /**
     * @brief Gets the plant ID associated with this watering command
     * @return String containing the plant ID
     */
    std::string getData() const override;
};

#endif
