#include "DeadStateCmd.h"
#include "Plant.h"
#include "DeadState.h"

DeadStateCmd::DeadStateCmd() : m_label("DeadState") {}

std::string DeadStateCmd::name() {
    return m_label;
}

void DeadStateCmd::execute(Plant* plant) {
    if (!plant) return;
    plant->setLifeCycle(new DeadState());
}