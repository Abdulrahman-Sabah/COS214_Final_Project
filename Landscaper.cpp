/**
 * @file Landscaper.cpp
 * @brief Implementation of Landscaper handler for plant care operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "Landscaper.h"
#include "Commands.h"
#include <iostream>
void Landscaper::handleRequest(Commands* r){
    if (r && (r->getType() == "AddWater" || r->getType() == "ApplyFertilizer")) 
    {
        std::cout << "Landscaper is handling plant care: " << r->getType() << std::endl;
    }
    else{
        // Pass to next handler in chain using protected method
        passToSuccessor(r);
    }
    
}   
