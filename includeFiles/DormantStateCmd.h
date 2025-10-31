#ifndef DORMANTSTATECMD_H
#define DORMANTSTATECMD_H

#include <string>

#include "Commands.h"

class DormantStateCmd : public Commands {
 public:
  DormantStateCmd();
  virtual ~DormantStateCmd() {}

  std::string name();
  void execute(Plant* plant);

 private:
  std::string m_label;
};

#endif