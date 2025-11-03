
#ifndef CACTUSCREATOR_H
#define CACTUSCREATOR_H

/**
 * @file CactusCreator.h
 * @brief It defines the CactusCreator class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Creator.h"

/**
 * @class CactusCreator
 * @brief Factory class used to create Cactus plants.
 * @details Inherits from Creator and implements the Factory Method pattern
 * to create Cactus objects.
 */
class CactusCreator : public Creator {
public:
  /**
   * @brief Default constructor.
   */
  CactusCreator() = default;

  /**
   * @brief Creates and returns a new Cactus instance.
   *
   * @details Implements the Factory Method pattern to encapsulate the
   * instantiation of plant objects based on type.
   *
   * @return A newly allocated Cactus object.
   */
  Plant *factoryMethod() const override;
};

#endif // CACTUSCREATOR_H
