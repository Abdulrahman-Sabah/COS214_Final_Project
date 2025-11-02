#ifndef CACTUSCREATOR_H
#define CACTUSCREATOR_H

/**
 * @file CactusCreator.h
 * @brief Factory/Creator for Cactus instances.
 *
 * Provides the factoryMethod() used to create new Cactus objects. Part of
 * a family of Creator classes implementing the Factory Method pattern.
 */

#include "Creator.h"

class CactusCreator : public Creator {
public:
  CactusCreator() = default;
  Plant *factoryMethod() const override;
};

#endif
