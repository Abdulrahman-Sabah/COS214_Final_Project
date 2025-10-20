#ifndef GREENHOUSEMANAGER_H
#define GREENHOUSEMANAGER_H
#include "Handler.h"
class GreenhouseManager : public Handler{
    void handleRequest(Command* r);
};

#endif