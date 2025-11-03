#ifndef DORMANTSTATECMD_CPP_DOC
/**
 * @file DormantStateCmd.cpp
 * @brief Command implementation for DormantState transitions.
 * @author Git it done group members
 * @date 10-2025
 */
#define DORMANTSTATECMD_CPP_DOC
#endif

#include "DormantStateCmd.h"

#include "DormantState.h"
#include "Plant.h"

DormantStateCmd::DormantStateCmd() : m_label("DormantState") {}

std::string DormantStateCmd::name() { return m_label; }

void DormantStateCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setLifeCycle(new DormantState());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}