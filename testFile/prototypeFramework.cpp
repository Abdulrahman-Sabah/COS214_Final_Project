#include "Cactus.h"
#include "CardDecorator.h"
#include "Lavender.h"
#include "Plant.h"
#include "PlantDecorations.h"
#include "PotDecorator.h"
#include "Rose.h"
#include "WrapDecorator.h"
#include "doctest.h"

TEST_CASE("Rose clone") {
  Rose original;
  Plant *copy = original.clone();
  REQUIRE(copy != nullptr);
  CHECK(dynamic_cast<Rose *>(copy) != nullptr);
  CHECK(copy->description() == original.description());
  CHECK(copy->price() == doctest::Approx(original.price()));
  delete copy;
}

TEST_CASE("Cactus clone") {
  Cactus original;
  Plant *copy = original.clone();
  REQUIRE(copy != nullptr);
  CHECK(dynamic_cast<Cactus *>(copy) != nullptr);
  CHECK(copy->description() == original.description());
  CHECK(copy->price() == doctest::Approx(original.price()));
  delete copy;
}

TEST_CASE("Lavender clone") {
  Lavender original;
  Plant *copy = original.clone();
  REQUIRE(copy != nullptr);
  CHECK(dynamic_cast<Lavender *>(copy) != nullptr);
  CHECK(copy->description() == original.description());
  CHECK(copy->price() == doctest::Approx(original.price()));
  delete copy;
}

TEST_CASE("Decorator clone - single Pot/Wrap/Card") {
  Plant *potDecor = new PotDecorator(new Rose(), "Terracotta", 8.0);
  Plant *potCopy = potDecor->clone();
  REQUIRE(potCopy != nullptr);
  CHECK(potCopy->description() == potDecor->description());
  CHECK(potCopy->price() == doctest::Approx(potDecor->price()));
  delete potDecor;
  CHECK(potCopy->description().find("Terracotta") != std::string::npos);
  delete potCopy;

  Plant *wrapDecor = new WrapDecorator(new Rose(), "Silver", 5.0);
  Plant *wrapCopy = wrapDecor->clone();
  REQUIRE(wrapCopy != nullptr);
  CHECK(wrapCopy->description() == wrapDecor->description());
  CHECK(wrapCopy->price() == doctest::Approx(wrapDecor->price()));
  delete wrapDecor;
  CHECK(wrapCopy->description().find("Silver") != std::string::npos);
  delete wrapCopy;

  Plant *cardDecor = new CardDecorator(new Rose(), "Happy Birthday", 2.0);
  Plant *cardCopy = cardDecor->clone();
  REQUIRE(cardCopy != nullptr);
  CHECK(cardCopy->description() == cardDecor->description());
  CHECK(cardCopy->price() == doctest::Approx(cardDecor->price()));
  delete cardDecor;
  CHECK(cardCopy->description().find("Happy Birthday") != std::string::npos);
  delete cardCopy;
}
