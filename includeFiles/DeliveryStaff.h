/**
 * @file DeliveryStaff.h
 * @brief Concrete handler for delivery-related requests in Chain of
 * Responsibility pattern
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H
#include "Handler.h"

/**
 * @class DeliveryStaff
 * @brief Handles delivery scheduling requests in the chain of responsibility
 *
 * The DeliveryStaff class is a concrete handler that specifically processes
 * "ScheduleDelivery" command types. If it cannot handle a request, it passes
 * the request to the next handler in the chain.
 */
class DeliveryStaff : public Handler {
public:
  /**
   * @brief Handles delivery-related requests
   * @param r Pointer to the command to be processed
   *
   * This method checks if the command type is "ScheduleDelivery" and processes
   * it. If not, it passes the request to the next handler in the chain.
   */
  void handleRequest(Commands *r) override;
};

#endif