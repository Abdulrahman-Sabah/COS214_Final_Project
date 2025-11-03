
#ifndef CREATOR_H
#define CREATOR_H

/**
 * @file Creator.h
 * @brief It defines the Creator class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

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

    /// @brief Virtual destructor
    virtual ~Creator() = default;
};

#endif // CREATOR_H
