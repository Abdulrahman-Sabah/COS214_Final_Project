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
 * @file SucculentBuilder.h
 * @brief Concrete builder for constructing Succulent plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef SUCCULENT_BUILDER_H
#define SUCCULENT_BUILDER_H

#include <string>
#include "PlantBuilder.h"

// Forward declarations to minimize coupling
class Plant;
class Succulent;
class PlantLifeCycleState;

/**
 * @class SucculentBuilder
 * @brief Concrete builder class for constructing Succulent objects
 * 
 * This class implements the Builder pattern to construct Succulent plants
 * step by step, allowing for flexible configuration of succulent properties.
 */
class SucculentBuilder : public PlantBuilder
{
private:
    Plant* product; ///< The succulent being built

public:
    /**
     * @brief Constructor that initializes a new succulent build process
     */
    SucculentBuilder();
    
    /**
     * @brief Destructor that cleans up resources
     */
    ~SucculentBuilder() override;

    /**
     * @brief Sets the name of the succulent being built
     * @param n The name to set for the succulent
     */
    void setName(std::string n) override;
    
    /**
     * @brief Sets the care type required for the succulent
     * @param ct The care type to set
     */
    void setCareType(std::string ct) override;
    
    /**
     * @brief Sets the growing season for the succulent
     * @param s The season to set
     */
    void setSeason(std::string s) override;
    
    /**
     * @brief Sets the lifecycle state for the succulent
     * @param state The PlantLifeCycleState to set
     */
    void setLifeCycle(PlantLifeCycleState* state) override;

    /**
     * @brief Gets the constructed succulent and transfers ownership to caller
     * @return Pointer to the constructed Succulent plant
     */
    Plant* getPlant() override;
};

#endif
