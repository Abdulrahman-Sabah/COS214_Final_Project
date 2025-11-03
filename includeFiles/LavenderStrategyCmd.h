#ifndef LAVENDER_STRATEGY_CMD_H
#define LAVENDER_STRATEGY_CMD_H

/**
 * @file LavenderStrategyCmd.h
 * @brief Command to set plant care to LavenderCare.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Commands.h"
#include <string>

/**
 * @class LavenderStrategyCmd
 * @brief Applies LavenderCare strategy to a plant.
 */
class LavenderStrategyCmd : public Commands {
public:
  /** @brief Constructor */
  LavenderStrategyCmd();
  /** @brief Destructor */
  ~LavenderStrategyCmd() override = default;

  /**
   * @brief Gets the command name
   * @return Command name */
  std::string name() override;

  /**
   * @brief Set lavender care
   * @param plant Target plant
   */
  void execute(Plant *plant) override;

private:
  /** @brief Command label */
  std::string m_label;
};

#endif // LAVENDER_STRATEGY_CMD_H
