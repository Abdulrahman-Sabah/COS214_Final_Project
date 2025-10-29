#include "CustomerFacade.h"
#include "Receipt.h"
#include <iostream>

CustomerFacade::CustomerFacade(Inventory &inv) : inventory(inv) {}

void CustomerFacade::browsePlants() const { inventory.displayAll(); }

// Cart Management Methods
void CustomerFacade::addToCart(const std::string &name) {
  auto plant = inventory.removePlantByName(name);
  if (!plant) {
    std::cout << "Sorry, " << name << " is not currently in stock.\n";
    return;
  }

  std::cout << "Adding " << name << " to cart.\n";
  cart.push_back(std::unique_ptr<Plant>(plant));
}

void CustomerFacade::removeFromCart(const std::string &name) {
  for (auto it = cart.begin(); it != cart.end(); ++it) {
    if ((*it)->getName() == name) {
      std::cout << "Removing " << name << " from cart.\n";
      inventory.addPlant(it->release());
      cart.erase(it);
      return;
    }
  }
  std::cout << "Sorry, " << name << " is not in your cart.\n";
}

void CustomerFacade::viewCart() const {
  std::cout << "\n=== Your Shopping Cart ===\n";
  if (cart.empty()) {
    std::cout << "(empty)\n";
    return;
  }

  for (auto const &p : cart)
    std::cout << " - " << p->getName() << " (R" << p->price() << ")\n";
}

void CustomerFacade::checkout() {
  if (cart.empty()) {
    std::cout << "Your cart is empty. Add some plants before checking out.\n";
    return;
  }

  Receipt receipt;
  for (auto const &p : cart)
    receipt.addPlant(p.get());

  receipt.printReceipt();
  cart.clear();
}