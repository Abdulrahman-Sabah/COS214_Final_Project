#include <iostream>
#include "DeliveryStaff.h"
#include "GreenhouseManager.h"
#include "Landscaper.h"
#include "ScheduleDelivery.h"
#include "MoveToSales.h"
#include "AddWater.h"
#include "ApplyFertilizer.h"

int main() {
    std::cout << "=== Chain of Responsibility Pattern Test ===" << std::endl;
    
   
    DeliveryStaff* deliveryStaff = new DeliveryStaff();
    GreenhouseManager* manager = new GreenhouseManager();
    Landscaper* landscaper = new Landscaper();
    
    
    deliveryStaff->setSuccessor(manager);    // delivery -> manager
    manager->setSuccessor(landscaper);       // manager -> landscaper
    
    std::cout << "\nChain built: DeliveryStaff -> GreenhouseManager -> Landscaper\n" << std::endl;
    
    
    ScheduleDelivery* deliveryCmd = new ScheduleDelivery("ORDER123");
    MoveToSales* salesCmd = new MoveToSales("PLANT456");
    AddWater* waterCmd = new AddWater("PLANT789");
    ApplyFertilizer* fertilizerCmd = new ApplyFertilizer("PLANT101");
    
    
    std::cout << "--- Testing Chain of Responsibility ---\n" << std::endl;
    
    std::cout << "1. Testing ScheduleDelivery command:" << std::endl;
    std::cout << "   Command Type: " << deliveryCmd->getType() << ", Data: " << deliveryCmd->getData() << std::endl;
    deliveryStaff->handleRequest(deliveryCmd);
    
    std::cout << "\n2. Testing MoveToSales command:" << std::endl;
    std::cout << "   Command Type: " << salesCmd->getType() << ", Data: " << salesCmd->getData() << std::endl;
    deliveryStaff->handleRequest(salesCmd);
    
    std::cout << "\n3. Testing AddWater command:" << std::endl;
    std::cout << "   Command Type: " << waterCmd->getType() << ", Data: " << waterCmd->getData() << std::endl;
    deliveryStaff->handleRequest(waterCmd);
    
    std::cout << "\n4. Testing ApplyFertilizer command:" << std::endl;
    std::cout << "   Command Type: " << fertilizerCmd->getType() << ", Data: " << fertilizerCmd->getData() << std::endl;
    deliveryStaff->handleRequest(fertilizerCmd);
    
    std::cout << "\n--- Expected Results ---" << std::endl;
    std::cout << "ScheduleDelivery -> Handled by DeliveryStaff" << std::endl;
    std::cout << "MoveToSales -> Passed through DeliveryStaff -> Handled by GreenhouseManager" << std::endl;
    std::cout << "AddWater -> Passed through DeliveryStaff -> GreenhouseManager -> Handled by Landscaper" << std::endl;
    std::cout << "ApplyFertilizer -> Passed through DeliveryStaff -> GreenhouseManager -> Handled by Landscaper" << std::endl;
    
    std::cout << "\n--- Test Complete ---" << std::endl;
    
    
    delete deliveryStaff;
    delete manager;
    delete landscaper;
    delete deliveryCmd;
    delete salesCmd;
    delete waterCmd;
    delete fertilizerCmd;
    
    return 0;
}
