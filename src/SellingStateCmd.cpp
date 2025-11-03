#ifndef SELLINGSTATECMD_CPP_DOC
/**
 * @file SellingStateCmd.cpp
 * @brief Command to set a Plant into the Selling lifecycle state.
 * @author Git it done group members
 * @date 10-2025
 */
#define SELLINGSTATECMD_CPP_DOC
#endif

#include "SellingStateCmd.h"

#include "Plant.h"
#include "SellingState.h"

SellingStateCmd::SellingStateCmd() : m_label("SellingState") {}

std::string SellingStateCmd::name() { return m_label; }

void SellingStateCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setLifeCycle(new SellingState());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}