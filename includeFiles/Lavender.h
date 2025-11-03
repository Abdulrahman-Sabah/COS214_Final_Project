#ifndef LAVENDER_H
#define LAVENDER_H
/**
 * @file Lavender.h
 * @brief It defines the Lavender class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Plant.h"

/**
 * @class Lavender
 * @brief Represents a lavender plant.
 * @details Inherits from Plant and implements specific behavior for lavender.
 */
class Lavender : public Plant {
public:
    /**
     * @brief Constructor
     */
    Lavender();
    /**
     * @brief Destructor
     */
    ~Lavender() override;

    /**
     * @brief Get the description of the lavender plant
     * @return Description string
     */
    std::string description() override;

    /**
     * @brief Get the price of the lavender plant
     * @return Price value
     */
    double price() override;

    /**
     * @brief Clone the lavender plant
     * @return Pointer to cloned Lavender object
     */
    Plant* clone() override;

    /**
     * @brief Get the type of the lavender plant
     * @return Type string( always 'Lavender')
     */
    std::string getType() const override { return "Lavender"; }
};

#endif // LAVENDER_H
