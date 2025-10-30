#ifndef SELLING_STATE_CMD_H
#define SELLING_STATE_CMD_H

#include "Commands.h"
#include <string>

class SellingStateCmd : public Commands {
public:
    SellingStateCmd();
    virtual ~SellingStateCmd() {}

     std::string name() ;
    void execute(Plant* plant);

private:
    std::string m_label;
};

#endif
