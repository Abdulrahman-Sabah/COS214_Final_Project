#ifndef SELLING_STATE_CMD_H
#define SELLING_STATE_CMD_H

/**
 * @file SellingStateCmd.h
 * @brief Command to set a plant to SellingState.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Commands.h"
#include <string>

/**
 * @class SellingStateCmd
 * @brief Applies SellingState to a plant.
 */
class SellingStateCmd : public Commands {
public:
  /** @brief Constructor */
  SellingStateCmd();
  /** @brief Destructor */
  ~SellingStateCmd() override = default;

  /**
   * @brief Get the command name
   * @return Command name
   */
  std::string name() override;

  /**
   * @brief Set selling state
   * @param plant Target plant
   */
  void execute(Plant *plant) override;

private:
  /** @brief Label for the command */
  std::string m_label;
};

#endif // SELLING_STATE_CMD_H
