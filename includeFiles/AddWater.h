#ifndef ADDWATER_H
#define ADDWATER_H

#include "Commands.h"

class AddWater : public Commands {
private:
  std::string plantId;

public:
  AddWater(const std::string &id);
  std::string getType() const override;
  std::string getData() const override;
};

#endif
