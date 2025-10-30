/**
* @file Landscaper.h
* @brief Concrete handler for plant care requests in Chain of Responsibility pattern
* @author COS214 Final Project Team
* @date 2025
*/

#ifndef LANDSCAPER_H
#define LANDSCAPER_H
#include "Handler.h"
#include "Plant.h"

/**
* @class Landscaper
* @brief Handles plant care requests in the chain of responsibility
* 
* The Landscaper class is a concrete handler that specifically processes
* plant care command types such as "AddWater" and "ApplyFertilizer".
* This handler typically appears at the end of the chain to handle
* basic plant maintenance operations.
*/
class Landscaper : public Handler{
public:
/**
    * @brief Handles plant care requests
    * @param r Pointer to the command to be processed
    * 
    * This method checks if the command type is "AddWater" or "ApplyFertilizer"
    * and processes it. If not, it passes the request to the next handler in the chain.
    */
    void handleRequest(Commands* r, Plant* plant) override;
};

#endif