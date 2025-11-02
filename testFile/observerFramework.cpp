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

TEST_CASE("CareSchedulerObserver receives state, lifecycle, season and strategy notifications") {
    Rose* r = new Rose();
    CareSchedulerObserver obs;
    r->attach(&obs);
    CHECK(r->getName() != "");
    CHECK(r->getLifeCycle() != nullptr);
    CHECK(r->getCareStrategy() != nullptr);


    // 1) state change
    std::string out1 = capture_stdout_ss([&]{ r->setStateText("Blooming"); });
    std::string o1 = to_lower(out1);
    bool works = (o1.find("care scheduler") != std::string::npos) || (o1.find("carescheduler") != std::string::npos)
            | (o1.find("[carescheduler]") != std::string::npos) || (o1.find("care") != std::string::npos);
    CHECK(works);
    CHECK(o1.find(to_lower(r->getName())) != std::string::npos);
    CHECK(o1.find("blooming") != std::string::npos);

    // 2) lifecycle change
    std::string out2 = capture_stdout_ss([&]{ r->setLifeCycle(new GrowingState()); });
    std::string o2 = to_lower(out2);
    bool lifecycle_ok = (o2.find("life cycle changed") != std::string::npos)
                      || (o2.find("life cycle changed for") != std::string::npos)
                      || (o2.find("life cycle") != std::string::npos);
    CHECK(lifecycle_ok);
    CHECK(o2.find(to_lower(r->getName())) != std::string::npos);

    // 3) season change
    std::string out3 = capture_stdout_ss([&]{ r->setSeason("Winter"); });
    std::string o3 = to_lower(out3);
    CHECK(o3.find("season changed") != std::string::npos);
    CHECK(o3.find("winter") != std::string::npos);
    CHECK(o3.find(to_lower(r->getName())) != std::string::npos);

    // 4) care strategy change
    std::string out4 = capture_stdout_ss([&]{ r->setCareStrategy(new RoseCare()); });
    std::string o4 = to_lower(out4);
    bool strategy_ok = (o4.find("care strategy") != std::string::npos)
                    || (o4.find("care strategy updated") != std::string::npos);
    CHECK(strategy_ok);
    CHECK(o4.find(to_lower(r->getName())) != std::string::npos);

    r->detach(&obs);
    delete r;
}
