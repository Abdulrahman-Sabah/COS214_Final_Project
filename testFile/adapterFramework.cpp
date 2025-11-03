#ifndef ADAPTERFRAMEWORK_CPP_DOC
/**
 * @file adapterFramework.cpp
 * @brief Unit test cases for WebAPI and Inventory integration.
 * @author Git it done group members
 * @date 10-2025
 */
#define ADAPTERFRAMEWORK_CPP_DOC
#endif

#include "doctest.h"
#include <string>
#include "Inventory.h"
#include "WebAPI.h"
#include "InventorySerializer.h"

TEST_CASE("WebAPI add/get/remove functions") {
    Inventory inv;
    WebAPI api(&inv);
    CHECK(inv.getSize() == 0);

    bool added = api.addPlantToInventory("RosePlant", "flowering", "blooming", "spring", 9.99);
    REQUIRE(added == true);
    CHECK(inv.getSize() == 1);

    std::string json = api.getPlantsJSON();
    CHECK(json.find("\"plants\"") != std::string::npos);
    CHECK(json.find("RosePlant") != std::string::npos);
    CHECK(json.find("\"type\"") != std::string::npos);

    api.addPlantToInventory("CactusPlant", "succulent", "dormant", "winter", 4.50);
    CHECK(inv.getSize() == 2);
    json = api.getPlantsJSON();
    CHECK(json.find("RosePlant") != std::string::npos);
    CHECK(json.find("CactusPlant") != std::string::npos);

    bool removed = api.removePlantFromInventory("RosePlant");
    CHECK(removed == true);
    CHECK(inv.getSize() == 1);
    json = api.getPlantsJSON();
    CHECK(json.find("RosePlant") == std::string::npos);
}

TEST_CASE("WebAPI json format works correctly") {
    Inventory inv;
    WebAPI api(&inv);

    std::string json = api.getPlantsJSON();
    CHECK(json.find("\"plants\":[") != std::string::npos);

    bool works = ( !json.empty() &&
                          (json.back() == '}' ||
                           json.find("]}") != std::string::npos ||
                           json.find("]") != std::string::npos) );
    CHECK(works);
}