/**
 * @file DeliveryStaff.cpp
 * @brief Implementation of DeliveryStaff handler for delivery scheduling
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "DeliveryStaff.h"
#include "Commands.h"
#include <iostream>
void DeliveryStaff::handleRequest(Commands *r) {

  if (r && r->getType() == "ScheduleDelivery") {
    std::cout << "Delivery Staff is scheduling the delivery." << std::endl;
  } else {
    // Pass to next handler in chain using protected method
    passToSuccessor(r);
  }
}