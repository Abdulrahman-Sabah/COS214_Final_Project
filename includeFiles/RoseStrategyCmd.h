#ifndef ROSE_STRATEGY_CMD_H
#define ROSE_STRATEGY_CMD_H

#include "Commands.h"
#include <string>

class RoseStrategyCmd : public Commands {
public:
    RoseStrategyCmd();
    ~RoseStrategyCmd() override = default;

    std::string name() override;
    void execute(Plant* plant) override;

private:
    std::string m_label;
};

#endif
