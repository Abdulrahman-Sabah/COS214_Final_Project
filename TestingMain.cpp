#include <iostream>
#include "GreenhouseDirector.h"
#include "RoseBuilder.h"
#include "CactusBuilder.h"
#include "LavenderBuilder.h"
#include "Plant.h"

int main() 
{
    std::cout << "Testing the main" << std::endl;
    
    std::cout << "=== Bulder Design Pattern Test ===\n\n";

    // 1. Rose
    RoseBuilder roseBuilder;
    GreenhouseDirector roseDirector(&roseBuilder);
    roseDirector.construct();
    Plant* rose = roseBuilder.getPlant(); 

    if (rose)
    {
        std::cout << "Rose Built Successfully!" << std::endl;
        std::cout << "Name: "       << rose->getName() << std::endl
                  << "Care Type: "  << rose->getCareType() << std::endl
                  << "Season: "     << rose->getSeason() << std::endl;
    }
    else
    {
        std:: cout << "Rose Builder Returned Null Plant!" << std::endl;
    }

    // 2. Cactus
    CactusBuilder cactusBuilder;
    GreenhouseDirector cactusDirector(&cactusBuilder);
    cactusDirector.construct();
    Plant* cactus = cactusBuilder.getPlant();
    if (cactus)
    {
        std::cout << "\nCactus Built Successfully!" << std::endl;
        std::cout << "Name: "       << cactus->getName() << std::endl
                  << "Care Type: "  << cactus->getCareType() << std::endl
                  << "Season: "     << cactus->getSeason() << std::endl;
    }
    else
    {
        std:: cout << "Cactus Builder Returned Null Plant!" << std::endl;
    }
    
    // 3. Lavender
    LavenderBuilder lavenderBuilder;
    GreenhouseDirector lavenderDirector(&lavenderBuilder);
    lavenderDirector.construct();
    Plant* lavender = lavenderBuilder.getPlant();
    if (lavender)
    {
        std::cout << "\nLavender Built Successfully!" << std::endl;
        std::cout << "Name: "       << lavender->getName() << std::endl
                  << "Care Type: "  << lavender->getCareType() << std::endl
                  << "Season: "     << lavender->getSeason() << std::endl;
    }
    else
    {
        std:: cout << "Lavender Builder Returned Null Plant!" << std::endl;
    }

    return 0;
}
