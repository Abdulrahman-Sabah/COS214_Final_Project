#ifndef CACTUS_STRATEGY_CMD_H
#define CACTUS_STRATEGY_CMD_H

#include <string>

#include "Commands.h"

class CactusStrategyCmd : public Commands {
public:
  CactusStrategyCmd();
  ~CactusStrategyCmd() override = default;

  std::string name() override;
  void execute(Plant *plant) override;

private:
  std::string m_label;
};

#endif