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


#ifndef CACTUS_BUILDER_H
#define CACTUS_BUILDER_H

#include <string>
#include "PlantBuilder.h"

// Forward declarations to minimize coupling
class Plant;
class Cactus;
class PlantLifeCycleState;

class CactusBuilder : public PlantBuilder
{
    private:
        Plant* product; // the plant being built (will be a Cactus)

    public:
        CactusBuilder();
        ~CactusBuilder() override;

        // NOTE: By-value std::string parameters to match your ABI/linker traces
        void setName(std::string n) override;
        void setCareType(std::string ct) override;
        void setSeason(std::string s) override;
        void setLifeCycle(PlantLifeCycleState* state) override;

        // Transfer ownership of the built plant to the caller
        Plant* getPlant() override;
};

#endif
