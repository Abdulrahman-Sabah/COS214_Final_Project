
#ifndef CACTUS_STRATEGY_CMD_H
#define CACTUS_STRATEGY_CMD_H

/**
 * @file CactusStrategyCmd.h
 * @brief It defines the CactusStrategyCmd class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>

#include "Commands.h"
/**
 * @class CactusStrategyCmd
 * @brief Command to switch a plant's care strategy to CactusCare.
 * @details Inherits from Commands and implements the Command pattern
 * to execute the command to care for the plant as a cactus.
 */
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
  /**
   * @brief Label identifying this command.
   */
  std::string m_label;
};

#endif