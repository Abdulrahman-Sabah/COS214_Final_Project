
#ifndef LANDSCAPER_H
#define LANDSCAPER_H

/**
 * @file GreenhouseManager.h
 * @brief It defines the GreenhouseManager class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Handler.h"
#include "Plant.h"

/**
 * @class Landscaper
 * @brief Handles plant care requests in the chain of responsibility
 *
 * @details Inherits from Handler and implements the handleRequest method
 * to process plant care commands.
 */
class Landscaper : public Handler {
public:
  /**
   * @brief Handles plant care requests
   * @param cmd Pointer to the command to be processed
   * @param plant Pointer to the Plant associated with the command
   */
  void handleRequest(Commands *cmd, Plant *plant) override;
};

#endif