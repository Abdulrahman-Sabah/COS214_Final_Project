#include "SellingStateCmd.h"

#include "Plant.h"
#include "SellingState.h"

SellingStateCmd::SellingStateCmd() : m_label("SellingState") {}

std::string SellingStateCmd::name() { return m_label; }

void SellingStateCmd::execute(Plant* plant) {
  if (!plant) return;
  plant->setLifeCycle(new SellingState());
}