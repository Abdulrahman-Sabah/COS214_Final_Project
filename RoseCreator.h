#ifndef ROSECREATOR_H
#define ROSECREATOR_H

#include "Creator.h"

class RoseCreator : public Creator {
public:
    RoseCreator();
    Plant* factoryMethod() const override;
};

#endif
