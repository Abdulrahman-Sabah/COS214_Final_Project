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
