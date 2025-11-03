#ifndef COMMANDFRAMEWORK_CPP_DOC
/**
 * @file commandFramework.cpp
 * @brief Tests for command objects and lifecycle commands.
 * @details Verifies strategy/command execution and safe handling of null plant
 * pointers.
 * @author Git it done group members
 * @date 10-2025
 */
#define COMMANDFRAMEWORK_CPP_DOC
#endif

#include "doctest.h"

#include <functional>
#include <iostream>
#include <sstream>
#include <string>

#include "Cactus.h"
#include "CactusStrategyCmd.h"
#include "DeadStateCmd.h"
#include "DormantStateCmd.h"
#include "GrowingStateCmd.h"
#include "Lavender.h"
#include "LavenderStrategyCmd.h"
#include "MatureStateCmd.h"
#include "Plant.h"
#include "PlantLifeCycleState.h"
#include "Rose.h"
#include "RoseStrategyCmd.h"
#include "SeedlingStateCmd.h"
#include "SellingStateCmd.h"

TEST_CASE("CactusStrategyCmd applies cactus care") {
  Cactus c;
  CactusStrategyCmd cmd;
  CHECK(c.getCareStrategy() != nullptr);
  CHECK(cmd.name() == "CactusStrategy");
  REQUIRE_NOTHROW(cmd.execute(&c));
}

TEST_CASE("LavenderStrategyCmd applies lavender care") {
  Lavender l;
  LavenderStrategyCmd cmd;
  CHECK(l.getCareStrategy() != nullptr);
  CHECK(cmd.name() == "LavenderStrategy");
  REQUIRE_NOTHROW(cmd.execute(&l));
}

TEST_CASE("RoseStrategyCmd applies rose care") {
  Rose r;
  RoseStrategyCmd cmd;
  CHECK(r.getCareStrategy() != nullptr);
  CHECK(cmd.name() == "RoseStrategy");
  REQUIRE_NOTHROW(cmd.execute(&r));
}

TEST_CASE("SeedlingStateCmd transitions plant to Seedling state") {
  Rose r;
  SeedlingStateCmd cmd;
  CHECK(r.getLifeCycle() != nullptr);
  cmd.execute(&r);

  REQUIRE(r.getLifeCycle() != nullptr);
  CHECK(r.getLifeCycle()->name() == "Seedling");
}

TEST_CASE("GrowingStateCmd transitions plant to Growing state") {
  Cactus c;
  GrowingStateCmd cmd;
  cmd.execute(&c);
  CHECK(cmd.name() == "GrowingState");

  REQUIRE(c.getLifeCycle() != nullptr);
  CHECK(c.getLifeCycle()->name() == "Growing");
}

TEST_CASE("DormantStateCmd transitions plant to Dormant state") {
  Lavender l;
  DormantStateCmd cmd;
  cmd.execute(&l);

  CHECK(cmd.name() == "DormantState");
  REQUIRE(l.getLifeCycle() != nullptr);
  CHECK(l.getLifeCycle()->name() == "Dormant");
}

TEST_CASE("MatureStateCmd transitions plant to Mature state") {
  Rose r;
  MatureStateCmd cmd;
  cmd.execute(&r);

  CHECK(cmd.name() == "MatureState");
  REQUIRE(r.getLifeCycle() != nullptr);
  CHECK(r.getLifeCycle()->name() == "Mature");
}

TEST_CASE("SellingStateCmd transitions plant to Selling state") {
  Cactus c;
  SellingStateCmd cmd;
  cmd.execute(&c);

  CHECK(cmd.name() == "SellingState");
  REQUIRE(c.getLifeCycle() != nullptr);
  CHECK(c.getLifeCycle()->name() == "Selling");
}

TEST_CASE("DeadStateCmd transitions plant to Dead state") {
  Lavender l;
  DeadStateCmd cmd;
  cmd.execute(&l);

  CHECK(cmd.name() == "DeadState");
  REQUIRE(l.getLifeCycle() != nullptr);
  CHECK(l.getLifeCycle()->name() == "Dead");
}

TEST_CASE("Command chaining - multiple state transitions") {
  Rose r;
  SeedlingStateCmd s;
  GrowingStateCmd g;
  MatureStateCmd m;

  CHECK(r.getLifeCycle() != nullptr);
  CHECK(s.name() == "SeedlingState");
  CHECK(g.name() == "GrowingState");
  CHECK(m.name() == "MatureState");

  s.execute(&r);
  CHECK(r.getLifeCycle()->name() == "Seedling");

  g.execute(&r);
  CHECK(r.getLifeCycle()->name() == "Growing");

  m.execute(&r);
  CHECK(r.getLifeCycle()->name() == "Mature");
}

TEST_CASE("Command execution on null plant pointer is safe") {
  SeedlingStateCmd cmd;
  CHECK(cmd.name() == "SeedlingState");
  REQUIRE_NOTHROW(cmd.execute(nullptr));
}