#ifndef LAVENDER_STRATEGY_CMD_H
#define LAVENDER_STRATEGY_CMD_H

#include <string>

#include "Commands.h"

class LavenderStrategyCmd : public Commands {
 public:
  LavenderStrategyCmd();
  ~LavenderStrategyCmd() override = default;

  std::string name() override;
  void execute(Plant* plant) override;

 private:
  std::string m_label;
};

#endif