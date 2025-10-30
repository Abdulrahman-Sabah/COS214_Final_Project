/**
 * @file GreenhouseDirector.cpp
 * @brief Implementation of the GreenhouseDirector class
 * @author COS214 Students
 * @date 2024
 */

#include "GreenhouseDirector.h"

GreenhouseDirector::GreenhouseDirector(PlantBuilder* b) : builder(b) {}

void GreenhouseDirector::construct()
{
    builder->setName();
    builder->setCareType("Low Watering");
    builder->setSeason("Summer");
    //builder->setLifeCycle(new SeedingState());   
}