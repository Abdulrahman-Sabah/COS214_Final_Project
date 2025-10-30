#include "RoseCreator.h"
#include "Rose.h"   
#include <iostream>

RoseCreator::RoseCreator() {}

Plant* RoseCreator::factoryMethod() const 
{
    std::cout << "anOperation: RoseCreator has executed successfully." << std::endl;
    return new Rose();
}
