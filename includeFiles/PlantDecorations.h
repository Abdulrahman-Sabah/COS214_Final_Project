#ifndef PLANTDECORATIONS_H
#define PLANTDECORATIONS_H

/**
 * @file PlantDecorations.h
 * @brief Decorator base class for adding decorations/wraps to Plant objects.
 */

#include <string>

#include "Plant.h"

using namespace std;

class PlantDecorations : public Plant {
protected:
  Plant *wrappedPlant; 

public:
  /** @brief Construct a decorator wrapping an existing Plant */
  PlantDecorations(Plant *item);

  virtual ~PlantDecorations();

  string getName() override { return wrappedPlant->getName(); }

  /** @brief Description including any decoration details */
  virtual string description() = 0;

  /** @brief Price including decoration costs */
  virtual double price() = 0;

  /** @brief Clone the decorator and wrapped plant */
  virtual Plant *clone() = 0;
};

#endif