#ifndef GROWINGSTATECMD_CPP_DOC
/**
 * @file GrowingStateCmd.cpp
 * @brief Command implementation for GrowingState transitions.
 */
#define GROWINGSTATECMD_CPP_DOC
#endif

#include "GrowingStateCmd.h"

#include "GrowingState.h"
#include "Plant.h"

GrowingStateCmd::GrowingStateCmd() : m_label("GrowingState") {}

std::string GrowingStateCmd::name() { return m_label; }

void GrowingStateCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setLifeCycle(new GrowingState());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}