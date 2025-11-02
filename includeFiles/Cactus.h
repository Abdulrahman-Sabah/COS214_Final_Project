#ifndef CACTUS_H
#define CACTUS_H

/**
 * @file Cactus.h
 * @brief Declaration of the Cactus concrete plant class.
 *
 * This class represents a cactus item in the plant nursery.
 * Cactus objects have their own pricing, description, and type,
 * and support cloning through the Prototype design pattern.
 */

#include "Plant.h"

/**
 * @class Cactus
 * @brief Represents a cactus plant available for purchase.
 *
 * Inherits from the Plant abstract base class and overrides
 * required functions such as description(), price(), clone(),
 * and getType(). Cactus plants typically require low-water care.
 */
class Cactus : public Plant {
public:
    /**
     * @brief Default constructor.
     *
     * Initializes a cactus plant with its predefined lifecycle state,
     * care strategy, and seasonal attributes (if assigned later).
     */
    Cactus();

    /**
     * @brief Destructor.
     *
     * Ensures proper cleanup if strategies or states have been set.
     */
    ~Cactus();

    /**
     * @brief Returns a short description of the cactus.
     * @return A descriptive string about the cactus.
     */
    std::string description() override;

    /**
     * @brief Returns the cost of purchasing a cactus plant.
     * @return The base price value.
     */
    double price() override;

    /**
     * @brief Clone this cactus instance using deep copy.
     *
     * Supports Prototype design pattern for duplicating plants.
     * @return A pointer to a new cloned Cactus object.
     */
    Plant* clone() override;

    /**
     * @brief Retrieve the plant type name for UI or categorization.
     * @return Always returns "Cactus".
     */
    std::string getType() const override { return "Cactus"; }
};

#endif // CACTUS_H
