#include "SeedlingStateCmd.h"

#include "Plant.h"
#include "SeedlingState.h"

SeedlingStateCmd::SeedlingStateCmd() : m_label("SeedlingState") {}

std::string SeedlingStateCmd::name() { return m_label; }

void SeedlingStateCmd::execute(Plant* plant) {
  if (!plant) return;
  plant->setLifeCycle(new SeedlingState());
  cout << "Cycle is being changed" << endl;
}