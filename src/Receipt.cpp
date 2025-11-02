#ifndef RECEIPT_CPP_DOC
/**
 * @file Receipt.cpp
 * @brief Receipts for purchases and printing utilities.
 */
#define RECEIPT_CPP_DOC
#endif

#include "Receipt.h"

#include <iomanip>
#include <iostream>

Receipt::Receipt() : totalAmount(0.0) {}

Receipt::~Receipt() {
  for (auto *p : purchasedPlants) {
    delete p;
  }
}

void Receipt::addPlant(Plant *p) {
  purchasedPlants.push_back(p);
  totalAmount += p->price();
}

void Receipt::printReceipt() const {
  std::cout << "\n====== RECEIPT ======\n";

  // Printing Header
  std::cout << std::left << std::setw(20) << "Plant Name" << std::setw(15)
            << "Care Type" << std::setw(10) << "Season" << std::setw(10)
            << "Price\n";

  std::cout << "---------------------------------------------\n";

  // Printing each purchased plant
  for (auto *p : purchasedPlants) {
    std::cout << std::left << std::setw(20) << p->getName() << std::setw(15)
              << p->getCareType() << std::setw(10) << p->getSeason() << "R"
              << std::fixed << std::setprecision(2) << p->price() << "\n";
  }

  std::cout << "---------------------------------------------\n";

  // Printing Footer

  std::cout << "TOTAL: R" << totalAmount << std::endl;
  std::cout << "Thank you for shopping with Git It Done Greenhouse!\n";
  std::cout << "=====================\n";
}
