#ifndef SCHEDULEDELIVERY_H
#define SCHEDULEDELIVERY_H

#include "Commands.h"
#include <string>

class ScheduleDelivery : public Commands {
private:
  std::string orderId;

public:
  explicit ScheduleDelivery(const std::string &id);
  std::string getType() const override;
  std::string getData() const override;
};

#endif
