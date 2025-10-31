
#ifndef GREENHOUSEMANAGER_H
#define GREENHOUSEMANAGER_H
#include "Commands.h"
#include "Handler.h"
#include "Plant.h"

/**
 * @class GreenhouseManager
 * @brief Handles sales and inventory management requests in the chain of
 * responsibility
 *
 * The GreenhouseManager class is a concrete handler that specifically processes
 * "MoveToSales" command types. It manages the transition of plants from growing
 * areas to sales areas. If it cannot handle a request, it passes the request
 * to the next handler in the chain.
 */
class GreenhouseManager : public Handler {
 public:
  /**
   * @brief Handles sales and inventory management requests
   * @param r Pointer to the command to be processed
   *
   * This method checks if the command type is "MoveToSales" and processes it.
   * If not, it passes the request to the next handler in the chain.
   */
  void handleRequest(Commands* r, Plant* plant);
};

#endif