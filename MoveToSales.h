/**
 * @file MoveToSales.h
 * @brief Header file for the MoveToSales class
 */

#ifndef MOVETOSALES_H
#define MOVETOSALES_H

#include "Commands.h"
#include <string>

/**
 * @class MoveToSales
 * @brief Concrete command class for moving plants to sales area
 * 
 * This class implements the Commands interface to represent a move-to-sales
 * command in the Command pattern. It encapsulates the request to move a
 * specific plant to the sales area, typically handled by the GreenhouseManager.
 */
class MoveToSales : public Commands {
private:
    std::string plantId; ///< ID of the plant to move to sales

public:
    /**
     * @brief Constructor for MoveToSales command
     * @param id The ID of the plant to move to sales area
     */
    explicit MoveToSales(const std::string& id);
    
    /**
     * @brief Get the type of this command
     * @return String indicating this is a "MoveToSales" command
     */
    std::string getType() const override;
    
    /**
     * @brief Get the data associated with this command
     * @return String containing the plant ID for sales movement
     */
    std::string getData() const override;
};

#endif 
