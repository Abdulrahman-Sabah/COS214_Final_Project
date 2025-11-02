/**
 * @file Creator.h
 * @brief Abstract factory for creating Plant objects.
 */

#ifndef CREATOR_H
#define CREATOR_H

#include "Plant.h"

/**
 * @class Creator
 * @brief Base class in the Factory Method pattern.
 */
class Creator {
public:
    Plant* product = nullptr;

    /**
     * @brief Create a plant object
     * @return New Plant instance
     */
    virtual Plant* factoryMethod() const = 0;

    /// Virtual destructor
    virtual ~Creator() = default;
};

#endif // CREATOR_H
