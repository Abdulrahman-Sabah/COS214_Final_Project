#include "SucculentBuilder.h"

SucculentBuilder::SucculentBuilder()
{
    succulent = NULL;
}

~SucculentBuilder::~SucculentBuilder()
{
    if (succulent)
    {
        delete succulent;
    }
    succulent = NULL;
}

void SucculentBuilder::setName(const std::string& name)
{
    plant->setName(name);
}

void SucculentBuilder::setCareType(const std::string& careType)
{
    plant->setCareType(careType);
}

void SucculentBuilder::setSeason(const std::string& season)
{
    plant->setSeason(season);
}

void SucculentBuilder::setLifeCycle(PlantLifeCycleState* state)
{
    plant->setLifeCycle(state);
}

void SucculentBuilder::setCareStrategy(CareStrategy* strategy)
{
    plant->setCareStrategy(strategy);
}

Plant SucculentBuilder::getPlant()
{
    Plant* succulent = new Succulent();
    return succulent;
}