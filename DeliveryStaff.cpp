#include "DeliveryStaff.h"
#include "StoreMediator.h"

void DeliveryStaff::handleRequest(Commands* r) {
    if (r && r->getType() == "ScheduleDelivery") {
        std::cout << "DeliveryStaff: Scheduling delivery...\n";
    } else {
        passToSuccessor(r);
    }
}

void DeliveryStaff::processCustomerRequest(Commands* cmd) {
    std::cout << "DeliveryStaff: Received request from customer through mediator.\n";

    std::cout << "DeliveryStaff: Fetching plant from greenhouse...\n";

    handleRequest(cmd);

    mediator->notify(this, "DeliveryReady", cmd);
}

void DeliveryStaff::receive(const std::string& event) {
    std::cout << "DeliveryStaff received event: " << event << "\n";
}
