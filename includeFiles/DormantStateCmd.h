#ifndef DORMANT_STATE_CMD_H
#define DORMANT_STATE_CMD_H

#include "Commands.h"
#include <string>

class DormantStateCmd : public Commands {
public:
    DormantStateCmd();
    virtual ~DormantStateCmd() {}

     std::string name() ;
    void execute(Plant* plant);

private:
    std::string m_label;
};

#endif
