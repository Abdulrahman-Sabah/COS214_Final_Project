#include "CactusCreator.h"
#include "Cactus.h"

Plant* CactusCreator::factoryMethod() const {
    return new Cactus();
}