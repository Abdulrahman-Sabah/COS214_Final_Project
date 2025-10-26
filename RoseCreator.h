#ifndef ROSECREATOR_H
#define ROSECREATOR_H

#include "Creator.h"

class RoseCreator : public Creator 
{
    public:
        RoseCreator() = default;
        Plant* factoryMethod() const override;
};

#endif 
