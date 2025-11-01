#include "LavenderStrategyCmd.h"

#include "LavenderCare.h"
#include "Plant.h"

LavenderStrategyCmd::LavenderStrategyCmd() : m_label("LavenderStrategy") {}

std::string LavenderStrategyCmd::name() { return m_label; }

void LavenderStrategyCmd::execute(Plant* plant) {
  if (!plant) return;
  plant->setCareStrategy(new LavenderCare());
      std::cout << "[COMMAND USED] " << m_label << " applied to "<< plant->getName() << "\n";

}