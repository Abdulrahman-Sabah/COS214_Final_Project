#include "PlantDecorations.h"

PlantDecorations::PlantDecorations(Plant* item) : wrappedPlant(item) {}

PlantDecorations::~PlantDecorations() {
    delete wrappedPlant;
}