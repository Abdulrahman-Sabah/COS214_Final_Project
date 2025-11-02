#ifndef PLANT_BUILDER_H
#define PLANT_BUILDER_H

/**
 * @file PlantBuilder.h
 * @brief Builder interface for constructing Plant instances step-by-step.
 */

#include <string>

#include "Plant.h"
#include "PlantLifeCycleState.h"

class PlantBuilder {
public:
  PlantBuilder() = default;

  /** @brief Set the plant name in the builder */
  virtual void setName(std::string n = "") = 0;

  /** @brief Set the care type in the builder */
  virtual void setCareType(std::string c = "") = 0;

  /** @brief Set the season attribute in the builder */
  virtual void setSeason(std::string s = "") = 0;

  /** @brief Set the initial lifecycle state for the plant */
  virtual void setLifeCycle(PlantLifeCycleState *state) = 0;

  /** @brief Retrieve the built Plant instance */
  virtual Plant *getPlant() = 0;

  virtual ~PlantBuilder() = default;
};

#endif