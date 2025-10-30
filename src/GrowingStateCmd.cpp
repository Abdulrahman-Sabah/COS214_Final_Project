#include "GrowingStateCmd.h"
#include "GrowingState.h"
#include "Plant.h"

GrowingStateCmd::GrowingStateCmd() : m_label("GrowingState") {}

std::string GrowingStateCmd::name() { return m_label; }

void GrowingStateCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setLifeCycle(new GrowingState());
}