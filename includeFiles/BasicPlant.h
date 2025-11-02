#ifndef BASICPLANT_H
#define BASICPLANT_H

/**
 * @file BasicPlant.h
 * @brief Concrete implementation of a simple Plant type.
 *
 * This class represents a basic plant model with a name, price,
 * and basic description. It supports cloning (Prototype pattern),
 * pricing, and descriptive details without advanced behaviors.
 */

#include "Plant.h"

/**
 * @class BasicPlant
 * @brief Represents a simple, concrete plant used in the nursery inventory.
 *
 * Inherits from the Plant abstract class and provides basic information:
 * - Fixed price
 * - Text description
 * - Care type, lifecycle state, and seasonal information
 */
class BasicPlant : public Plant {
private:
    /**
     * @brief The base retail price for this plant.
     */
    double basePrice;

    /**
     * @brief A short descriptive summary of the plant.
     */
    string plantDescription;

public:
    /**
     * @brief Construct a new BasicPlant object.
     *
     * @param name Display name of the plant.
     * @param description Text describing appearance or details.
     * @param price Base cost for purchasing this plant.
     * @param careType Care strategy label (default = "Basic").
     * @param state Initial lifecycle state (default = "Healthy").
     * @param season Seasonal availability (default = "AllSeason").
     */
    BasicPlant(string name,
               string description,
               double price,
               string careType = "Basic",
               string state = "Healthy",
               string season = "AllSeason");

    /**
     * @brief Get a descriptive string for the plant.
     * @return The stored description text.
     */
    string description() override;

    /**
     * @brief Get the price of the plant.
     * @return The stored base price value.
     */
    double price() override;

    /**
     * @brief Clone this plant instance (Prototype pattern support).
     *
     * @return A newly allocated BasicPlant object with
     *         identical internal data.
     */
    Plant* clone() override;
};

#endif // BASICPLANT_H
