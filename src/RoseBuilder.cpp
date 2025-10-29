#include "RoseBuilder.h"
#include "Rose.h"             // concrete Plant subtype
#include "Plant.h"
#include "PlantLifeCycleState.h"
#include "RoseCreator.h"
#include <utility> // std::move

namespace
{
    // Lazily allocate the product the first time it’s needed
    inline void ensureAllocated(Plant*& p)
    {
        if (!p)
        {
            RoseCreator creator;
            p = creator.factoryMethod(); // adjust ctor args if your Rose needs them
            p->setName("Rose");
        }
    }
}

RoseBuilder::RoseBuilder()
    : product(nullptr)
{
}

RoseBuilder::~RoseBuilder()
{
    delete product;    // safe if nullptr
    product = nullptr;
}

void RoseBuilder::setName(std::string n)
{
    ensureAllocated(product);
    product->setName(std::move(n));
}

void RoseBuilder::setCareType(std::string ct)
{
    ensureAllocated(product);
    product->setCareType(std::move(ct));
}

void RoseBuilder::setSeason(std::string s)
{
    ensureAllocated(product);
    product->setSeason(std::move(s));
}

void RoseBuilder::setLifeCycle(PlantLifeCycleState* state)
{
    ensureAllocated(product);
    product->setLifeCycle(state);
}


Plant* RoseBuilder::getPlant()
{
    ensureAllocated(product);
    Plant* out = product;  // transfer ownership
    product = nullptr;     // builder relinquishes ownership
    return out;
}