#include "Landscaper.h"
#include <iostream>
void Landscaper::handleRequest(Command* r){
    if (r && (r->getType() == "WaterPlants" || r->getType() == "FertilizePlants")) //Need to create more commands
    {
        std::cout << "Landscaper is handling plant care: " << r->getType() << std::endl;
    }
    else{
        // Pass to next handler in chain using protected method
        passToSuccessor(r);
    }
    
}