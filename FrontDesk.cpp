#include "FrontDesk.h"
#include "StoreCustomer.h"
#include "DeliveryStaff.h"
#include "Handler.h"
#include <iostream>

FrontDesk::FrontDesk(StoreCustomer* c, DeliveryStaff* d, Handler* chain)
    : customer(c), staff(d), handlerChain(chain) {}


void FrontDesk::setCustomer(StoreCustomer* c) { StoreCustomer c; }
void FrontDesk::setDeliveryStaff(DeliveryStaff* d) { staff = d; }
void FrontDesk::setHandlerChain(Handler* chain) { handlerChain = chain; }

void FrontDesk::notify(void* sender, const std::string& event, Commands* cmd) {
    if (event == "StoreCustomerRequest") {
        std::cout << "Mediator: Forwarding StoreCustomer request to DeliveryStaff.\n";
        staff->processCustomerRequest(cmd);
    } else if (event == "DeliveryReady") {
        std::cout << "Mediator: Informing StoreCustomer that the plant is ready.\n";
        customer->receive("DeliveryReady");
    }
}
