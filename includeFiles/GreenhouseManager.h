
#ifndef GREENHOUSEMANAGER_H
#define GREENHOUSEMANAGER_H

/**
 * @file GreenhouseManager.h
 * @brief It defines the GreenhouseManager class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Commands.h"
#include "Handler.h"
#include "Plant.h"

/**
 * @class GreenhouseManager
 * @brief Handles sales and inventory management requests in the chain of responsibility
 * @details Inherits from Handler and processes requests related to moving plants to sales
 * and managing the inventory
 */
class GreenhouseManager : public Handler {
public:
  /**
   * @brief Handles sales and inventory management requests
   * @param cmd Pointer to the command to be processed
   * @param plant Pointer to the Plant associated with the request
   * @details This method checks the command type and if it is valid it processes it.
   * If not, it passes the request to the next handler in the chain.
   */
  void handleRequest(Commands *cmd, Plant *plant);
};

#endif