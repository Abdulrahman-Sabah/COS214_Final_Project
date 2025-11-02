#ifndef CARDDECORATOR_H
#define CARDDECORATOR_H

/**
 * @file CardDecorator.h
 * @brief Decorator that adds a greeting card to a plant order.
 *
 * CardDecorator wraps another Plant and adds a message and additional cost.
 */

#include "PlantDecorations.h"

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