#include "FrontDesk.h"

#include <iostream>

#include "DeliveryStaff.h"
#include "StoreCustomer.h"

void FrontDesk::setCustomer(StoreCustomer *c) { customer = c; }
void FrontDesk::setDeliveryStaff(DeliveryStaff *d) { staff = d; }

void FrontDesk::notify(Plant *plant, const std::string &event) {
  if (event == "StoreCustomerRequest") {
    if (!staff) {
      std::cout << "Mediator: No DeliveryStaff set.\n";
      return;
    }
    std::cout << "Mediator: Forwarding customer request to DeliveryStaff.\n";
    staff->processCustomerRequest(plant);
  } else if (event == "DeliveryReady") {
    if (!customer) {
      std::cout << "Mediator: No StoreCustomer set.\n";
      return;
    }
    std::cout << "Mediator: Informing StoreCustomer that the plant is ready.\n";
    customer->receive("DeliveryReady");
  } else if (event == "PlantNotFound") {
    if (!customer) {
      std::cout << "Mediator: No StoreCustomer set.\n";
      return;
    }
    std::cout << "Mediator: Informing StoreCustomer that the plant is not "
                 "available.\n";
    customer->receive("PlantNotFound");
  }
}



void FrontDesk::infoByType(const std::string& type) const {
    std::string t = type;
    for (char &c : t) c = (char)std::tolower(c);

    std::cout << "\n=== Plant Information ===\n";

    if (t == "rose") {
        std::cout << " Rose\n"
                  << "• Beautiful flowering plant commonly in gardens.\n"
                  << "• Requires moderate water and sunlight.\n"
                  << "• Has thorns and fragrant blooms.\n"
                  << "• Popular choice for gifts and decoration.\n";
    } 
    else if (t == "cactus") {
        std::cout << " Cactus\n"
                  << "• Desert plant that stores water.\n"
                  << "• Requires very little watering.\n"
                  << "• Great for people who forget to water plants.\n"
                  << "• Comes in many shapes and sizes.\n";
    } 
    else if (t == "lavender") {
        std::cout << " Lavender\n"
                  << "• Known for its relaxing scent and purple flowers.\n"
                  << "• Good for sunny areas.\n"
                  << "• Used in perfumes and oils.\n"
                  << "• Attracts bees and butterflies.\n";
    } 
    else {
        std::cout << "Sorry, we don't have information for: " << type << "\n";
    }

    std::cout << "====================================\n";
}
