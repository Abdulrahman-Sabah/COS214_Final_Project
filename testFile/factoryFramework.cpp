#ifndef FACTORYFRAMEWORK_CPP_DOC
/**
 * @file factoryFramework.cpp
 * @brief Tests for the Factory Method creators producing specific plants.
 */
#define FACTORYFRAMEWORK_CPP_DOC
#endif

#include "Cactus.h"
#include "CactusCreator.h"
#include "Lavender.h"
#include "LavenderCreator.h"
#include "Plant.h"
#include "Rose.h"
#include "RoseCreator.h"
#include "doctest.h"

TEST_CASE("Rose Product") {
  Rose r;
  bool check = (r.getName() == "Rose");
  CHECK(check);
  CHECK(r.description() == "Rose (Rosa): a fragrant and colorful flowering "
                           "plant symbolizing love and beauty.");
  CHECK(r.price() > 0.0);
}

TEST_CASE("Lavender") {
  Lavender l;
  bool check = (l.getName() == "Lavender");
  CHECK(check);
  CHECK(l.description() == "Lavender (Lavandula): a fragrant purple herb often "
                           "used for decoration and scent.");
  CHECK(l.price() > 0.0);
}

TEST_CASE("Cactus") {
  Cactus c;
  bool check = (c.getName() == "Cactus");
  CHECK(check);
  CHECK(c.description() == "Cactus (Cactaceae): a hardy, water-efficient plant "
                           "adapted to dry climates.");
  CHECK(c.price() > 0.0);
}

TEST_CASE("RoseCreator makes a Rose") {
  RoseCreator creator;
  Plant *p = creator.factoryMethod();
  CHECK(p != nullptr);
  CHECK(dynamic_cast<Rose *>(p) != nullptr);
  delete p;
}

TEST_CASE("CactusCreator makes a Cactus") {
  CactusCreator creator;
  Plant *p = creator.factoryMethod();
  CHECK(p != nullptr);
  CHECK(dynamic_cast<Cactus *>(p) != nullptr);
  delete p;
}

TEST_CASE("LavenderCreator makes a Lavender") {
  LavenderCreator creator;
  Plant *p = creator.factoryMethod();
  CHECK(p != nullptr);
  CHECK(dynamic_cast<Lavender *>(p) != nullptr);
  delete p;
}