#include "StoreCustomer.h"

void StoreCustomer::requestPlant(const std::string& plantName) {
    std::cout << "StoreCustomer: Requesting plant '" << plantName << "'\n";
    Commands* cmd = new Commands("FetchPlant", plantName); 
    mediator->notify(this, "StoreCustomerRequest", cmd);
}

void StoreCustomer::receive(const std::string& event) {
    if (event == "DeliveryReady") {
        std::cout << "StoreCustomer: My plant is ready at the front of the shop!\n";
    }
}
