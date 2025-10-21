#include "GreenhouseFacade.h"

GreenhouseFacade::GreenhouseFacade()
{
    succulentBuilder = new SucculentBuilder();
}

GreenhouseFacade::~GreenhouseFacade()
{
    delete succulentBuilder;

    for (Plant* p : invent) {
        delete p;
    }
}

void GreenhouseFacade::sellPlant(const std::string& name)
{
    for (auto it = invent.begin(); it != invent.end(); ++it) {
        if ((*it)->getName() == name) {
            std::cout << "Selling plant: " << name << std::endl;
            delete *it;
            invent.erase(it);
            return;
        }
    }

    std::cout << "Plant not found/unavailable." << std::endl;
}

void GreenhouseFacade::showInventory() const
{
    std::cout << "==========================" << std::endl;
    std::cout << "Current Inventory:" << std::endl;
    std::cout << "==========================" << std::endl;
    for (const Plant* p : invent) {
        std::cout << p->getName() << std::endl;
    }
}