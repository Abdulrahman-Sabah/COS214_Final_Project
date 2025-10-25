#include <iostream>

#include "Creator.h"
#include "RoseCreator.h"
#include "CactusCreator.h"
#include "LavenderCreator.h"

int main() 
{
    std::cout << "---------------------------Factory Testing---------------------------" << std::endl;

    std::cout << "========== Factory Method Testing ==========\n" << std::endl;

    RoseCreator roseCreator;
    CactusCreator cactusCreator;
    LavenderCreator lavenderCreator;

    Plant* rose = roseCreator.factoryMethod();
    Plant* cactus = cactusCreator.factoryMethod();
    Plant* lavender = lavenderCreator.factoryMethod();

    return 0;
}
