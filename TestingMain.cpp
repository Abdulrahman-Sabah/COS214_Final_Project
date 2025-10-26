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
#include "ApplyFertilizer.h"
#include "AddWater.h"


int main() 
{

    std::cout << "========== Factory Method Testing ==========\n" << std::endl;

    RoseCreator roseCreator;
    CactusCreator cactusCreator;
    LavenderCreator lavenderCreator;

    Plant* rose = roseCreator.factoryMethod();
    Plant* cactus = cactusCreator.factoryMethod();
    Plant* lavender = lavenderCreator.factoryMethod();

    delete rose;
    delete cactus;
    delete lavender;

    std::cout << "========== End of Factory Method Test ==========" << std::endl;

    std::cout << std::endl;

    std::cout << "========== Plant Class Testing ==========\n" << std::endl;

    Cactus cactusPlant;
    Lavender lavenderPlant;
    Rose rosePlant;

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

    std::cout << "========== Clone Tests ==========\n" << std::endl;

    Plant* clonedCactus = cactusPlant.clone();
    std::cout << "--- Cactus Clone ---" << std::endl;
    std::cout << "Cloned Name: " << clonedCactus->getName() << std::endl;
    std::cout << "Cloned Description: " << clonedCactus->description() << std::endl;
    std::cout << "Cloned Care Type: " << clonedCactus->getCareType() << std::endl;
    std::cout << "Cloned State: " << clonedCactus->getStateText() << std::endl;
    std::cout << "Cloned Season: " << clonedCactus->getSeason() << std::endl;
    std::cout << "Cloned Price: R" << clonedCactus->price() << "\n" << std::endl;

    Plant* clonedLavender = lavenderPlant.clone();
    std::cout << "--- Lavender Clone ---" << std::endl;
    std::cout << "Cloned Name: " << clonedLavender->getName() << std::endl;
    std::cout << "Cloned Description: " << clonedLavender->description() << std::endl;
    std::cout << "Cloned Care Type: " << clonedLavender->getCareType() << std::endl;
    std::cout << "Cloned State: " << clonedLavender->getStateText() << std::endl;
    std::cout << "Cloned Season: " << clonedLavender->getSeason() << std::endl;
    std::cout << "Cloned Price: R" << clonedLavender->price() << "\n" << std::endl;

    Plant* clonedRose = rosePlant.clone();
    std::cout << "--- Rose Clone ---" << std::endl;
    std::cout << "Cloned Name: " << clonedRose->getName() << std::endl;
    std::cout << "Cloned Description: " << clonedRose->description() << std::endl;
    std::cout << "Cloned Care Type: " << clonedRose->getCareType() << std::endl;
    std::cout << "Cloned State: " << clonedRose->getStateText() << std::endl;
    std::cout << "Cloned Season: " << clonedRose->getSeason() << std::endl;
    std::cout << "Cloned Price: R" << clonedRose->price() << "\n" << std::endl;

    delete clonedCactus;
    delete clonedLavender;
    delete clonedRose;

    std::cout << "========== End of Clone Test ==========" << std::endl;

    std::cout << std::endl;

    std::cout << "\n========== End of Plant Class Test ==========" << std::endl;

    std::cout << std::endl;

    std::cout << "========== Command Pattern Testing ==========\n" << std::endl;

    MoveToSales moveCommand("Plant-001");
    ScheduleDelivery scheduleCommand("Order-ABC123");
    ApplyFertilizer fertilizerCommand("Plant-002");
    AddWater waterCommand("Plant-003");

    std::cout << "Command Type: " << moveCommand.getType() << std::endl;
    std::cout << "Command Data: " << moveCommand.getData() << "\n" << std::endl;

    std::cout << "Command Type: " << scheduleCommand.getType() << std::endl;
    std::cout << "Command Data: " << scheduleCommand.getData() << "\n" << std::endl;

    std::cout << "Command Type: " << fertilizerCommand.getType() << std::endl;
    std::cout << "Command Data: " << fertilizerCommand.getData() << "\n" << std::endl;

    std::cout << "Command Type: " << waterCommand.getType() << std::endl;
    std::cout << "Command Data: " << waterCommand.getData() << "\n" << std::endl;

    std::cout << "========== End of Command Test ==========" << std::endl;
    std::cout << std::endl;


    return 0;
}
