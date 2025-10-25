#include <iostream>
#include "Cactus.h"
#include "CactusCare.h"
#include "Rose.h"
#include "RoseCare.h"
#include "Lavender.h"
#include "LavenderCare.h"

int main() 
{
    std::cout << "=========Strategy Testing=========" << std::endl;

    Cactus* cactus = new Cactus();
    Rose* rose = new Rose();
    Lavender* lavender = new Lavender();

    cactus->setCareStrategy(new CactusCare());
    rose->setCareStrategy(new RoseCare());
    lavender->setCareStrategy(new LavenderCare());

    cactus->setName("Golden Barrel Cactus");
    rose->setName("Red Rose");
    lavender->setName("English Lavender");

    std::cout << "Taking care of Cactus:" << std::endl;
    cactus->takeCare();

    std::cout << "Taking care of Rose:" << std::endl;
    rose->takeCare();

    std::cout << "Taking care of Lavender:" << std::endl;
    lavender->takeCare();

    delete cactus;
    delete rose;
    delete lavender;

    return 0;
}
