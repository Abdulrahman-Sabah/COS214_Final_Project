#ifndef LAVENDERBUILDER_H
#define LAVENDERBUILDER_H

#include <string>
#include "PlantBuilder.h"

// Forward declaration to minimize coupling
class Plant;
class Lavender;
class PlantLifeCycleState;

class LavenderBuilder : public PlantBuilder
{
    private:
        Plant* product;  // the plant being built (will be a Lavender)

    public:
        LavenderBuilder();
        ~LavenderBuilder() override;

        // NOTE: By-value std::string parameters to match your ABI/linker traces
        void setName(std::string name) override;
        void setCareType(std::string careType) override;
        void setSeason(std::string season) override;
        void setLifeCycle(PlantLifeCycleState* state) override;

        // Transfer ownership of the built plant to the caller
        Plant* getPlant() override;
};

#endif // LAVENDERBUILDER_H