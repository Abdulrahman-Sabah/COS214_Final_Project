#include "MatureStateCmd.h"

#include "MatureState.h"
#include "Plant.h"

MatureStateCmd::MatureStateCmd() : m_label("MatureState") {}

std::string MatureStateCmd::name() { return m_label; }

void MatureStateCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setLifeCycle(new MatureState());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}