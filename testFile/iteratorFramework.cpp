#include "doctest.h"
#include <vector>
#include <string>
#include "Inventory.h"
#include "InventoryIterator.h"
#include "Plant.h"
#include "Rose.h"
#include "Cactus.h"
#include "Lavender.h"

TEST_CASE("add plants") {
    Inventory inv;
    inv.addPlant(new Rose());
    inv.addPlant(new Cactus());
    inv.addPlant(new Lavender());

    PlantIterator* it = inv.createIterator();
    REQUIRE(it != nullptr);

    std::vector<std::string> names;
    for (it->first(); !it->isDone(); it->next()) {
        Plant* p = it->current();
        REQUIRE(p != nullptr);
        names.push_back(p->getName());
    }
    delete it;

    CHECK(names.size() == 3u);
    CHECK(names[0] == "Rose");
    CHECK(names[1] == "Cactus");
    CHECK(names[2] == "Lavender");

    bool removed = inv.removePlantByName("Rose");
    CHECK(removed);

    removed = inv.removePlantByName("Cactus");
    CHECK(removed);

    removed = inv.removePlantByName("Lavender");
    CHECK(removed);


}

TEST_CASE("empty iterator traverse behaviour") {
    Inventory inv;
    PlantIterator* it = inv.createIterator();
    it->first();
    CHECK(it->isDone());
    CHECK(it->current() == nullptr);
    delete it;

    inv.addPlant(new Rose());
    inv.addPlant(new Lavender());

    it = inv.createIterator();
    it->first();
    std::size_t count = 0;
    std::vector<std::string> seen;
    while (!it->isDone()) {
        Plant* p = it->current();
        REQUIRE(p != nullptr);
        seen.push_back(p->getName());
        ++count;
        it->next();
    }
    delete it;

    CHECK(count == 2u);
    CHECK(seen[0] == "Rose");
    CHECK(seen[1] == "Lavender");

    bool removedA = inv.removePlantByName("Rose");
    CHECK(removedA);

    bool removedB = inv.removePlantByName("Lavender");
    CHECK(removedB);

}

TEST_CASE("Inventory remove plant") {
    Inventory inv;
    Plant* p = new Rose();
    inv.addPlant(p);
    p->setStateText("Dead");
    bool removed = inv.removePlant(p);
    CHECK(removed);

    CHECK(inv.removePlant(p) == false);

    Plant* q = new Cactus();
    inv.addPlant(q);
    q->setStateText("Dead");
    CHECK(inv.removePlantByName("Cactus") == true);
    
    CHECK(inv.removePlantByName("Cactus") == false);

    CHECK(!inv.removePlantByName("Cactus"));

}