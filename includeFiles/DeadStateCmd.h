#ifndef DEAD_STATE_CMD_H
#define DEAD_STATE_CMD_H

/**
 * @file DeadStateCmd.h
 * @brief Command that transitions a plant into the DeadState or handles
 * related dead-state actions.
 */

#include <string>

#include "Commands.h"

class DeadStateCmd : public Commands {
public:
  DeadStateCmd();
  virtual ~DeadStateCmd() {}

  std::string name();
  void execute(Plant *plant);

private:
  std::string m_label;
};

#endif