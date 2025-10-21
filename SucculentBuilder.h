#ifndef SUCCULENT_BUILDER_H
#define SUCCULENT_BUILDER_H

#include "PlantBuilder.h"
#include "Succulent.h"

class SucculentBuilder : public PlantBuilder
{
    private:
        Succulent* succulent;
    
    public:
        SucculentBuilder();
        ~SucculentBuilder();
        void setName(string n) override;
        void setCareType(string ct) override;
        void setSeason(string s) override;
        void setLifeCycle(PlantLifeCycleState* state) override;
        Plant* getPlant() override; //getResult
};

#endif