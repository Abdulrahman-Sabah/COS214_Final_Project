
#ifndef CARDDECORATOR_H
#define CARDDECORATOR_H

/**
 * @file CardDecorator.h
 * @brief It defines the CardDecorator class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantDecorations.h"

/**
 * @class CardDecorator
 * @brief Decorator adding a greeting card to a plant purchase.
 * @details Inherits from PlantDecorations and implements the Decorator pattern
 * to add card-specific details such as message and additional cost.
 */
class CardDecorator : public PlantDecorations {
private:
  string message; /**< Message printed on the card */
  double cardCost; /**< Additional cost for the card */

public:
  /**
   * @brief Construct a CardDecorator
   * @param item Underlying plant to decorate
   * @param msg Card message text
   * @param cost Additional cost added by the card
   */
  CardDecorator(Plant *item, string msg, double cost);

  /** @brief Returns description including card message */
  string description() override;

  /** @brief Returns total price including card cost */
  double price() override;

  /** @brief Clone the decorator and the wrapped plant */
  Plant *clone() override;
};

#endif