#ifndef ROSE_STRATEGY_CMD_H
#define ROSE_STRATEGY_CMD_H

/**
 * @file RoseStrategyCmd.h
 * @brief Command to switch a plant's care strategy to RoseCare.
 */

#include <string>

#include "Commands.h"

class RoseStrategyCmd : public Commands {
public:
  RoseStrategyCmd();
  ~RoseStrategyCmd() override = default;

  /** @brief Human-friendly name for the command */
  std::string name() override;

  /**
   * @brief Execute the command to set rose care on the plant
   * @param plant Plant pointer to act upon
   */
  void execute(Plant *plant) override;

private:
  std::string m_label;
};

#endif