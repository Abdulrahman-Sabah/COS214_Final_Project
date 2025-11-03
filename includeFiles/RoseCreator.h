#ifndef ROSECREATOR_H
#define ROSECREATOR_H

/**
 * @file RoseCreator.h
 * @brief Factory/Creator for Rose instances.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Creator.h"

/**
 * @class RoseCreator
 * @brief Concrete Creator for Rose plants.
 */
class RoseCreator : public Creator {
public:
  /** @brief Constructor */
  RoseCreator();

  /** @brief Create a new Rose instance */
  Plant *factoryMethod() const override;
};

#endif
