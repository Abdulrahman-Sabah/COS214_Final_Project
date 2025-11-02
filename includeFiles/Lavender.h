#ifndef LAVENDER_H
#define LAVENDER_H

/**
 * @file Lavender.h
 * @brief Concrete Lavender plant type.
 */

#include "Plant.h"

/**
 * @class Lavender
 * @brief Represents a lavender plant.
 */
class Lavender : public Plant {
public:
    Lavender();
    ~Lavender() override;

    /// @return Description string
    std::string description() override;

    /// @return Price value
    double price() override;

    /// @return Cloned Lavender object
    Plant* clone() override;

    /// @return "Lavender"
    std::string getType() const override { return "Lavender"; }
};

#endif // LAVENDER_H
