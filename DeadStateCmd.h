#ifndef DEAD_STATE_CMD_H
#define DEAD_STATE_CMD_H

#include "Commands.h"
#include <string>

class DeadStateCmd : public Commands {
public:
    DeadStateCmd();
    virtual ~DeadStateCmd() {}

     std::string name() ;
    void execute(Plant* plant);

private:
    std::string m_label;
};

#endif
