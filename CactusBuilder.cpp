//#include "SucculentBuilder.h"

// SucculentBuilder::SucculentBuilder()
// {
//     succulent = NULL;
// }

// SucculentBuilder::~SucculentBuilder()
// {
//     if (succulent)
//     {
//         delete succulent;
//     }
//     succulent = NULL;
// }

// void SucculentBuilder::setName( std::string& name)
// {
//     plant->setName(name);
// }

// void SucculentBuilder::setCareType(const std::string& careType)
// {
//     plant->setCareType(careType);
// }

// void SucculentBuilder::setSeason(const std::string& season)
// {
//     plant->setSeason(season);
// }

// void SucculentBuilder::setLifeCycle(PlantLifeCycleState* state)
// {
//     plant->setLifeCycle(state);
// }

// void SucculentBuilder::setCareStrategy(CareStrategy* strategy)
// {
//     plant->setCareStrategy(strategy);
// }

// Plant SucculentBuilder::getPlant()
// {
//     Plant* succulent = new Succulent();
//     return succulent;
// }


/**
 * @file CactusBuilder.cpp
 * @brief Implementation of the CactusBuilder class
 * @author COS214 Students
 * @date 2024
 */

#include "CactusBuilder.h"
// #include "Cactus.h"              // concrete Plant subtype
#include "Plant.h"
#include "PlantLifeCycleState.h"
#include "CactusCreator.h"
#include <utility> // std::move

namespace
{
    // Lazily allocate the product the first time it’s needed
    inline void ensureAllocated(Plant*& p)
    {
        if (!p)
        {
            CactusCreator creator;
            p = creator.factoryMethod(); // adjust ctor args if your Cactus needs them
        }
    }
}

CactusBuilder::CactusBuilder()
    : product(nullptr)
{
}

CactusBuilder::~CactusBuilder()
{
    delete product;    // safe if nullptr
    product = nullptr;
}

void CactusBuilder::setName(std::string n)
{
    ensureAllocated(product);
    product->setName(std::move(n));
}

void CactusBuilder::setCareType(std::string ct)
{
    ensureAllocated(product);
    product->setCareType(std::move(ct));
}

void CactusBuilder::setSeason(std::string s)
{
    ensureAllocated(product);
    product->setSeason(std::move(s));
}

void CactusBuilder::setLifeCycle(PlantLifeCycleState* state)
{
    ensureAllocated(product);
    product->setLifeCycle(state);
}

Plant* CactusBuilder::getPlant()
{
    ensureAllocated(product);
    Plant* out = product;  // transfer ownership
    product = nullptr;     // builder relinquishes ownership
    return out;
}
