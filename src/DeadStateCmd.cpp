#include "DeadStateCmd.h"

#include "DeadState.h"
#include "Plant.h"

DeadStateCmd::DeadStateCmd() : m_label("DeadState") {}

std::string DeadStateCmd::name() { return m_label; }

void DeadStateCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setLifeCycle(new DeadState());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}