#ifndef DORMANTSTATECMD_H
#define DORMANTSTATECMD_H

/**
 * @file DormantStateCmd.h
 * @brief Command to toggle or manage DormantState behaviour for a plant.
 */

#include <string>

#include "Commands.h"

class DormantStateCmd : public Commands {
public:
  DormantStateCmd();
  virtual ~DormantStateCmd() {}

  std::string name();
  void execute(Plant *plant);

private:
  std::string m_label;
};

#endif