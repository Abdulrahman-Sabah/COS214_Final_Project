#include "CactusStrategyCmd.h"
#include "Plant.h"
#include "CactusCare.h"

CactusStrategyCmd::CactusStrategyCmd() : m_label("CactusStrategy") {}

std::string CactusStrategyCmd::name() { return m_label; }

void CactusStrategyCmd::execute(Plant* plant) {
    if (!plant) return;
    plant->setCareStrategy(new CactusCare());
}