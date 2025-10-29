#include "StaffFacade.h"
#include "Plant.h"
#include "CactusBuilder.h"
#include "LavenderBuilder.h"
#include "RoseBuilder.h"
#include "GreenhouseDirector.h"

#include <iostream>
#include <memory>

StaffFacade::StaffFacade(Inventory& inv) : inventory(inv) {}

void StaffFacade::addStock(const std::string& name)
{
    std::unique_ptr<Plant> plant;
     
    if (name == "Cactus") 
    {
        CactusBuilder builder;
        GreenhouseDirector director(&builder);
        director.construct();
        Plant* builtPlant = builder.getPlant();
        plant = std::unique_ptr<Plant>(builtPlant);
    } 
    else if (name == "Lavender") 
    {
        LavenderBuilder builder;
        GreenhouseDirector director(&builder);
        director.construct();
        Plant* builtPlant = builder.getPlant();
        plant = std::unique_ptr<Plant>(builtPlant);
    }
    else if (name == "Rose") 
    {
        RoseBuilder builder;
        GreenhouseDirector director(&builder);
        director.construct();
        Plant* builtPlant = builder.getPlant();
        plant = std::unique_ptr<Plant>(builtPlant);
    }
    else 
    {
        std::cout << "Unknown plant type: " << name << "\n";
        return;
    }

    std::cout << "Adding " << name << " to inventory.\n";
    inventory.addPlant(plant.release());
}