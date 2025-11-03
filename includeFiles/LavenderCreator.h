#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H

/**
 * @file LavenderCreator.h
 * @brief It defines the LavenderCreator class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Creator.h"

/**
 * @class LavenderCreator
 * @brief Concrete creator for Lavender plants.
 */

class LavenderCreator : public Creator {
public:
  /** @brief Constructor */
  LavenderCreator();

  /** @brief Create a new Lavender instance */
  Plant *factoryMethod() const;
};

#endif
