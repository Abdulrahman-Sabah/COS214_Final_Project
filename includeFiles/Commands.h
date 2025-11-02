/**
 * @file Commands.h
 * @brief Abstract command interface for Command pattern implementation
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

#include "Plant.h"

/**
 * @class Commands
 * @brief Abstract base class for the Command pattern
 *
 * This class defines the interface for all commands in the greenhouse
 * management system. Commands encapsulate requests as objects, allowing for
 * parameterization of clients with different requests, queuing of requests, and
 * logging of requests.
 *
 * Concrete command classes should inherit from this class and implement the
 * pure virtual methods to define specific command behavior.
 */
class Commands {
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
   * what type of command they are processing and decide whether they can handle
   * it.
   */
  virtual std::string name() = 0;

  /**
   * @brief Execute the command on a Plant.
   * @param plant Pointer to the Plant to operate on. May be nullptr and
   *        implementations should handle that safely.
   *
   * Concrete commands perform their action in this method. The command owns
   * any internal state; callers are responsible for command lifetime unless
   * documented otherwise.
   */
  virtual void execute(Plant *plant) = 0;
  Commands() = default;
};

#endif