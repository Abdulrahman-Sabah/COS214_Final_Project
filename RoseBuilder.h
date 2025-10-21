#ifndef ROSE_BUILDER_H
#define ROSE_BUILDER_H

#include "PlantBuilder.h"

class RoseBuilder : public PlantBuilder
{
    private:
        Plant* rose;

    public:
        RoseBuilder();
        void setName(std::string n = "") override;
        void setCareType(std::string c = "") override;
        void setSeason(std::string s = "") override;
        void setLifeCycle(PlantLifeCycleState* state) override;
        void setCareStrategy(CareStrategy* strategy) override;
        Plant* getPlant() override;
        ~RoseBuilder();
};

#endif