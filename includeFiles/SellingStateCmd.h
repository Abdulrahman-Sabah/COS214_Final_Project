#ifndef SELLING_STATE_CMD_H
#define SELLING_STATE_CMD_H

/**
 * @file SellingStateCmd.h
 * @brief Command to transition a plant into the Selling lifecycle state.
 */

#include <string>

#include "Commands.h"

class SellingStateCmd : public Commands {
public:
  SellingStateCmd();
  virtual ~SellingStateCmd() {}

  /** @brief Return a human-readable name for this command */
  std::string name();

  /**
   * @brief Execute the command on the provided plant
   * @param plant Plant pointer to operate on
   */
  void execute(Plant *plant);

private:
  std::string m_label; /**< Optional label or payload for the command */
};

#endif