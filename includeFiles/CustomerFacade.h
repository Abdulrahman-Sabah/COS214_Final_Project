#ifndef CUSTOMER_FACADE_H
#define CUSTOMER_FACADE_H

#include "CactusBuilder.h"
#include "Inventory.h"
#include "LavenderBuilder.h"
#include "RoseBuilder.h"

#include <memory>
#include <string>
#include <vector>

class CustomerFacade {
private:
  Inventory &inventory;
  std::vector<std::unique_ptr<Plant>> cart;

public:
  explicit CustomerFacade(Inventory &inv);
  void browsePlants() const;
  void addToCart(const std::string &name);
  void removeFromCart(const std::string &name);
  void viewCart() const;
  void checkout();
};

#endif