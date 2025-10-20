#ifndef ROSECREATOR_H
#define ROSECREATOR_H

#include "Creator.h"

class RoseCreator : public Creator {
public:
    virtual Plant* factoryMethod() const;
};

#endif 
