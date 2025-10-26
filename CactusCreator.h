#ifndef CACTUSCREATOR_H
#define CACTUSCREATOR_H

#include "Creator.h"

class CactusCreator : public Creator 
{
public:
    CactusCreator() = default;
    Plant* factoryMethod() const override; 
};

#endif