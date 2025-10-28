/**
 * @file Commands.h
 * @brief Abstract command interface for Command pattern implementation
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

/**
 * @class Commands
 * @brief Abstract base class for the Command pattern
 * 
 * This class defines the interface for all commands in the greenhouse management system.
 * Commands encapsulate requests as objects, allowing for parameterization of clients
 * with different requests, queuing of requests, and logging of requests.
 * 
 * Concrete command classes should inherit from this class and implement the pure
 * virtual methods to define specific command behavior.
 */
class Commands 
{
public:
    /**
     * @brief Virtual destructor for proper polymorphic cleanup
     */
    virtual ~Commands() = default;
    
    /**
     * @brief Gets the type/name of the command
     * @return String representing the command type
     * 
     * This method allows handlers in the Chain of Responsibility to identify
     * what type of command they are processing and decide whether they can handle it.
     */
    virtual std::string getType() const = 0;
    
    /**
     * @brief Gets the data/parameters associated with the command
     * @return String containing command-specific data
     * 
     * This method provides access to any additional data or parameters
     * that the command needs for execution (e.g., plant IDs, order numbers).
     */
    virtual std::string getData() const = 0;
};

#endif
