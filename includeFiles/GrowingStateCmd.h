#ifndef GROWING_STATE_CMD_H
#define GROWING_STATE_CMD_H

#include <string>

#include "Commands.h"

class GrowingStateCmd : public Commands {
 public:
  GrowingStateCmd();
  virtual ~GrowingStateCmd() {}
  std::string name();
  void execute(Plant* plant);

 private:
  std::string m_label;
};

#endif