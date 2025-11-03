#ifndef PLANTDECORATIONS_H
#define PLANTDECORATIONS_H

/**
 * @file PlantDecorations.h
 * @brief Decorator base class for adding decorations/wraps to Plant objects.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>

#include "Plant.h"

using namespace std;

/**
 * @class PlantDecorations
 * @brief Abstract decorator class for Plant.
 */
class PlantDecorations : public Plant {
protected:
  /** @brief Wrapped plant */
  Plant *wrappedPlant;

public:
  /** @brief Construct a decorator wrapping an existing Plant */
  PlantDecorations(Plant *item);
  /** @brief Destructor */
  virtual ~PlantDecorations();
  /** @brief Get the name of the wrapped plant
   * @return Name string
   */
  string getName() override { return wrappedPlant->getName(); }

  /** @brief Description including any decoration details
   * @return Description string
   */
  virtual string description() = 0;

  /** @brief Price including decoration costs
   * @return Price value
   */
  virtual double price() = 0;

  /** @brief Clone the decorator and wrapped plant
   * @return Cloned Plant pointer
   */
  virtual Plant *clone() = 0;
};

#endif