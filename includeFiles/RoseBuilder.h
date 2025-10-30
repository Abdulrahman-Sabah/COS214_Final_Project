/**
 * @file RoseBuilder.h
 * @brief Concrete builder for constructing Rose plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef ROSE_BUILDER_H
#define ROSE_BUILDER_H

#include <string>
#include "PlantBuilder.h"

// Forward declarations to minimize coupling
class Plant;
class Rose;
class PlantLifeCycleState;

/**
 * @class RoseBuilder
 * @brief Concrete builder class for constructing Rose objects
 * 
 * This class implements the Builder pattern to construct Rose plants
 * step by step, allowing for flexible configuration of rose properties.
 */
class RoseBuilder : public PlantBuilder
{
    private:
        Plant* product; ///< The rose being built

    public:
        /**
         * @brief Constructor that initializes a new rose build process
         */
        RoseBuilder();
        
        /**
         * @brief Destructor that cleans up resources
         */
        ~RoseBuilder() override;

        /**
         * @brief Sets the name of the rose being built
         * @param n The name to set for the rose
         */
        void setName(std::string n) override;
        
        /**
         * @brief Sets the care type required for the rose
         * @param ct The care type to set
         */
        void setCareType(std::string ct) override;
        
        /**
         * @brief Sets the growing season for the rose
         * @param s The season to set
         */
        void setSeason(std::string s) override;
        
        /**
         * @brief Sets the lifecycle state for the rose
         * @param state The PlantLifeCycleState to set
         */
        void setLifeCycle(PlantLifeCycleState* state) override;
        
        /**
         * @brief Gets the constructed rose and transfers ownership to caller
         * @return Pointer to the constructed Rose plant
         */
        Plant* getPlant() override;
};

#endif