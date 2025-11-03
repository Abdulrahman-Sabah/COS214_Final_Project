
#ifndef BASICPLANT_H
#define BASICPLANT_H

/**
 * @file BasicPlant.h
 * @brief It defines the BasicPlant class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Plant.h"

/**
 * @class BasicPlant
 * @brief Represents a simple, concrete plant used in the nursery inventory.
 * @details Inherits from the Plant abstract class and provides basic information:
 * such as price, description name, state season and caretype.
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
     * @brief Cloning the plant (Prototype design pattern).
     *
     * @return A newly allocated BasicPlant object with
     *         identical internal data.
     */
    Plant* clone() override;
};

#endif // BASICPLANT_H
