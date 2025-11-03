
#ifndef DECORATORFRAMEWORK_CPP_DOC
/**
 * @file decoratorFramework.cpp
 * @brief Unit tests for the Decorator pattern (wrapping plants with extras).
 * @author Git it done group members
 * @date 10-2025
 */
#define DECORATORFRAMEWORK_CPP_DOC
#endif

#include "doctest.h"

#include <functional>
#include <iostream>
#include <sstream>
#include <string>

#include "CardDecorator.h"
#include "Plant.h"
#include "PlantDecorations.h"
#include "PotDecorator.h"
#include "Rose.h"
#include "WrapDecorator.h"

static std::string capture_stdout(const std::function<void()> &fn) {
  std::ostringstream oss;
  std::streambuf *old_buf = std::cout.rdbuf(oss.rdbuf());
  fn();
  std::cout.flush();
  std::cout.rdbuf(old_buf);
  return oss.str();
}

TEST_CASE("Rose default constructor initializes correctly") {
  Rose r;

  CHECK(r.getName() == "Rose");
  CHECK(r.getCareType() == "Moderate");
  CHECK(r.getStateText() == "Seedling");
  CHECK(r.getSeason() == "Spring");
  CHECK(r.getCareStrategy() != nullptr);
  CHECK(r.getLifeCycle() != nullptr);
}

TEST_CASE("Rose description is correct") {
  Rose r;
  std::string expected = "Rose (Rosa): a fragrant and colorful flowering plant "
                         "symbolizing love and beauty.";

  CHECK(r.description() == expected);
}

TEST_CASE("Rose base price is correct") {
  Rose r;

  CHECK(r.price() == doctest::Approx(79.99));
}

TEST_CASE("Rose clone creates independent copy") {
  Rose r;
  Plant *cloned = r.clone();

  REQUIRE(cloned != nullptr);
  CHECK(cloned != &r);
  CHECK(cloned->getName() == r.getName());
  CHECK(cloned->getCareType() == r.getCareType());

  r.setName("Modified Rose");
  CHECK(cloned->getName() != "Modified Rose");

  delete cloned;
}

TEST_CASE("Rose setName changes name") {
  Rose r;
  r.setName("Red Rose");

  CHECK(r.getName() == "Red Rose");
}

TEST_CASE("Rose setCareType changes care type") {
  Rose r;
  r.setCareType("High");

  CHECK(r.getCareType() == "High");
}

TEST_CASE("Rose setStateText changes state") {
  Rose r;
  r.setStateText("Flowering");

  CHECK(r.getStateText() == "Flowering");
}

TEST_CASE("Rose setSeason changes season") {
  Rose r;
  r.setSeason("Summer");

  CHECK(r.getSeason() == "Summer");
}

TEST_CASE("Rose setPrice changes price") {
  Rose r;
  REQUIRE_NOTHROW(r.setPrice(99.99));
  CHECK(r.price() == doctest::Approx(79.99));
}

TEST_CASE("CardDecorator constructor works") {
  Plant *rose = new Rose();
  CardDecorator *decorated = new CardDecorator(rose, "Happy Birthday!", 5.99);

  REQUIRE(decorated != nullptr);
  delete decorated;
}

TEST_CASE("CardDecorator description includes card message") {
  Plant *rose = new Rose();
  CardDecorator *decorated = new CardDecorator(rose, "Get well soon", 4.50);

  std::string desc = decorated->description();
  CHECK(desc.find("Rose (Rosa)") != std::string::npos);
  CHECK(desc.find("with card: \"Get well soon\"") != std::string::npos);

  delete decorated;
}
