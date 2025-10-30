#ifndef SEEDLING_STATE_CMD_H
#define SEEDLING_STATE_CMD_H

#include "Commands.h"
#include <string>

class SeedlingStateCmd : public Commands {
public:
    SeedlingStateCmd();
    virtual ~SeedlingStateCmd() {}

    std::string name() ;
    void execute(Plant* plant);

private:
    std::string m_label;
};

#endif