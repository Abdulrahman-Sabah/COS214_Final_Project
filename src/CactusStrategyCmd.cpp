#ifndef CACTUSSTRATEGYCMD_CPP_DOC
/**
 * @file CactusStrategyCmd.cpp
 * @brief Command implementation to set cactus care strategy on plants.
 */
#define CACTUSSTRATEGYCMD_CPP_DOC
#endif

#include "CactusStrategyCmd.h"

#include "CactusCare.h"
#include "Plant.h"

CactusStrategyCmd::CactusStrategyCmd() : m_label("CactusStrategy") {}

std::string CactusStrategyCmd::name() { return m_label; }

void CactusStrategyCmd::execute(Plant *plant) {
  if (!plant)
    return;
  plant->setCareStrategy(new CactusCare());
  std::cout << "[COMMAND USED] " << m_label << " applied to "
            << plant->getName() << "\n";
}