#include "doctest.h"

#include <string>
#include <sstream>
#include <functional>
#include <iostream>
#include <algorithm>

#include "Plant.h"
#include "Rose.h"
#include "PlantLifeCycleState.h"
#include "GrowingState.h"
#include "RoseCare.h"
#include "CareScheduleObserver.h" 

static std::string capture_stdout_ss(const std::function<void()>& fn) {
    std::ostringstream oss;
    std::streambuf* old_buf = std::cout.rdbuf(oss.rdbuf());
    fn();
    std::cout.flush();
    std::cout.rdbuf(old_buf);
    return oss.str();
}

static std::string to_lower(const std::string &s) {
    std::string out(s);
    std::transform(out.begin(), out.end(), out.begin(), [](unsigned char c){ return std::tolower(c); });
    return out;
}