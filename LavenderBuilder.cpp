#include "LavenderBuilder.h"
//#include "Lavender.h"         // concrete Plant subtype
#include "Plant.h"
#include "PlantLifeCycleState.h"
#include "LavenderCreator.h"
#include <utility> // std::move

namespace
{
    // Lazily allocate the product the first time it’s needed
    inline void ensureAllocated(Plant*& p)
    {
        if (!p)
        {
            LavenderCreator creator;
            p = creator.factoryMethod(); // adjust ctor args if your Lavender needs them
        }
    }
}

LavenderBuilder::LavenderBuilder()
    : product(nullptr)
{
}

LavenderBuilder::~LavenderBuilder()
{
    delete product;    // safe if nullptr
    product = nullptr;
}

void LavenderBuilder::setName(std::string n)
{
    ensureAllocated(product);
    product->setName(std::move(n));
}

void LavenderBuilder::setCareType(std::string ct)
{
    ensureAllocated(product);
    product->setCareType(std::move(ct));
}

void LavenderBuilder::setSeason(std::string s)
{
    ensureAllocated(product);
    product->setSeason(std::move(s));
}

void LavenderBuilder::setLifeCycle(PlantLifeCycleState* state)
{
    ensureAllocated(product);
    product->setLifeCycle(state);
}

Plant* LavenderBuilder::getPlant()
{
    ensureAllocated(product);
    Plant* out = product;  // transfer ownership
    product = nullptr;     // builder relinquishes ownership
    return out;
}
