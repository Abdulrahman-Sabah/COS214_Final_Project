#ifndef CACTUSCREATOR_H
#define CACTUSCREATOR_H

#include "Creator.h"

class CactusCreator : public Creator {
public:
    virtual Plant* factoryMethod() const;
};

#endif 
