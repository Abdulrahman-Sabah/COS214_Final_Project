#ifndef CACTUS_STRATEGY_CMD_H
#define CACTUS_STRATEGY_CMD_H

/**
 * @file CactusStrategyCmd.h
 * @brief Command to switch a plant's care strategy to CactusCare.
 *
 * This command is used by handlers to change a plant's CareStrategy to
 * cactus-specific behavior.
 */

#include <string>

#include "Commands.h"

class CactusStrategyCmd : public Commands {
public:
  CactusStrategyCmd();
  ~CactusStrategyCmd() override = default;

  /**
   * @brief Returns a human-readable name for this command.
   */
  std::string name() override;

  /**
   * @brief Execute the command, switching the plant's care strategy.
   * @param plant Pointer to the plant to operate on.
   */
  void execute(Plant *plant) override;

private:
  std::string m_label;
};

#endif