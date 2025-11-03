
#ifndef STORECUSTOMER_H
#define STORECUSTOMER_H

/**
 * @file StoreCustomer.h
 * @brief Customer interacting with the store via mediator.
 * @author Git it done group members
 *  @date 10-2025
 */

#include "Commands.h"
#include "Plant.h"
#include "StoreColleague.h"
#include <iostream>

/**
 * @class StoreCustomer
 * @brief Represents a customer requesting plants.
 */
class StoreCustomer : public StoreColleague {
public:
  using StoreColleague::StoreColleague;
  /** @brief Default constructor */
  StoreCustomer() = default;
  /** @brief Destructor */
  ~StoreCustomer() override = default;

  /**
   * @brief Send request by plant name
   * @param plantName Name of plant
   */
  void requestPlant(const std::string &plantName);

  /**
   * @brief Send request by plant pointer
   * @param p Plant pointer
   */
  void requestPlant(Plant *p);

  /**
   * @brief Receive notification from mediator
   * @param event Event text
   */
  void receive(const std::string &event) override;
};

#endif // STORECUSTOMER_H
