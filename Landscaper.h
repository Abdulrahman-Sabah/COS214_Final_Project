#ifndef LANDSCAPER_H
#define LANDSCAPER_H
#include "Handler.h"
class Landscaper : public Handler{
    void handleRequest(Command* r);
};

#endif