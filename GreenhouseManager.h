#ifndef GREENHOUSEMANAGER_H
#define GREENHOUSEMANAGER_H
#include "Handler.h"
class GreenhouseManager : public Handler{
public:
    void handleRequest(Commands* r) override;
};

#endif