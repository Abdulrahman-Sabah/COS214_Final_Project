#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H

/**
 * @file LavenderCreator.h
 * @brief Factory/Creator for Lavender instances.
 */

#include "Creator.h"

class LavenderCreator : public Creator {
public:
  LavenderCreator();

  /** @brief Create a new Lavender instance */
  Plant *factoryMethod() const;
};

#endif
