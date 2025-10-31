#ifndef ROSE_BUILDER_H
#define ROSE_BUILDER_H

#include <string>

#include "PlantBuilder.h"

// Forward declarations to minimize coupling
class Plant;
class Rose;
class PlantLifeCycleState;

class RoseBuilder : public PlantBuilder {
 private:
  Plant* product;  // the plant being built (will be a Rose)

 public:
  RoseBuilder();
  ~RoseBuilder() override;

  // NOTE: By-value std::string parameters to match your ABI/linker traces
  void setName(std::string n) override;
  void setCareType(std::string ct) override;
  void setSeason(std::string s) override;
  void setLifeCycle(PlantLifeCycleState* state) override;

  // Transfer ownership of the built plant to the caller
  Plant* getPlant() override;
};

#endif