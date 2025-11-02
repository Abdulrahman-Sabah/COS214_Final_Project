#ifndef SEEDLING_STATE_CMD_H
#define SEEDLING_STATE_CMD_H

/**
 * @file SeedlingStateCmd.h
 * @brief Command to transition a plant into the Seedling lifecycle state.
 */

#include <string>

#include "Commands.h"

class SeedlingStateCmd : public Commands {
public:
  SeedlingStateCmd();
  virtual ~SeedlingStateCmd() {}

  /** @brief Human-readable command name */
  std::string name();

  /**
   * @brief Execute the command on the given plant
   * @param plant Plant pointer to operate on
   */
  void execute(Plant *plant);

private:
  std::string m_label; /**< Optional label or payload for the command */
};

#endif