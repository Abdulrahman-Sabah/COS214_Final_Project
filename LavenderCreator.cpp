#include "LavenderCreator.h"
#include "Lavender.h"

Plant* LavenderCreator::factoryMethod() const {
    return new Lavender();
}