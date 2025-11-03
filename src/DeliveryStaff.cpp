#ifndef DELIVERYSTAFF_CPP_DOC
/**
 * @file DeliveryStaff.cpp
 * @brief DeliveryStaff colleague implementation for mediator interactions.
 * @author Git it done group members
 * @date 10-2025
 */
#define DELIVERYSTAFF_CPP_DOC
#endif

#include "DeliveryStaff.h"

#include <iostream>

#include "Inventory.h"

void DeliveryStaff::processCustomerRequest(Plant *plant) {
  std::cout << "DeliveryStaff: Customer delivery request received.\n";

  if (!greenhouse_) {
    std::cout << "ERROR: DeliveryStaff has no inventory assigned.\n";
    return;
  }

  if (!plant) {
    std::cout << "ERROR: No plant provided.\n";
    return;
  }

  if (!greenhouse_->hasPlant(plant)) {
    std::cout << "DeliveryStaff: Plant is NOT in inventory.\n";
    if (auto *m = getMediator())
      m->notify(plant, "PlantNotFound");
    return;
  }

  std::cout << "DeliveryStaff: Plant found! Preparing delivery...\n";
  if (auto *m = getMediator())
    m->notify(plant, "DeliveryReady");
}

void DeliveryStaff::receive(const std::string &event) {
  std::cout << "DeliveryStaff received event: " << event << "\n";
}