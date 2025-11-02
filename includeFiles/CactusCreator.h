#ifndef CACTUSCREATOR_H
#define CACTUSCREATOR_H

/**
 * @file CactusCreator.h
 * @brief Creator subclass responsible for producing Cactus objects.
 *
 * This class implements the Factory Method design pattern by providing
 * a concrete factory that creates Cactus instances. It allows plant
 * creation to be handled polymorphically through the Creator interface.
 */

#include "Creator.h"

/**
 * @class CactusCreator
 * @brief Factory class used to create Cactus plants.
 *
 * Specializes the Creator interface by overriding factoryMethod()
 * to instantiate Cactus objects. This allows runtime selection of
 * which specific plant type to create without modifying client code.
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
     * Implements the Factory Method pattern to encapsulate the
     * instantiation of plant objects based on type.
     *
     * @return A newly allocated Cactus object.
     */
    Plant* factoryMethod() const override;
};

#endif // CACTUSCREATOR_H
