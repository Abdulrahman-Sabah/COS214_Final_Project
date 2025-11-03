/**
 * @file Commands.h
 * @brief Base class for Command pattern.
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include "Plant.h"

/**
 * @class Commands
 * @brief Abstract command interface.
 */
class Commands {
public:
    /// Default constructor
    Commands() = default;

    /// Virtual destructor
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
