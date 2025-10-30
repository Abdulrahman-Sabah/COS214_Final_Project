#ifndef MATURE_STATE_CMD_H
#define MATURE_STATE_CMD_H

#include "Commands.h"
#include <string>

class MatureStateCmd : public Commands {
public:
  MatureStateCmd();
  virtual ~MatureStateCmd() {}

  std::string name();
  void execute(Plant *plant);

private:
  std::string m_label;
};

#endif