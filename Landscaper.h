#ifndef LANDSCAPER_H
#define LANDSCAPER_H
#include "Handler.h"
class Landscaper : public Handler{
public:
    void handleRequest(Command* r) override;
};

#endif