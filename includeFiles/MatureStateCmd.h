#ifndef MATURE_STATE_CMD_H
#define MATURE_STATE_CMD_H

/**
 * @file MatureStateCmd.h
 * @brief Command to transition a plant into the Mature lifecycle state.
 *
 * Implements the Commands interface; used by handlers to promote plants to
 * the MatureState and perform any associated actions.
 */

#include <string>

#include "Commands.h"

class MatureStateCmd : public Commands {
public:
  MatureStateCmd();
  virtual ~MatureStateCmd() {}

  /** @brief Human-readable name for the command */
  std::string name();

  /**
   * @brief Execute the command on the given plant
   * @param plant Pointer to the plant to operate on
   */
  void execute(Plant *plant);

private:
  std::string m_label; /**< Optional label or payload for the command */
};

#endif