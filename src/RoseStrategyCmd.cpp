#include "RoseStrategyCmd.h"
#include "Plant.h"
#include "RoseCare.h"

RoseStrategyCmd::RoseStrategyCmd() : m_label("RoseStrategy") {}

std::string RoseStrategyCmd::name() { return m_label; }

void RoseStrategyCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setCareStrategy(new RoseCare());
}