#ifndef CREATOR_H
#define CREATOR_H

#include "Plant.h"

class Creator {
protected:
    Plant* product;

    virtual Plant* factoryMethod() const = 0;
    virtual Plant* factoryMethod2() const = 0;

public:
    virtual void anOperation() = 0;
    virtual ~Creator() {}
};

#endif 
