/**
 * @file PlantDecorations.h
 * @brief Abstract base class for the Decorator pattern implementation
 * @author COS214 Students
 * @date 2024
 */

#ifndef PLANTDECORATIONS_H
#define PLANTDECORATIONS_H

#include "Plant.h"
#include <string>

using namespace std;

/**
 * @class PlantDecorations
 * @brief Abstract decorator class that allows adding features to plants
 * dynamically
 *
 * This class implements the Decorator pattern for the Plant hierarchy, allowing
 * additional features (like pots, cards, wrapping) to be added to plants at
 * runtime without modifying their original structure.
 */
class PlantDecorations : public Plant {
protected:
  Plant *wrappedPlant; ///< The plant being decorated

public:
  /**
   * @brief Constructor that wraps an existing plant
   * @param item The plant to be decorated
   */
  PlantDecorations(Plant *item) : wrappedPlant(item) {}

  /**
   * @brief Virtual destructor that cleans up the wrapped plant
   */
  virtual ~PlantDecorations() { delete wrappedPlant; }

  /**
   * @brief Gets the name of the wrapped plant
   * @return The name of the wrapped plant
   */
  string getName() override { return wrappedPlant->getName(); }

  /**
   * @brief Pure virtual method to get decoration description
   * @return String description of the decoration
   */
  virtual string description() = 0;

  /**
   * @brief Pure virtual method to get the total price including decoration
   * @return The total price of the decorated plant
   */
  virtual double price() = 0;

  /**
   * @brief Pure virtual method to clone the decorated plant
   * @return A pointer to a cloned decorated plant
   */
  virtual Plant *clone() = 0;
};

#endif