#ifndef ROSE_H
#define ROSE_H

/**
 * @file Rose.h
 * @brief Concrete Rose plant type.
 */

#include "Plant.h"

/**
 * @class Rose
 * @brief Represents a rose plant.
 */
class Rose : public Plant {
public:
    Rose();
    ~Rose() override;

    /// @return Description string
    std::string description() override;

    /// @return Price value
    double price() override;

    /// @return Cloned Rose object
    Plant* clone() override;

    /// @return "Rose"
    std::string getType() const override { return "Rose"; }
};

#endif // ROSE_H
