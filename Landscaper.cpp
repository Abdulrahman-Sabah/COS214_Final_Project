/**
 * @file Landscaper.cpp
 * @brief Implementation of Landscaper handler for plant care operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "Landscaper.h"
#include "Commands.h"
#include <iostream>

void Landscaper::handleRequest(Commands* r,Plant* plant)
{
    std::cout << "Working";
    if (r && (r->name() == "SeedlingState" || r->name() == "GrowingState" || r->name() == "DormantState" || r->name() == "MatureState" || r->name() == "SellingState" || r->name() == "DeadState")) 
    {
        std::cout << "Landscaper is handling plant care: " << r->name() << std::endl;
        r->execute(plant);
        delete r;
    }
    else{
        // Pass to next handler in chain using protected method
        passToSuccessor(r,plant);
        
    }
    
}   
