#ifndef APPLYFERTILIZER_H
#define APPLYFERTILIZER_H

#include "Commands.h"
#include <string>

class ApplyFertilizer : public Commands {
private:
  std::string plantId;

public:
  ApplyFertilizer(const std::string &id);
  std::string getType() const override;
  std::string getData() const override;
};

#endif
