#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H

#include "Creator.h"

class LavenderCreator : public Creator 
{
    public:
        LavenderCreator() = default;
        Plant* factoryMethod() const override;
};

#endif