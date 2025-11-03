#ifndef ROSECARE_H
#define ROSECARE_H

/**
 * @file RoseCare.h
 * @brief Care strategy for rose plants.
 * @author Git it done group members
 * @date 10-2025
 */

#include "CareStrategy.h"

/**
 * @class RoseCare
 * @brief Applies rose-specific care.
 */
class RoseCare : public CareStrategy {
public:
  /**
   * @brief Apply rose care actions
   * @param plant Target plant
   */
  void applyCare(Plant *plant) override;

  /// @brief Destructor
  ~RoseCare() override = default;
};

#endif // ROSECARE_H
