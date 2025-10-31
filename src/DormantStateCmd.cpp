#include "DormantStateCmd.h"

#include "DormantState.h"
#include "Plant.h"

DormantStateCmd::DormantStateCmd() : m_label("DormantState") {}

std::string DormantStateCmd::name() { return m_label; }

void DormantStateCmd::execute(Plant* plant) {
  if (!plant) return;
  plant->setLifeCycle(new DormantState());
}