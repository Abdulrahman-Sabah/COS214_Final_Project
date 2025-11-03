#ifndef OBSERVERFRAMEWORK_CPP_DOC
/**
 * @file observerFramework.cpp
 * @brief Unit Tests for Observer-based care scheduling and notifications.
 * @author Git it done group members
 * @date 10-2025
 */
#define OBSERVERFRAMEWORK_CPP_DOC
#endif

#include "doctest.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>

#include "CareScheduleObserver.h"
#include "GrowingState.h"
#include "Plant.h"
#include "PlantLifeCycleState.h"
#include "Rose.h"
#include "RoseCare.h"

static std::string capture_stdout_ss(const std::function<void()> &fn) {
  std::ostringstream oss;
  std::streambuf *old_buf = std::cout.rdbuf(oss.rdbuf());
  fn();
  std::cout.flush();
  std::cout.rdbuf(old_buf);
  return oss.str();
}

static std::string to_lower(const std::string &s) {
  std::string out(s);
  std::transform(out.begin(), out.end(), out.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return out;
}