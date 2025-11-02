#ifndef LAVENDER_STRATEGY_CMD_H
#define LAVENDER_STRATEGY_CMD_H

/**
 * @file LavenderStrategyCmd.h
 * @brief Command to switch a plant's care strategy to LavenderCare.
 */

#include <string>

#include "Commands.h"

class LavenderStrategyCmd : public Commands {
public:
  LavenderStrategyCmd();
  ~LavenderStrategyCmd() override = default;

  /** @brief Human-readable command name */
  std::string name() override;

  /**
   * @brief Execute the command to set lavender care on the plant
   * @param plant Plant pointer to act upon
   */
  void execute(Plant *plant) override;

private:
  std::string m_label;
};

#endif