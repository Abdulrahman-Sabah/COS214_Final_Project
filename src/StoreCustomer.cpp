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