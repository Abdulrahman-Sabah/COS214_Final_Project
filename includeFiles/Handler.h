
#ifndef HANDLER_H
#define HANDLER_H
#include "Plant.h"

/**
 * @file Handler.h
 * @brief Handler base class for Chain of Responsibility pattern
 * @author Git it done group members
 * @date 2025
 */

// Forward declarations
class Notify;
class Commands;
/**
 * @class Handler
 * @brief Abstract base class implementing the Chain of Responsibility pattern
 *
 * @details The Handler class defines the interface for handling requests in a
 * chain. Each handler can process a request or pass it to the next handler in
 * the chain. This implements the Chain of Responsibility design pattern for the
 * greenhouse management system.
 */
class Handler {
protected:
  /**
   * @brief Helper method for derived classes to pass requests along the chain
   * @param cmd Pointer to the command to be passed to successor
   * @param plant Pointer to the Plant associated with the command (may be
   *        nullptr)
   *
   * @details This protected method allows derived handlers to easily pass
   * requests to the next handler in the chain when they cannot handle the
   * request themselves.
   */
  void passToSuccessor(Commands *cmd, Plant *plant);
  Handler *successor; /**< Pointer to next handler in chain */
  Notify *subject;    /**< Subject for observer pattern notifications */

public:
  /**
   * @brief Sets the next handler in the chain
   * @param h Pointer to the handler that should be the successor
   *
   * @details This method establishes the chain by setting which handler should
   * receive requests that this handler cannot process.
   */
  void setSuccessor(Handler *h);

  /**
   * @brief Pure virtual method for handling requests
   * @param cmd Pointer to the command to be handled
   * @param plant Pointer to the Plant associated with the command
   *
   * @details concrete handler must implement this method to define how it
   * processes specific types of requests. If the handler cannot process
   * the request, it should call passToSuccessor().
   */
  virtual void handleRequest(Commands *cmd, Plant *plant) = 0;

  /**
   * @brief Virtual destructor for proper polymorphic cleanup
   */
  virtual ~Handler();

  /**
   * @brief Default constructor
   */
  Handler();

  /**
   * @brief Get next handler in chain
   * @return Pointer to successor handler
   */
  Handler *getSuccessor() { return successor; }
};
#endif