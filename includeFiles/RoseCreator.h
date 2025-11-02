#ifndef ROSECREATOR_H
#define ROSECREATOR_H

/**
 * @file RoseCreator.h
 * @brief Factory/Creator for Rose instances.
 */

#include "Creator.h"

class RoseCreator : public Creator {
public:
  RoseCreator();

  /** @brief Create a new Rose instance */
  Plant *factoryMethod() const override;
};

#endif
