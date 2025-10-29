#ifndef RECEIPT_H
#define RECEIPT_H

#include "Plant.h"
#include <vector>

class Receipt {
private:
  std::vector<Plant *> purchasedPlants;
  double totalAmount;

public:
  Receipt();
  ~Receipt();
  void addPlant(Plant *plant);
  void printReceipt() const;
};

#endif