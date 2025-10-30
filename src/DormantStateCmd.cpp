#include "DormantStateCmd.h"
#include "Plant.h"
#include "DormantState.h"

DormantStateCmd::DormantStateCmd() : m_label("DormantState") {}

std::string DormantStateCmd::name()  {
    return m_label;
}

void DormantStateCmd::execute(Plant* plant) {
    if (!plant) return;
    plant->setLifeCycle(new DormantState());
}