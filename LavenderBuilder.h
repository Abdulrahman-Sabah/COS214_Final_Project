/**
 * @file LavenderBuilder.h
 * @brief Concrete builder for constructing Lavender plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef LAVENDERBUILDER_H
#define LAVENDERBUILDER_H

#include <string>
#include "PlantBuilder.h"

// Forward declaration to minimize coupling
class Plant;
class Lavender;
class PlantLifeCycleState;

/**
 * @class LavenderBuilder
 * @brief Concrete builder class for constructing Lavender objects
 * 
 * This class implements the Builder pattern to construct Lavender plants
 * step by step, allowing for flexible configuration of lavender properties.
 */
class LavenderBuilder : public PlantBuilder
{
    private:
        Plant* product;  ///< The lavender being built

    public:
        /**
         * @brief Constructor that initializes a new lavender build process
         */
        LavenderBuilder();
        
        /**
         * @brief Destructor that cleans up resources
         */
        ~LavenderBuilder() override;

        /**
         * @brief Sets the name of the lavender being built
         * @param name The name to set for the lavender
         */
        void setName(std::string name) override;
        
        /**
         * @brief Sets the care type required for the lavender
         * @param careType The care type to set
         */
        void setCareType(std::string careType) override;
        
        /**
         * @brief Sets the growing season for the lavender
         * @param season The season to set
         */
        void setSeason(std::string season) override;
        
        /**
         * @brief Sets the lifecycle state for the lavender
         * @param state The PlantLifeCycleState to set
         */
        void setLifeCycle(PlantLifeCycleState* state) override;

        /**
         * @brief Gets the constructed lavender and transfers ownership to caller
         * @return Pointer to the constructed Lavender plant
         */
        Plant* getPlant() override;
};

#endif // LAVENDERBUILDER_H