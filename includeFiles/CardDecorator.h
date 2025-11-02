/**
 * @file CardDecorator.h
 * @brief Card decorator for adding greeting cards to plants
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef CARDDECORATOR_H
#define CARDDECORATOR_H

#include "PlantDecorations.h"

/**
 * @class CardDecorator
 * @brief Concrete decorator that adds greeting cards to plants
 *
 * CardDecorator implements the Decorator pattern to add greeting card
 * functionality to plants. It enhances plants with personalized messages
 * and adjusts the total price accordingly.
 */
class CardDecorator : public PlantDecorations {
private:
  string message;  ///< Message text for the greeting card
  double cardCost; ///< Additional cost for the card

public:
  /**
   * @brief Constructor for CardDecorator
   * @param item Pointer to the plant being decorated
   * @param msg Message text for the greeting card
   * @param cost Additional cost for adding the card
   */
  CardDecorator(Plant *item, string msg, double cost);

  /**
   * @brief Gets the enhanced description including card message
   * @return String describing the plant with card information
   */
  string description() override;

  /**
   * @brief Gets the total price including card cost
   * @return Double representing the plant price plus card cost
   */
  double price() override;

  /**
   * @brief Creates a clone of this decorated plant
   * @return Pointer to a new CardDecorator with the same properties
   */
  Plant *clone() override;
};

#endif