#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Plant.h"

class PlantIterator {
 public:
  virtual ~PlantIterator() {}

  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() = 0;
  virtual Plant* current() = 0;
};

#endif
