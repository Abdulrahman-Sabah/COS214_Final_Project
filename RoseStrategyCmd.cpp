#include "RoseStrategyCmd.h"
#include "Plant.h"
#include "RoseCare.h"

RoseStrategyCmd::RoseStrategyCmd() : m_label("RoseStrategy") {}

std::string RoseStrategyCmd::name() { return m_label; }

void RoseStrategyCmd::execute(Plant* plant) {
    if (!plant) return;

    // Option A (matches your style used in DeadStateCmd):
    plant->setCareStrategy(new RoseCare());

    // If you switched to smart pointers in Plant:
    // plant->setCareStrategy(std::make_unique<RoseCare>());
}
