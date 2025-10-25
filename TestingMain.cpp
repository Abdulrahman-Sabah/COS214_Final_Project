#include <iostream>

#include "Creator.h"
#include "RoseCreator.h"
#include "CactusCreator.h"
#include "LavenderCreator.h"
#include "Cactus.h"
#include "Lavender.h"
#include "Lavender.h"
#include "Rose.h"
#include "Plant.h"
#include "MoveToSales.h"
#include "Command.h"
#include "ScheduleDelivery.h"

int main() 
{

    std::cout << "========== Factory Method Testing ==========\n" << std::endl;

    RoseCreator roseCreator;
    CactusCreator cactusCreator;
    LavenderCreator lavenderCreator;

    Plant* rose = roseCreator.factoryMethod();
    Plant* cactus = cactusCreator.factoryMethod();
    Plant* lavender = lavenderCreator.factoryMethod();

    std::cout << "========== End of Factory Method Test ==========" << std::endl;


    std::cout << "========== Plant Class Testing ==========\n" << std::endl;

    Cactus cactusPlant;
    Lavender lavenderPlant;
    Rose rosePlant;

    std::cout << "Name: " << cactus << std::endl;
    std::cout << "Description: " << cactusPlant.description() << std::endl;
    std::cout << "Care Type: " << cactusPlant.getCareType() << std::endl;
    std::cout << "State: " << cactusPlant.getStateText() << std::endl;
    std::cout << "Season: " << cactusPlant.getSeason() << std::endl;
    std::cout << "Price: R" << cactusPlant.price() << "\n" << std::endl;

    std::cout << "Name: " << lavenderPlant.getName() << std::endl;
    std::cout << "Description: " << lavenderPlant.description() << std::endl;
    std::cout << "Care Type: " << lavenderPlant.getCareType() << std::endl;
    std::cout << "State: " << lavenderPlant.getStateText() << std::endl;
    std::cout << "Season: " << lavenderPlant.getSeason() << std::endl;
    std::cout << "Price: R" << lavenderPlant.price() << "\n" << std::endl;

    std::cout << "Name: " << rosePlant.getName() << std::endl;
    std::cout << "Description: " << rosePlant.description() << std::endl;
    std::cout << "Care Type: " << rosePlant.getCareType() << std::endl;
    std::cout << "State: " << rosePlant.getStateText() << std::endl;
    std::cout << "Season: " << rosePlant.getSeason() << std::endl;
    std::cout << "Price: R" << rosePlant.price() << "\n" << std::endl;

    Plant* clonedCactus = cactusPlant.clone();
    std::cout << "--- Clone Test ---" << std::endl;
    std::cout << "Cloned Name: " << clonedCactus->getName() << std::endl;
    std::cout << "Cloned Description: " << clonedCactus->description() << std::endl;
    std::cout << "Cloned Price: R" << clonedCactus->price() << std::endl;

    delete clonedCactus;

    std::cout << "\n========== End of Plant Class Test ==========" << std::endl;


    std::cout << "========== Command Pattern Testing ==========\n" << std::endl;

    MoveToSales moveCommand("Plant-001");
    ScheduleDelivery scheduleCommand("Order-ABC123");

    std::cout << "Command Type: " << moveCommand.getType() << std::endl;
    std::cout << "Command Data: " << moveCommand.getData() << "\n" << std::endl;

    std::cout << "Command Type: " << scheduleCommand.getType() << std::endl;
    std::cout << "Command Data: " << scheduleCommand.getData() << "\n" << std::endl;

    std::cout << "========== End of Command Test ==========" << std::endl;


    return 0;
}
