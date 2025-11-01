#include <iostream>
#include <string>
#include <limits>
#include "FrontDesk.h"
#include "StoreCustomer.h"
#include "DeliveryStaff.h"
#include "Inventory.h"
#include "InventoryIterator.h"
#include "Rose.h"
#include "Cactus.h"
#include "Lavender.h"
#include "CareScheduleObserver.h"
#include "Landscaper.h"
#include "GreenhouseManager.h"
#include "SeedlingState.h"
#include "GrowingState.h"
#include "DormantState.h"
#include "MatureState.h"
#include "SellingState.h"
#include "DeadState.h"
#include "RoseCare.h"
#include "CactusCare.h"
#include "LavenderCare.h"

static void clearStdin()
{
    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::string lower(std::string s)
{
    for (char &c : s)
    {
        c = (char)std::tolower(c);
    }
    return s;
}

static Plant *makePlantByType(const std::string &type)
{
    std::string t = lower(type);
    if (t == "rose")
    {
        return new Rose();
    }
    if (t == "cactus")
    {
        return new Cactus();
    }
    if (t == "lavender")
    {
        return new Lavender();
    }
    else
    {
        return nullptr;
    }
}

static PlantLifeCycleState *makeState(const std::string &s)
{
    std::string t = lower(s);
    if (t == "seedling")
    {
        return new SeedlingState();
    }

    if (t == "growing")
    {
        return new GrowingState();
    }

    if (t == "dormant")
    {
        return new DormantState();
    }
    if (t == "mature")
    {
        return new MatureState();
    }
    if (t == "selling")
    {
        return new SellingState();
    }
    if (t == "dead")
    {
        return new DeadState();
    }
    else
    {
        return nullptr;
    }
}
static CareStrategy *makeStrategy(const std::string &s)
{
    std::string t = lower(s);
    if (t == "rose")
    {
        return new RoseCare();
    }
    if (t == "cactus")
    {
        return new CactusCare();
    }
    if (t == "lavender")
    {
        return new LavenderCare();
    }
    else
    {
        return nullptr;
    }
}

static void printInventory(Inventory *inv)
{
    std::cout << "\n--- Inventory (" << inv->getSize() << ") ---\n";
    PlantIterator *it = inv->createIterator();
    int i = 1;

    for (it->first(); !it->isDone(); it->next())
    {
        Plant *p = it->current();
        if (!p)
            continue;

        auto *st = p->getLifeCycle();
        auto *cs = p->getCareStrategy();

        std::string strategyName = "NoStrategy";
        if (dynamic_cast<RoseCare *>(cs))
        {
            strategyName = "RoseCare";
        }
        else if (dynamic_cast<CactusCare *>(cs))
        {
            strategyName = "CactusCare";
        }
        else if (dynamic_cast<LavenderCare *>(cs))
        {
            strategyName = "LavenderCare";
        }

        std::cout << i++ << ". " << p->getName()
                  << " | State: " << (st ? st->name() : "Unknown")
                  << " | Care: " << strategyName
                  << "\n";
    }
    delete it;

    if (i == 1)
        std::cout << "(empty)\n";
}

static Plant *findByName(Inventory *inv, const std::string &name)
{
    PlantIterator *it = inv->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
        Plant *p = it->current();
        if (p && p->getName() == name)
        {
            delete it;
            return p;
        }
    }
    delete it;
    return nullptr;
}

static void applyStateAndNotify(Plant *plantchecking, PlantLifeCycleState *typeofcare, CareSchedulerObserver &Theobserver)
{
    Theobserver.onLifeCycleChanged(plantchecking, typeofcare);
}
static void applyStrategyAndNotify(Plant *plantchecking, CareStrategy *typeofcare, CareSchedulerObserver &Theobserver)
{
    Theobserver.onCareStrategyChanged(plantchecking, typeofcare);
}

int main()
{

    FrontDesk mediator;
    StoreCustomer customer;

    Inventory *greenhouse = new Inventory();
    greenhouse->addPlant(new Rose());
    greenhouse->addPlant(new Cactus());

    DeliveryStaff *staff = new DeliveryStaff(greenhouse);
    staff->setMediator(&mediator);

    customer.setMediator(&mediator);
    mediator.setCustomer(&customer);
    mediator.setDeliveryStaff(staff);

    auto *landscaper = new Landscaper();
    auto *manager = new GreenhouseManager();
    landscaper->setSuccessor(manager);
    manager->setSuccessor(landscaper);
    CareSchedulerObserver observer;
    observer.setHandler(landscaper);

    while (true)
    {
        std::cout << "\n====================================\n";
        std::cout << "  Plant Nursery Demo (Mediator + Observer)\n";
        std::cout << "====================================\n";
        std::cout << "1) List inventory\n";
        std::cout << "2) Add plant\n";
        std::cout << "3) Customer request (by name)\n";
        std::cout << "4) Remove plant(only staff) (by name)\n";
        std::cout << "5) Observer(only staff) (observer -> chain)\n";
        std::cout << "6) Exit\n";
        std::cout << "Choose: ";
        int choice = 0;
        if (!(std::cin >> choice))
        {
            clearStdin();
            continue;
        }
        clearStdin();

        if (choice == 1)
        {
            printInventory(greenhouse);
        }
        else if (choice == 2)
        {
            std::string type;
            std::cout << "Enter type (Rose/Cactus/Lavender): ";
            std::getline(std::cin, type);

            Plant *p = makePlantByType(type);
            if (!p)
            {
                std::cout << "Unknown type.\n";
                continue;
            }

            greenhouse->addPlant(p);
            std::cout << "Added: " << p->getName() << "\n";
        }
        else if (choice == 3)
        {
            std::string name;
            std::cout << "Enter plant name to request (see 'List inventory' for exact names): ";
            std::getline(std::cin, name);

            Plant *inInv = findByName(greenhouse, name);
            if (inInv)
            {
                std::cout << "(Found in inventory) ";
                customer.requestPlant(inInv);
            }
            else
            {
                std::string type;
                std::cout << "Not in inventory. Enter type to request anyway (Rose/Cactus/Lavender): ";
                std::getline(std::cin, type);
                Plant *temp = makePlantByType(type);
                if (!temp)
                {
                    std::cout << "Unknown type.\n";
                    continue;
                }

                std::cout << "(Not in inventory) ";
                customer.requestPlant(temp);
                delete temp;
            }
        }
        else if (choice == 4)
        {
            std::string pass;
            std::cout << "\n--- Secure Access Required ---\n";
            std::cout << "Enter password: ";
            std::getline(std::cin, pass);

            if (pass != "1234")
            {
                std::cout << "Wrong password. Access denied.\n";
                continue;
            }

            std::cout << "Access granted.\n";

            std::string name;
            std::cout << "Enter plant name to remove: ";
            std::getline(std::cin, name);

            bool ok = greenhouse->removePlantByName(name);
            std::cout << (ok ? "Removed.\n" : "No plant with that name.\n");
        }

        else if (choice == 5)
        {
            std::string pass;
            std::cout << "\n--- Observer Secure Access ---\n";
            std::cout << "Enter password: ";
            std::getline(std::cin, pass);

            if (pass != "1234")
            {
                std::cout << " Wrong password. Access denied.\n";
                continue;
            }

            std::cout << " Access granted.\n";

            int obsChoice;
            std::cout << "\nObserver Options:\n";
            std::cout << "1) Edit plant lifecycle state\n";
            std::cout << "2) Edit plant care strategy\n";
            std::cout << "3) Back to menu\n";
            std::cout << "Choose option: ";

            if (!(std::cin >> obsChoice))
            {
                clearStdin();
                continue;
            }
            clearStdin();

            if (obsChoice == 3)
            {
                std::cout << "Returning...\n";
                continue;
            }

            std::string name;
            std::cout << "Plant name: ";
            std::getline(std::cin, name);

            Plant *p = findByName(greenhouse, name);
            if (!p)
            {
                std::cout << " Plant not found.\n";
                continue;
            }

            if (obsChoice == 1)
            {
                std::string st;
                std::cout << "State (seedling/growing/dormant/mature/selling/dead): ";
                std::getline(std::cin, st);

                PlantLifeCycleState *ns = makeState(st);
                if (!ns)
                {
                    std::cout << " Invalid state.\n";
                    continue;
                }

                applyStateAndNotify(p, ns, observer);
                std::cout << " State updated → " << p->getLifeCycle()->name() << "\n";
            }
            else if (obsChoice == 2)
            {
                std::string st;
                std::cout << "Strategy (rose/cactus/lavender): ";
                std::getline(std::cin, st);

                CareStrategy *ns = makeStrategy(st);
                if (!ns)
                {
                    std::cout << " Invalid strategy.\n";
                    continue;
                }

                applyStrategyAndNotify(p, ns, observer);
                std::cout << " Strategy updated!\n";
            }
            else
            {
                std::cout << " Invalid selection.\n";
            }
        }

        else if (choice == 6)
        {
            std::cout << "Bye!\n";
            break;
        }
        else
        {
            std::cout << "Invalid option.\n";
        }
    }

    delete staff;
    delete greenhouse;
    delete manager;
    delete landscaper;

    return 0;
}
