#include "CactusCreator.h"
#include "Cactus.h"     
#include <iostream>

Plant* CactusCreator::factoryMethod() const 
{
    std::cout << "anOperation: CactusCreator has executed successfully." << std::endl;
    return new Cactus();
}
