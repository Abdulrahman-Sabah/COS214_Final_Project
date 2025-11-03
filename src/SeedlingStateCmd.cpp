#ifndef SEEDLINGSTATECMD_CPP_DOC
/**
 * @file SeedlingStateCmd.cpp
 * @brief Command implementation to set Seedling lifecycle state on plants.
 * @author Git it done group members
 * @date 10-2025
 */
#define SEEDLINGSTATECMD_CPP_DOC
#endif

#include "SeedlingStateCmd.h"

#include "Plant.h"
#include "SeedlingState.h"

SeedlingStateCmd::SeedlingStateCmd() : m_label("SeedlingState") {}

std::string SeedlingStateCmd::name() { return m_label; }

void SeedlingStateCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setLifeCycle(new SeedlingState());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}