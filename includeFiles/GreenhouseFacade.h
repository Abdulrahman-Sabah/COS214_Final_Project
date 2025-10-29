#ifndef GREENHOUSEFACADE_H
#define GREENHOUSEFACADE_H

#include "Plant.h"
#include "SucculentBuilder.h"
#include <iostream>
#include <string>
#include <vector>

class GreenhouseFacade {
private:
  std::vector<Plant *> invent;
  SucculentBuilder *succulentBuilder;

public:
  GreenhouseFacade();
  ~GreenhouseFacade();
  void sellPlant(const std::string &name);
  void showInventory() const;
};

#endif