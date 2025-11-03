
#ifndef COMMANDS_H
#define COMMANDS_H

/**
 * @file Commands.h
 * @brief It defines the Commands class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>
#include "Plant.h"

/**
 * @class Commands
 * @brief Abstract command interface.
 */
class Commands {
public:
    /// @brief Default constructor
    Commands() = default;

    /// @brief Virtual destructor
    virtual ~Commands() = default;

    /// @return Command name
    virtual std::string name() = 0;

    /**
     * @brief Execute action on a plant
     * @param plant Target plant (may be nullptr)
     */
    virtual void execute(Plant* plant) = 0;
};

#endif // COMMANDS_H
