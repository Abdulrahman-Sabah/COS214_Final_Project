#include "MatureStateCmd.h"
#include "Plant.h"
#include "MatureState.h"

MatureStateCmd::MatureStateCmd() : m_label("MatureState") {}

std::string MatureStateCmd::name() {
    return m_label;
}

void MatureStateCmd::execute(Plant* plant) {
    if (!plant) return;
    plant->setLifeCycle(new MatureState());
}