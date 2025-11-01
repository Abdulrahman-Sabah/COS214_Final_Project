#include "CactusStrategyCmd.h"

#include "CactusCare.h"
#include "Plant.h"

CactusStrategyCmd::CactusStrategyCmd() : m_label("CactusStrategy") {}

std::string CactusStrategyCmd::name() { return m_label; }

void CactusStrategyCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setCareStrategy(new CactusCare());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}