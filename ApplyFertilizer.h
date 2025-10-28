/**
 * @file ApplyFertilizer.h
 * @brief Header file for the ApplyFertilizer class
 */

#ifndef APPLYFERTILIZER_H
#define APPLYFERTILIZER_H

#include "Commands.h"
#include <string>

/**
 * @class ApplyFertilizer
 * @brief Concrete command class for applying fertilizer to plants
 * 
 * This class implements the Commands interface to represent a fertilizer
 * application command in the Command pattern. It encapsulates the request
 * to apply fertilizer to a specific plant identified by its ID.
 */
class ApplyFertilizer : public Commands 
{
private:
    std::string plantId; ///< ID of the plant to apply fertilizer to

public:
    /**
     * @brief Constructor for ApplyFertilizer command
     * @param id The ID of the plant to apply fertilizer to
     */
    ApplyFertilizer(const std::string& id);
    
    /**
     * @brief Get the type of this command
     * @return String indicating this is an "ApplyFertilizer" command
     */
    std::string getType() const override;
    
    /**
     * @brief Get the data associated with this command
     * @return String containing the plant ID for fertilizer application
     */
    std::string getData() const override;
};

#endif
