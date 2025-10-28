#ifndef PLANT_BUILDER_H
#define PLANT_BUILDER_H

#include <string>
#include "Plant.h"
#include "PlantLifeCycleState.h"

class PlantBuilder
{
    public:
        virtual void setName(std::string n = "") = 0;
        virtual void setCareType(std::string c = "") = 0;
        virtual void setSeason(std::string s = "") = 0;
        virtual void setLifeCycle(PlantLifeCycleState* state) = 0;
        virtual Plant* getPlant() = 0;
        virtual ~PlantBuilder() = default;
};

#endif