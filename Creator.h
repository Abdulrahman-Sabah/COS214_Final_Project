#ifndef CREATOR_H
#define CREATOR_H

#include "Plant.h"

class Creator 
{
    protected:
        Plant* product;
        virtual Plant* factoryMethod() const = 0;


public:
    virtual ~Creator() {}
};

#endif 