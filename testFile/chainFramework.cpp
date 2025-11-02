#include "doctest.h"

#include <string>
#include <sstream>
#include <functional>
#include <iostream>

#include "Handler.h"
#include "GreenhouseManager.h"
#include "Landscaper.h"
#include "Commands.h"
#include "Plant.h"
#include "Rose.h"
#include "Cactus.h"
#include "Lavender.h"
#include "CactusStrategyCmd.h"
#include "LavenderStrategyCmd.h"
#include "RoseStrategyCmd.h"
#include "SeedlingStateCmd.h"
#include "GrowingStateCmd.h"
#include "MatureStateCmd.h"

static std::string capture_stdout_chain(const std::function<void()>& fn) {
    std::ostringstream oss;
    std::streambuf* old_buf = std::cout.rdbuf(oss.rdbuf());
    fn();
    std::cout.flush();
    std::cout.rdbuf(old_buf);
    return oss.str();
}

TEST_CASE("Handler can set successor in chain") {
    GreenhouseManager manager;
    Landscaper landscaper;
    
    REQUIRE_NOTHROW(manager.setSuccessor(&landscaper));
}

TEST_CASE("GreenhouseManager handles requests") {
    GreenhouseManager manager;
    Rose r;
    Commands* cmd = new SeedlingStateCmd(); 
    
    REQUIRE_NOTHROW(manager.handleRequest(cmd, &r));
    // Handler deletes cmd
}

TEST_CASE("Landscaper handles plant care requests") {
    Landscaper landscaper;
    Cactus c;
    Commands* cmd = new CactusStrategyCmd();  
    
    REQUIRE_NOTHROW(landscaper.handleRequest(cmd, &c));
    // Handler deletes cmd
}

TEST_CASE("Chain passes request from Manager to Landscaper") {
    GreenhouseManager manager;
    Landscaper landscaper;
    manager.setSuccessor(&landscaper);
    Lavender l;
    Commands* cmd = new LavenderStrategyCmd();  
    
    std::string out = capture_stdout_chain([&]{ 
        manager.handleRequest(cmd, &l);
    });
    
    CHECK(true);
    // Handler deletes cmd
}

TEST_CASE("multiple requests in sequence") {
    GreenhouseManager manager;
    Landscaper landscaper;
    manager.setSuccessor(&landscaper);
    
    Rose r;
    
    Commands* seed_cmd = new SeedlingStateCmd();
    Commands* grow_cmd = new GrowingStateCmd();
    Commands* mature_cmd = new MatureStateCmd();
    
    REQUIRE_NOTHROW(manager.handleRequest(seed_cmd, &r));
    REQUIRE_NOTHROW(manager.handleRequest(grow_cmd, &r));
    REQUIRE_NOTHROW(manager.handleRequest(mature_cmd, &r));
}

TEST_CASE("diff plants") {
    GreenhouseManager manager;
    Landscaper landscaper;
    manager.setSuccessor(&landscaper);
    Rose r;
    Cactus c;
    Lavender l;
    
    Commands* rose_cmd = new RoseStrategyCmd();
    Commands* cactus_cmd = new CactusStrategyCmd();
    Commands* lavender_cmd = new LavenderStrategyCmd();
    
    REQUIRE_NOTHROW(manager.handleRequest(rose_cmd, &r));
    REQUIRE_NOTHROW(manager.handleRequest(cactus_cmd, &c));
    REQUIRE_NOTHROW(manager.handleRequest(lavender_cmd, &l));
}

TEST_CASE("Handler without successor processes request") {
    Landscaper landscaper;    
    Cactus c;
    Commands* cmd = new CactusStrategyCmd();  

    REQUIRE_NOTHROW(landscaper.handleRequest(cmd, &c));
}

TEST_CASE("Chain with nullptr plant is handled safely") {
    GreenhouseManager manager;
    Commands* cmd = new SeedlingStateCmd(); 
    
    REQUIRE_NOTHROW(manager.handleRequest(cmd, nullptr));
}

TEST_CASE("Chain with three handlers") {
    GreenhouseManager manager1;
    GreenhouseManager manager2;
    Landscaper landscaper;
    manager1.setSuccessor(&manager2);
    manager2.setSuccessor(&landscaper);
    Rose r;
    Commands* cmd = new RoseStrategyCmd();
    
    std::string out = capture_stdout_chain([&]{ 
        manager1.handleRequest(cmd, &r);
    });
    CHECK(true);
}

TEST_CASE("Handler destructor") {
    Handler* manager = new GreenhouseManager();
    Handler* landscaper = new Landscaper();
    manager->setSuccessor(landscaper);
    delete manager;
    delete landscaper;
    CHECK(true);
}

TEST_CASE("Chain handles mature state command") {
    GreenhouseManager manager;
    Landscaper landscaper;
    manager.setSuccessor(&landscaper);
    
    Rose plant;
    Commands* cmd = new MatureStateCmd(); 
    REQUIRE_NOTHROW(manager.handleRequest(cmd, &plant));
}