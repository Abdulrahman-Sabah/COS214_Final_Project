#ifndef PLANTDECORATIONS_CPP_DOC
/**
 * @file PlantDecorations.cpp
 * @brief Implementations for decorator base behaviour wrapping Plant objects.
 * @author Git it done group members
 * @date 10-2025
 */
#define PLANTDECORATIONS_CPP_DOC
#endif

#include "PlantDecorations.h"

PlantDecorations::PlantDecorations(Plant *item) : wrappedPlant(item) {}

PlantDecorations::~PlantDecorations() { delete wrappedPlant; }