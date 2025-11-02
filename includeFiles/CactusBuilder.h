// #ifndef SUCCULENT_BUILDER_H
// #define SUCCULENT_BUILDER_H

// #include "PlantBuilder.h"
// #include "SucculentCare.h"

// class SucculentBuilder : public PlantBuilder
// {
//     private:
//         SucculentCare* succulent;

//     public:
//         SucculentBuilder();
//         ~SucculentBuilder();
//         void setName(string n) override;
//         void setCareType(string ct) override;
//         void setSeason(string s) override;
//         void setLifeCycle(PlantLifeCycleState* state) override;
//         Plant* getPlant() override; //getResult
// };

// #endif

/**
 * @file CactusBuilder.h
 * @brief Concrete builder for constructing Cactus plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef CACTUS_BUILDER_H
#define CACTUS_BUILDER_H

#include "PlantBuilder.h"
#include <string>

// Forward declarations to minimize coupling
class Plant;
class Cactus;
class PlantLifeCycleState;

/**
 * @class CactusBuilder
 * @brief Concrete builder class for constructing Cactus objects
 *
 * This class implements the Builder pattern to construct Cactus plants
 * step by step, allowing for flexible configuration of cactus properties.
 */
class CactusBuilder : public PlantBuilder {
private:
  Plant *product; ///< The cactus being built

public:
  /**
   * @brief Constructor that initializes a new cactus build process
   */
  CactusBuilder();

  /**
   * @brief Destructor that cleans up resources
   */
  ~CactusBuilder() override;

  /**
   * @brief Sets the name of the cactus being built
   * @param n The name to set for the cactus
   */
  void setName(std::string n) override;

  /**
   * @brief Sets the care type required for the cactus
   * @param ct The care type to set
   */
  void setCareType(std::string ct) override;

  /**
   * @brief Sets the growing season for the cactus
   * @param s The season to set
   */
  void setSeason(std::string s) override;

  /**
   * @brief Sets the lifecycle state for the cactus
   * @param state The PlantLifeCycleState to set
   */
  void setLifeCycle(PlantLifeCycleState *state) override;

  /**
   * @brief Gets the constructed cactus and transfers ownership to caller
   * @return Pointer to the constructed Cactus plant
   */
  Plant *getPlant() override;
};

#endif
