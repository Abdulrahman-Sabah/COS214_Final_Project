#ifndef RECEIPT_H
#define RECEIPT_H

/**
 * @file Receipt.h
 * @brief Simple purchase receipt for bought plants.
 */

#include <vector>

#include "Plant.h"

class Receipt {
private:
  std::vector<Plant *> purchasedPlants;
  double totalAmount;

public:
  Receipt();
  ~Receipt();

  /** @brief Add a purchased plant to the receipt */
  void addPlant(Plant *plant);

  /** @brief Print the receipt to stdout */
  void printReceipt() const;
};

#endif