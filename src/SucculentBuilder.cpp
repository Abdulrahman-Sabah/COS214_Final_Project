
#include "SucculentBuilder.h"
//#include "Succulent.h"              // concrete Plant subtype
#include "Plant.h"
#include "PlantLifeCycleState.h"

#include <utility> // std::move

namespace {
// Lazily allocate the product the first time it’s needed
inline void ensureAllocated(Plant *&p) {
  // if (!p) {
  //     p = new Succulent(); // adjust ctor args if your Succulent needs them
  // }
}
} // namespace

SucculentBuilder::SucculentBuilder() : product(nullptr) {}

SucculentBuilder::~SucculentBuilder() {
  delete product; // safe if nullptr
  product = nullptr;
}

void SucculentBuilder::setName(std::string n) {
  ensureAllocated(product);
  product->setName(std::move(n));
}

void SucculentBuilder::setCareType(std::string ct) {
  ensureAllocated(product);
  product->setCareType(std::move(ct));
}

void SucculentBuilder::setSeason(std::string s) {
  ensureAllocated(product);
  product->setSeason(std::move(s));
}

void SucculentBuilder::setLifeCycle(PlantLifeCycleState *state) {
  ensureAllocated(product);
  product->setLifeCycle(state);
}

Plant *SucculentBuilder::getPlant() {
  ensureAllocated(product);
  Plant *out = product; // transfer ownership
  product = nullptr;    // builder relinquishes ownership
  return out;
}
