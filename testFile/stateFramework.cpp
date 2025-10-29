#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "DeadState.h"
#include "DormantState.h"
#include "GrowingState.h"
#include "MatureState.h"
#include "Plant.h"
#include "PlantLifeCycleState.h"
#include "Rose.h"
#include "SeedlingState.h"
#include "SellingState.h"

TEST_CASE("Initial state") {
  Rose *r = new Rose();
  REQUIRE(r->getLifeCycle() != nullptr);
  CHECK(r->getLifeCycle()->name() == "Seedling");
  delete r;
}

TEST_CASE("functions for Seedling state") {
  Rose *r = new Rose();
  r->getLifeCycle()->advance(r);
  CHECK(r->getLifeCycle() != nullptr);
  CHECK(r->getLifeCycle()->name() == "Growing");
  delete r;
}

TEST_CASE("functions for Growing state") {
  Rose *r = new Rose();
  r->setLifeCycle(new GrowingState());
  r->getLifeCycle()->advance(r);
  CHECK(r->getLifeCycle() != nullptr);
  CHECK(r->getLifeCycle()->name() == "Dormant");
  delete r;
}

TEST_CASE("functions for Dormant state, when growing is true or false") {
  // Growing boolean variable is true
  {
    Rose *r = new Rose();
    DormantState *d = new DormantState();
    d->setGrowing(true);
    r->setLifeCycle(d);
    r->getLifeCycle()->advance(r);
    CHECK(r->getLifeCycle()->name() == "Growing");
    delete r;
  }
  // Growing boolean variable is false
  {
    Rose *r = new Rose();
    DormantState *d = new DormantState();
    d->setGrowing(false);
    r->setLifeCycle(d);
    r->getLifeCycle()->advance(r);
    CHECK(r->getLifeCycle()->name() == "Mature");
    delete r;
  }
}

TEST_CASE("functions for Mature state") {
  Rose *r = new Rose();
  r->setLifeCycle(new MatureState());
  r->getLifeCycle()->advance(r);
  CHECK(r->getLifeCycle()->name() == "Selling");
  delete r;
}

TEST_CASE("We handle the Selling state advance function properly") {
  Rose *r = new Rose();
  r->setLifeCycle(new SellingState());
  r->getLifeCycle()->advance(r);
  CHECK(r->getLifeCycle() != nullptr);
  delete r;
}

TEST_CASE("We handle the Dead state advance function properly") {
  Rose *r = new Rose();
  r->setLifeCycle(new DeadState());
  r->getLifeCycle()->setDead(true);
  r->getLifeCycle()->advance(r);
  CHECK(r->getLifeCycle()->name() == "Dead");
  CHECK(r->getLifeCycle()->isDead() == true);
  delete r;
}