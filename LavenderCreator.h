#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H

#include "Creator.h"

class LavenderCreator : public Creator 
{
public:
    LavenderCreator();
    Plant* factoryMethod() const;
};

#endif