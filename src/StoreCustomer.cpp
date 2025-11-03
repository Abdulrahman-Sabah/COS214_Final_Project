#ifndef STORECUSTOMER_CPP_DOC
/**
 * @file StoreCustomer.cpp
 * @brief Concrete colleague that represents a customer in the store mediator demo. 
 * @details Provides request and receive callbacks used by the StoreMediator or FrontDesk.
 * @author Git it done group members
 * @date 10-2025
 */
#define STORECUSTOMER_CPP_DOC
#endif

#include "StoreCustomer.h"

void StoreCustomer::requestPlant(Plant *p) {
  std::cout << "StoreCustomer: Requesting plant '" << p->getName() << "'\n";

  if (auto *m = getMediator()) {
    m->notify(p, "StoreCustomerRequest");
  }
}

void StoreCustomer::receive(const std::string &event) {
  if (event == "DeliveryReady") {
    std::cout << "StoreCustomer: My plant is ready for pickup!\n";
  } else if (event == "PlantNotFound") {
    std::cout << "StoreCustomer: They do not have that plant.\n";
  }
}