/**
 * @file PlantBuilder.h
 * @brief Abstract builder interface for the Builder pattern implementation
 * @author COS214 Students
 * @date 2024
 */

#ifndef PLANT_BUILDER_H
#define PLANT_BUILDER_H

#include "Plant.h"
#include "PlantLifeCycleState.h"
#include <string>

/**
 * @class PlantBuilder
 * @brief Abstract builder class for constructing Plant objects step by step
 *
 * This class defines the interface for the Builder pattern, allowing different
 * concrete builders to construct various types of plants with different
 * configurations.
 */
class PlantBuilder {
public:
  /**
   * @brief Sets the name of the plant being built
   * @param n The name to set (default: empty string)
   */
  virtual void setName(std::string n = "") = 0;

  /**
   * @brief Sets the care type required for the plant
   * @param c The care type to set (default: empty string)
   */
  virtual void setCareType(std::string c = "") = 0;

  /**
   * @brief Sets the growing season for the plant
   * @param s The season to set (default: empty string)
   */
  virtual void setSeason(std::string s = "") = 0;

  /**
   * @brief Sets the lifecycle state for the plant
   * @param state The PlantLifeCycleState to set
   */
  virtual void setLifeCycle(PlantLifeCycleState *state) = 0;

  /**
   * @brief Gets the constructed plant object
   * @return A pointer to the constructed Plant
   */
  virtual Plant *getPlant() = 0;

  /**
   * @brief Virtual destructor for proper cleanup
   */
  virtual ~PlantBuilder() = default;
};

#endif