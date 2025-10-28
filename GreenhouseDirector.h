/**
 * @file GreenhouseDirector.h
 * @brief Director class for the Builder pattern in plant construction
 * @author COS214 Students
 * @date 2024
 */

#ifndef GREENHOUSE_DIRECTOR_H
#define GREENHOUSE_DIRECTOR_H

#include "PlantBuilder.h"

/**
 * @class GreenhouseDirector
 * @brief Director class that orchestrates the plant building process
 * 
 * This class implements the Director role in the Builder pattern,
 * providing a high-level interface for constructing plants with
 * predefined configurations using various PlantBuilder implementations.
 */
class GreenhouseDirector
{
    private:
        PlantBuilder* builder; ///< The builder used to construct plants

    public:
        /**
         * @brief Constructor that sets the builder to use
         * @param b Pointer to the PlantBuilder to use for construction
         */
        GreenhouseDirector(PlantBuilder* b);
        
        /**
         * @brief Constructs a plant using the configured builder
         * 
         * This method defines the steps to construct a plant with
         * default configurations for greenhouse production.
         */
        void construct();
};

#endif