#ifndef CREATOR_H
#define CREATOR_H

/**
 * @file Creator.h
 * @brief Abstract creator/factory interface used to instantiate Plant objects.
 *
 * Part of the Factory Method pattern — concrete Creator subclasses implement
 * factoryMethod() to return different Plant subclasses.
 */

#include "Plant.h"

class Creator {
public:
  Plant *product;
  virtual Plant *factoryMethod() const = 0;

public:
  virtual ~Creator() {}
};

#endif