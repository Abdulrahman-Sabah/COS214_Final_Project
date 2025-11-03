#ifndef ROSESTRATEGYCMD_CPP_DOC
/**
 * @file RoseStrategyCmd.cpp
 * @brief Command implementation to apply Rose care strategy.
 * @author Git it done group members
 * @date 10-2025
 */
#define ROSESTRATEGYCMD_CPP_DOC
#endif

#include "RoseStrategyCmd.h"

#include "Plant.h"
#include "RoseCare.h"

RoseStrategyCmd::RoseStrategyCmd() : m_label("RoseStrategy") {}

std::string RoseStrategyCmd::name() { return m_label; }

void RoseStrategyCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setCareStrategy(new RoseCare());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}