#ifndef LAVENDERSTRATEGYCMD_CPP_DOC
/**
 * @file LavenderStrategyCmd.cpp
 * @brief Command implementation to apply Lavender care strategy.
 */
#define LAVENDERSTRATEGYCMD_CPP_DOC
#endif

#include "LavenderStrategyCmd.h"

#include "LavenderCare.h"
#include "Plant.h"

LavenderStrategyCmd::LavenderStrategyCmd() : m_label("LavenderStrategy") {}

std::string LavenderStrategyCmd::name() { return m_label; }

void LavenderStrategyCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setCareStrategy(new LavenderCare());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}