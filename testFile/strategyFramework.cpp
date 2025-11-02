#ifndef STRATEGYFRAMEWORK_CPP_DOC
/**
 * @file strategyFramework.cpp
 * @brief Tests for CareStrategy implementations and their output.
 */
#define STRATEGYFRAMEWORK_CPP_DOC
#endif

#include "Cactus.h"
#include "CactusCare.h"
#include "Lavender.h"
#include "LavenderCare.h"
#include "Plant.h"
#include "Rose.h"
#include "RoseCare.h"
#include "doctest.h"
#include <functional>
#include <iostream>
#include <sstream>
#include <string>

static std::string capture_stdout_ss(const std::function<void()> &fn) {
  std::ostringstream oss;
  std::streambuf *old_buf = std::cout.rdbuf(oss.rdbuf());
  fn();
  std::cout.flush();
  std::cout.rdbuf(old_buf);
  return oss.str();
}

TEST_CASE("RoseCare tests") {
  Rose r;
  RoseCare care;
  std::string out = capture_stdout_ss([&] { care.applyCare(&r); });
  REQUIRE(!out.empty());
  REQUIRE(r.getName() != "");
  CHECK(out.find(r.getName()) != std::string::npos);
  CHECK(out.find(
            "is being watered regularly to keep the soil consistently moist") !=
        std::string::npos);
  CHECK(out.find("is now being pruned to remove dead or weak stems") !=
        std::string::npos);
  CHECK(out.find("is being fertilized for best blooms") != std::string::npos);
}

TEST_CASE("LavenderCare tests") {
  Lavender l;
  LavenderCare care;
  std::string out = capture_stdout_ss([&] { care.applyCare(&l); });
  REQUIRE(!out.empty());
  REQUIRE(l.getName() != "");
  CHECK(out.find(l.getName()) != std::string::npos);
  CHECK(out.find("is being watered regularly, keeping the soil consistently "
                 "moist but not soggy") != std::string::npos);
  CHECK(out.find("is now being placed in full sun to partial shade, depending "
                 "on the variety") != std::string::npos);
  CHECK(out.find("is being potted in fertile, well-drained soil enriched with "
                 "organic matter") != std::string::npos);
}

TEST_CASE("CactusCare tests") {
  Cactus c;
  CactusCare care;
  std::string out = capture_stdout_ss([&] { care.applyCare(&c); });
  REQUIRE(!out.empty());
  REQUIRE(c.getName() != "");
  CHECK(out.find(c.getName()) != std::string::npos);
  CHECK(out.find("is being watered as soon as the soil is completely dry") !=
        std::string::npos);
  CHECK(out.find("is now being placed in direct sunlight") !=
        std::string::npos);
  CHECK(out.find("is being potted in a cactus-specific soil mix for optimal "
                 "drainage") != std::string::npos);
}