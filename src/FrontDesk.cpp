#include "FrontDesk.h"
#include "StoreCustomer.h"
#include "DeliveryStaff.h"
#include <iostream>

void FrontDesk::setCustomer(StoreCustomer* c)      { customer = c; }
void FrontDesk::setDeliveryStaff(DeliveryStaff* d) { staff    = d; }

void FrontDesk::notify(Plant* plant, const std::string& event)
{
    if (event == "StoreCustomerRequest") {
        if (!staff) {
            std::cout << "Mediator: No DeliveryStaff set.\n";
            return;
        }
        std::cout << "Mediator: Forwarding customer request to DeliveryStaff.\n";
        staff->processCustomerRequest(plant);
    }
    else if (event == "DeliveryReady") {
        if (!customer) {
            std::cout << "Mediator: No StoreCustomer set.\n";
            return;
        }
        std::cout << "Mediator: Informing StoreCustomer that the plant is ready.\n";
        customer->receive("DeliveryReady");
    }
    else if (event == "PlantNotFound") {
        if (!customer) {
            std::cout << "Mediator: No StoreCustomer set.\n";
            return;
        }
        std::cout << "Mediator: Informing StoreCustomer that the plant is not available.\n";
        customer->receive("PlantNotFound");
    }
}
