#ifndef DEMOMAIN_CPP_DOC
/**
 * @file DemoMain.cpp
 * @brief Demo runner showing example usage of the greenhouse classes.
 * @author Git it done group members
 * @date 10-2025
 */
#define DEMOMAIN_CPP_DOC
#endif

#include "Cactus.h"
#include "CactusCare.h"
#include "CactusCreator.h"
#include "CardDecorator.h"
#include "CareScheduleObserver.h"
#include "Creator.h"
#include "DeadState.h"
#include "DeliveryStaff.h"
#include "DormantState.h"
#include "FrontDesk.h"
#include "GreenhouseManager.h"
#include "GrowingState.h"
#include "Inventory.h"
#include "InventoryIterator.h"
#include "Landscaper.h"
#include "Lavender.h"
#include "LavenderCare.h"
#include "LavenderCreator.h"
#include "MatureState.h"
#include "PlantDecorations.h"
#include "PotDecorator.h"
#include "Rose.h"
#include "RoseCare.h"
#include "RoseCreator.h"
#include "SeedlingState.h"
#include "SellingState.h"
#include "StoreCustomer.h"
#include "WrapDecorator.h"
#include <iostream>
#include <limits>
#include <string>

static void clearStdin() {
  std::cin.clear();

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::string lower(std::string s) {
  for (char &c : s) {
    c = (char)std::tolower(c);
  }
  return s;
}

static Plant *makePlantByType(const std::string &type) {
  std::string t = lower(type);
  if (t == "rose") {
    return new Rose();
  }
  if (t == "cactus") {
    return new Cactus();
  }
  if (t == "lavender") {
    return new Lavender();
  } else {
    return nullptr;
  }
}

static Creator *makeCreatorByType(const std::string &type) {
  std::string t = lower(type);
  if (t == "rose")
    return new RoseCreator();
  if (t == "cactus")
    return new CactusCreator();
  if (t == "lavender")
    return new LavenderCreator();
  return nullptr;
}

static PlantLifeCycleState *makeState(const std::string &s) {
  std::string t = lower(s);
  if (t == "seedling") {
    return new SeedlingState();
  }

  if (t == "growing") {
    return new GrowingState();
  }

  if (t == "dormant") {
    return new DormantState();
  }
  if (t == "mature") {
    return new MatureState();
  }
  if (t == "selling") {
    return new SellingState();
  }
  if (t == "dead") {
    return new DeadState();
  } else {
    return nullptr;
  }
}
static CareStrategy *makeStrategy(const std::string &s) {
  std::string t = lower(s);
  if (t == "rose") {
    return new RoseCare();
  }
  if (t == "cactus") {
    return new CactusCare();
  }
  if (t == "lavender") {
    return new LavenderCare();
  } else {
    return nullptr;
  }
}

static void printInventory(Inventory *inv) {
  std::cout << "\n--- Inventory (" << inv->getSize() << ") ---\n";
  PlantIterator *it = inv->createIterator();
  int i = 1;

  for (it->first(); !it->isDone(); it->next()) {
    Plant *p = it->current();
    if (!p) {
      continue;
    }
    auto *st = p->getLifeCycle();
    auto *cs = p->getCareStrategy();

    std::string strategyName = "NoStrategy";
    if (dynamic_cast<RoseCare *>(cs)) {
      strategyName = "RoseCare";
    } else if (dynamic_cast<CactusCare *>(cs)) {
      strategyName = "CactusCare";
    } else if (dynamic_cast<LavenderCare *>(cs)) {
      strategyName = "LavenderCare";
    }

    bool growing = (st && dynamic_cast<GrowingState *>(st) != nullptr);
    bool attention = (st ? st->getAttention() : false);
    bool dead = (st ? st->getDead() : false);

    std::cout << i++ << ". " << p->getName() << " | Price: $" << p->price()
              << " | State: " << (st ? st->name() : "Unknown")
              << " | Care: " << strategyName
              << " | Growing: " << (growing ? "Yes" : "No")
              << " | Attention: " << (attention ? "Yes" : "No")
              << " | Dead: " << (dead ? "Yes" : "No") << "\n\n";
  }
  delete it;
  if (i == 1)
    std::cout << "(empty)\n";
}

static void applyStateAndNotify(Plant *plantchecking,
                                PlantLifeCycleState *typeofcare,
                                CareSchedulerObserver &Theobserver) {
  Theobserver.onLifeCycleChanged(plantchecking, typeofcare);
}
static void applyStrategyAndNotify(Plant *plantchecking,
                                   CareStrategy *typeofcare,
                                   CareSchedulerObserver &Theobserver) {
  Theobserver.onCareStrategyChanged(plantchecking, typeofcare);
}

static void printSellingOnly(Inventory *inv) {
  std::cout << "\n--- Inventory (" << inv->getSize() << ") ---\n";
  PlantIterator *it = inv->createIterator();
  int i = 1;

  for (it->first(); !it->isDone(); it->next()) {
    Plant *p = it->current();
    if (!p) {
      continue;
    }

    PlantLifeCycleState *st = p->getLifeCycle();
    if (st == NULL || dynamic_cast<SellingState *>(st) == NULL) {
      i++;
      continue;
    }
    auto *cs = p->getCareStrategy();

    std::string strategyName = "NoStrategy";
    if (dynamic_cast<RoseCare *>(cs)) {
      strategyName = "RoseCare";
    } else if (dynamic_cast<CactusCare *>(cs)) {
      strategyName = "CactusCare";
    } else if (dynamic_cast<LavenderCare *>(cs)) {
      strategyName = "LavenderCare";
    }

    bool growing = (st && dynamic_cast<GrowingState *>(st) != nullptr);
    bool attention = (st ? st->getAttention() : false);
    bool dead = (st ? st->getDead() : false);

    std::cout << i++ << ". " << p->getName() << " | Price: $" << p->price()
              << " | State: " << (st ? st->name() : "Unknown")
              << " | Care: " << strategyName
              << " | Growing: " << (growing ? "Yes" : "No")
              << " | Attention: " << (attention ? "Yes" : "No")
              << " | Dead: " << (dead ? "Yes" : "No") << "\n\n";
  }
  delete it;
  if (i == 1)
    std::cout << "(empty)\n";
}

int main() {

  FrontDesk mediator;
  StoreCustomer customer;

  Inventory *greenhouse = new Inventory();
  greenhouse->addPlant(new Rose());
  greenhouse->addPlant(new Cactus());

  Plant *r1 = new Rose();
  r1->setLifeCycle(new SellingState());
  greenhouse->addPlant(r1);

  Plant *c1 = new Cactus();
  c1->setLifeCycle(new GrowingState());
  greenhouse->addPlant(c1);

  Plant *l1 = new Lavender();
  l1->setLifeCycle(new SeedlingState());
  greenhouse->addPlant(l1);

  Plant *r2 = new Rose();
  r2->setLifeCycle(new DormantState());
  greenhouse->addPlant(r2);

  Plant *c2 = new Cactus();
  c2->setLifeCycle(new SellingState());
  greenhouse->addPlant(c2);

  Plant *l2 = new Lavender();
l2->setLifeCycle(new SellingState());
greenhouse->addPlant(l2);

Plant *r3 = new Rose();
r3->setLifeCycle(new SellingState());
greenhouse->addPlant(r3);


Plant *c3 = new Cactus();
c3->setLifeCycle(new SellingState());
greenhouse->addPlant(c3);


Plant *l3 = new Lavender();
l3->setLifeCycle(new SellingState());
greenhouse->addPlant(l3);

Plant *r4 = new Rose();
r4->setLifeCycle(new SellingState());
greenhouse->addPlant(r4);

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

  while (true) {
    std::cout << "\n====================================\n";
    std::cout << "  Plant Nursery Demo (Mediator + Observer)\n";
    std::cout << "====================================\n";
    std::cout << "1) List inventory\n";
    std::cout << "2) Add plant\n";
    std::cout << "3) Customer request (by name)\n";
    std::cout << "4) Remove plant (Only staff can remove dead plants)\n";
    std::cout << "5) Observer(only staff) (observer -> chain)\n";
    std::cout << "6) Set Dead / Attention for a plant (staff only)\n";
    std::cout << "7) Customer browsing, plant information & recommendations\n";
    std::cout << "8) Exit\n";
    std::cout << "Choose: ";
    int choice = 0;
    if (!(std::cin >> choice)) {
      clearStdin();
      continue;
    }
    clearStdin();

    if (choice == 1) {
      if (choice == 1) {
        std::string roleInput;
        std::cout << "\nAre you a Customer (C) or Staff (S)? ";
        std::getline(std::cin, roleInput);

        std::string role = lower(roleInput);
        if (role == "s" || role == "staff") {
          std::string passforthestaff;
          std::cout << "\n--- Staff Access ---\n";
          std::cout << "Enter password: ";
          std::getline(std::cin, passforthestaff);

          if (passforthestaff == "1234") {
            std::cout << "Access granted. Showing full inventory.\n";
            printInventory(greenhouse);
          } else {
            std::cout << "Wrong password. Showing selling items only.\n";
            printSellingOnly(greenhouse);
          }
        } else {
          std::cout << "Customer view. Showing selling items only.\n";
          printSellingOnly(greenhouse);
        }
      }
    } else if (choice == 2) {
      string passwordforcustomers;
      cout << "\n--- Observer Secure Access ---\n";
      cout << "Enter password in order to remove: ";
      getline(std::cin, passwordforcustomers);

      if (passwordforcustomers != "1234") {
        std::cout
            << " Wrong password. Access denied. Sorry, you are not a staff.\n";
        continue;
      }

      string typeThatWantstobeDeleted;
      cout << "Enter type (Rose/Cactus/Lavender): ";
      getline(std::cin, typeThatWantstobeDeleted);

      Plant *wegettingtheplant = makePlantByType(typeThatWantstobeDeleted);
      if (!wegettingtheplant) {
        std::cout << "Unknown type.\n";
        continue;
      } else {
        greenhouse->addPlant(wegettingtheplant);
        std::cout << "Added: " << wegettingtheplant->getName() << "\n";
        Creator *testing = makeCreatorByType(typeThatWantstobeDeleted);
        testing->factoryMethod();
      }
    } else if (choice == 3)

    {
      printSellingOnly(greenhouse);

      int takingtheindex;
      std::cout << "Choose plant number to request (or 0 to cancel): ";
      if (!(std::cin >> takingtheindex)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        continue;
      }
      clearStdin();

      if (takingtheindex == 0) {
        std::cout << "Request cancelled.\n";
        continue;
      }

      int postioninginArray = takingtheindex - 1;
      if (postioninginArray < 0 || postioninginArray >= greenhouse->getSize()) {
        std::cout << "Invalid index.\n";
        continue;
      }

      Plant *planttoremoveinpointer = greenhouse->at(postioninginArray);
      if (planttoremoveinpointer == NULL) {
        std::cout << "Error: Plant pointer is null.\n";
        continue;
      }

      PlantLifeCycleState *st = planttoremoveinpointer->getLifeCycle();
      if (st == NULL) {
        std::cout << "Error: Plant state is null.\n";
        continue;
      }

      SellingState *sellingPtr = dynamic_cast<SellingState *>(st);
      if (sellingPtr == NULL) {
        std::cout
            << "Only plants in SELLING state can be requested by customers.\n";
        continue;
      }

      std::cout << "(Found in inventory) ";
      std::cout << "Choose a decoration:\n";
      std::cout << "1) Gift Wrap (R60)\n";
      std::cout << "2) Pot (R70)\n";
      std::cout << "3) Card (R80)\n";
      std::cout << "4) None\n";
      std::cout << "Enter option: ";

      int decorChoice;
      if (!(std::cin >> decorChoice)) {
        clearStdin();
        std::cout << "Invalid.\n";
        continue;
      }
      clearStdin();

      PlantDecorations *newDecorations = nullptr;

      if (decorChoice == 1)
      {
        newDecorations = new WrapDecorator(planttoremoveinpointer, "Gift wrap decoration", 60);
      }
      else if (decorChoice == 2)
      {
        newDecorations = new PotDecorator(planttoremoveinpointer, "Pot decoration", 70);
      }
      else if (decorChoice == 3)
      {
        newDecorations = new CardDecorator(planttoremoveinpointer, "Card decoration", 80);
      }
      else
      {
        std::cout << "No decoration selected.\n";
      }

      customer.requestPlant(planttoremoveinpointer);

      planttoremoveinpointer->setLifeCycle(new DeadState());
      std::cout << "Final product: " << newDecorations->description() << "\n";
      

      std::string receiptInput;
      std::cout << "Would you like a receipt? (y/n): ";
      std::getline(std::cin, receiptInput);

      if (lower(receiptInput) == "y" || lower(receiptInput) == "yes")
      {
        std::cout << "\n===== RECEIPT =====\n";
if (newDecorations != nullptr)
{
    double basePrice = planttoremoveinpointer->price();
    double decorationsCost = newDecorations->price();

    std::cout << "Item: " << planttoremoveinpointer->getName() << "\n";
    std::cout << "Base Price: R" << basePrice << "\n";
    std::cout << "Decoration: " << newDecorations->description()
              << " (+R" << decorationsCost << ")\n";
    std::cout << "Total: R" << (newDecorations->price() + basePrice) << "\n";
}
else
{
    std::cout << "Item: " << planttoremoveinpointer->getName() << "\n";
    std::cout << "Price: R" << planttoremoveinpointer->price() << "\n";
    std::cout << "No decorations added" << std::endl;
}
std::cout << "===================\n";
      }

      greenhouse->removePlant(planttoremoveinpointer);
    }

    else if (choice == 4) {
      string passforthestaff;
      cout << "\n--- Secure Access Required ---\n";
      cout << "Enter password: ";
      getline(std::cin, passforthestaff);

      if (passforthestaff != "1234") {
        std::cout << "Wrong password. Access denied.\n";
        continue;
      }

      std::cout << "Access granted.\n";

      printInventory(greenhouse);

      int takingtheindex;
      std::cout << "Enter plant number to remove (Only DEAD plants allowed): ";
      if (!(std::cin >> takingtheindex)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        continue;
      }
      clearStdin();

      int postioninginArray = takingtheindex - 1;

      if (postioninginArray < 0 || postioninginArray >= greenhouse->getSize()) {
        std::cout << "Invalid index.\n";
        continue;
      }

      Plant *planttoremoveinpointer = greenhouse->at(postioninginArray);
      bool diditremove = greenhouse->removePlant(planttoremoveinpointer);

      if (diditremove) {
        std::cout << " Plant removed.\n";
      } else {
        std::cout << " Cannot remove this plant.\n";
      }
    }

    else if (choice == 5) {
      std::string passforthestaff;
      cout << "\n--- Observer Secure Access ---\n";
      cout << "Enter password: ";
      getline(std::cin, passforthestaff);

      if (passforthestaff != "1234") {
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

      if (!(std::cin >> obsChoice)) {
        clearStdin();
        continue;
      }
      clearStdin();

      if (obsChoice == 3) {
        std::cout << "Returning...\n";
        continue;
      }

      printInventory(greenhouse);

      int takingtheindex;
      std::cout << "Select plant number to edit: ";
      if (!(std::cin >> takingtheindex)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        continue;
      }
      clearStdin();

      int postioninginArray = takingtheindex - 1;
      if (postioninginArray < 0 || postioninginArray >= greenhouse->getSize()) {
        std::cout << "Invalid index.\n";
        continue;
      }

      Plant *planttoremoveinpointer = greenhouse->at(postioninginArray);
      if (planttoremoveinpointer == NULL) {
        std::cout << " Plant not found.\n";
        continue;
      }

      if (obsChoice == 1) {
        std::string st;
        std::cout << "State (seedling/growing/dormant/mature/selling/dead): ";
        std::getline(std::cin, st);

        PlantLifeCycleState *ns = makeState(st);
        if (!ns) {
          std::cout << " Invalid state.\n";
          continue;
        }

        applyStateAndNotify(planttoremoveinpointer, ns, observer);
        std::cout << " State updated: "
                  << planttoremoveinpointer->getLifeCycle()->name() << "\n";
      } else if (obsChoice == 2) {
        std::string st;
        std::cout << "Strategy (rose/cactus/lavender): ";
        std::getline(std::cin, st);

        CareStrategy *ns = makeStrategy(st);
        if (!ns) {
          std::cout << " Invalid strategy.\n";
          continue;
        }

        applyStrategyAndNotify(planttoremoveinpointer, ns, observer);
        std::cout << " Strategy updated!\n";
      } else {
        std::cout << " Invalid selection.\n";
      }
    }

    else if (choice == 6) {
      std::string pass;
      std::cout << "\n--- Staff Secure Access ---\n";
      std::cout << "Enter password: ";
      std::getline(std::cin, pass);
      if (pass != "1234") {
        std::cout << "Wrong password. Access denied.\n";
        continue;
      }

      printInventory(greenhouse);
      int idx;
      std::cout << "Select plant number to modify (or 0 to cancel): ";
      if (!(std::cin >> idx)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        continue;
      }
      clearStdin();
      if (idx == 0) {
        std::cout << "Cancelled.\n";
        continue;
      }
      int pos = idx - 1;
      if (pos < 0 || pos >= greenhouse->getSize()) {
        std::cout << "Invalid index.\n";
        continue;
      }
      Plant *p = greenhouse->at(pos);
      if (!p) {
        std::cout << "Plant not found.\n";
        continue;
      }

      PlantLifeCycleState *cur = p->getLifeCycle();
      if (!cur) {
        std::cout << "Plant has no lifecycle state.\n";
        continue;
      }

      std::cout << "\nSet options:\n1) Set Dead\n2) Set Attention\nChoose: ";
      int set = 0;
      if (!(std::cin >> set)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        continue;
      }
      clearStdin();

      PlantLifeCycleState *ns = nullptr;
      if (set == 1) {

        if (cur->getDead()) {
          std::cout << "Working" << std::endl;
          ns = new SellingState();
        } else {
          std::cout << "Working" << std::endl;
          ns = new DeadState();
        }
      } else if (set == 2) {
        if (cur->getAttention())
          ns = new DormantState();
        else
          ns = new GrowingState();
      } else {
        std::cout << "Invalid set option.\n";
        delete ns;
        continue;
      }

      applyStateAndNotify(p, ns, observer);
      std::cout << "Updated state: " << p->getLifeCycle()->name()
                << " | Attention: "
                << (p->getLifeCycle()->getAttention() ? "Yes" : "No")
                << " | Dead: " << (p->getLifeCycle()->getDead() ? "Yes" : "No")
                << "\n";
      continue;
    }

    else if (choice == 8)
    {
      std::cout << "Bye! See you soon\n";
      break;
    }
    else if (choice == 7)
    {
      std::cout << "\n=== Customer Browsing ===\n";
      std::cout << "Showing available (SELLING) plants:\n";
      printSellingOnly(greenhouse);

      while (true)
      {
        std::cout << "\n-- What would you like to do? --\n";
        std::cout << "1) Info about plants (Rose/Cactus/Lavender)\n";
        std::cout << "2) Quick recommendations (show selling again)\n";
        std::cout << "3) Back\n";
        std::cout << "Choose: ";

        int sub = 0;
        if (!(std::cin >> sub))
        {
          clearStdin();
          continue;
        }
        clearStdin();

        if (sub == 3)
        {
          std::cout << "Back to main menu.\n";
          break;
        }
        else if (sub == 1)
        {
          std::string type;
          std::cout << "Enter plant type (Rose/Cactus/Lavender): ";
          std::getline(std::cin, type);
          mediator.infoByType(type);
        }
        else if (sub == 2)
        {
          std::cout << "\nRecommended for you (available now):\n";
          printSellingOnly(greenhouse);
        }
        else
        {
          std::cout << "Invalid option.\n";
        }
      }
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
