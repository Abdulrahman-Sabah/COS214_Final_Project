#ifndef RECEIPT_H
#define RECEIPT_H

/**
 * @file Receipt.h
 * @brief Simple purchase receipt for bought plants.
 * @author Git it done group members
 * @date 10-2025
 */

#include <vector>

#include "Plant.h"

/**
 * @class Receipt
 * @brief Represents a purchase receipt for plants.
 */
class Receipt {
private:
  /** @brief List of purchased plants */
  std::vector<Plant *> purchasedPlants;
  /** @brief Total amount of the receipt */
  double totalAmount;

public:
  /** @brief Constructor */
  Receipt();
  /** @brief Destructor */
  ~Receipt();

  /** @brief Add a purchased plant to the receipt */
  void addPlant(Plant *plant);

  /** @brief Print the receipt to stdout */
  void printReceipt() const;
};

#endif