#include "RoseCreator.h"
#include "Rose.h"

Plant* RoseCreator::factoryMethod() const {
    return new Rose();
}