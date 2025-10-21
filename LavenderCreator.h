#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H

#include "Creator.h"

class LavenderCreator : public Creator {
public:
    virtual Plant* factoryMethod() const;
};

#endif 
