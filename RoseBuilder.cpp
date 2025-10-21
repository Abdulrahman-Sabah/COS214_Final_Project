#include "RoseBuilder.h"

RoseBuilder::RoseBuilder()
{
    rose = nullptr;
}

RoseBuilder::~RoseBuilder()
{
    if (rose)
    {
        delete rose;
    }
    rose = nullptr;
}

void RoseBuilder::setName(std::string n)
{
    rose->setName(n);
}

void RoseBuilder::setCareType(std::string c)
{
    rose->setCareType(c);
}

void RoseBuilder::setSeason(std::string s)
{
    rose->setSeason(s);
}

void RoseBuilder::setLifeCycle(PlantLifeCycleState* state)
{
    rose->setLifeCycle(state);
}

void RoseBuilder::setCareStrategy(CareStrategy* strategy)
{
    rose->setCareStrategy(strategy);
}

Plant* RoseBuilder::getPlant()
{
    rose = new Rose();
    return rose;
}