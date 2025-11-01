#include "doctest.h"
#include <string>
#include <sstream>
#include <functional>
#include <iostream>
#include "FrontDesk.h"
#include "StoreCustomer.h"
#include "StoreColleague.h"
#include "DeliveryStaff.h"
#include "Inventory.h"
#include "Plant.h"
#include "Rose.h"
#include "Cactus.h"
#include "Lavender.h"


static std::string capture_stdout(const std::function<void()>& fn) {
    std::ostringstream oss;
    std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
    fn();
    std::cout.flush();
    std::cout.rdbuf(old);
    return oss.str();
}

TEST_CASE("StoreCustomer requests plant by pointer") {
    FrontDesk fd;
    StoreCustomer customer(&fd);
    Lavender plant;
    REQUIRE_NOTHROW(customer.requestPlant(&plant));
}

TEST_CASE("StoreCustomer requests plant") {
    FrontDesk fd;
    StoreCustomer customer(&fd);
    Rose r;

    std::string out = capture_stdout([&]{ customer.requestPlant(&r); });
    REQUIRE_NOTHROW(customer.requestPlant(&r));
    if (!out.empty()) {
        CHECK(out.find(r.getName()) != std::string::npos);
    }
}

TEST_CASE("Mediator routes requests between multiple colleagues without throwing") {
    FrontDesk fd;
    StoreCustomer cust1(&fd);
    StoreCustomer cust2(&fd);
    Inventory inventory;
    DeliveryStaff delivery(&inventory);
    Cactus cactus;
    Rose rose;

    REQUIRE_NOTHROW(cust1.requestPlant(&cactus));
    REQUIRE_NOTHROW(cust2.requestPlant(&rose));
    REQUIRE_NOTHROW(delivery.receive("Scheduled"));
}

TEST_CASE("DeliveryStaff processes customer ") {
    Inventory inv;
    DeliveryStaff delivery(&inv);
    Rose r;
    REQUIRE_NOTHROW(delivery.processCustomerRequest(&r));
}

TEST_CASE("DeliveryStaff receives notifications") {
    Inventory inv;
    DeliveryStaff delivery(&inv);
    REQUIRE_NOTHROW(delivery.receive("Delivery ready"));
}

TEST_CASE("DeliveryStaff can update inventory reference") {
    Inventory inv1;
    Inventory inv2;
    DeliveryStaff delivery(&inv1); 
   REQUIRE_NOTHROW(delivery.setInventory(&inv2));
}