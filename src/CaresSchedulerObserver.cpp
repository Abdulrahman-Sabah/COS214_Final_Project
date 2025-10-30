/**
 * @file CaresSchedulerObserver.cpp
 * @brief Implementation of CareSchedulerObserver for plant monitoring
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "CareScheduleObserver.h"

#include "CareStrategy.h"
#include "RoseCare.h"
#include "CactusCare.h"
#include "LavenderCare.h"

#include "SeedlingState.h"
#include "GrowingState.h"
#include "DormantState.h"
#include "MatureState.h"
#include "SellingState.h"
#include "DeadState.h"


#include "SeedlingStateCmd.h"
#include "GrowingStateCmd.h"
#include "DormantStateCmd.h"
#include "MatureStateCmd.h"
#include "SellingStateCmd.h"

#include "DeadStateCmd.h"
#include "DormantStateCmd.h"
#include "GrowingState.h"
#include "MatureState.h"
#include "SeedlingStateCmd.h"
#include "SellingStateCmd.h"
#include "Plant.h"
#include "Handler.h"
#include "Handler.h" 
#include "RoseStrategyCmd.h"
#include "CactusStrategyCmd.h"
#include "LavenderStrategyCmd.h"

CareSchedulerObserver::CareSchedulerObserver() : handler_(nullptr) {}

void CareSchedulerObserver::onLifeCycleChanged(Plant* plantTesting, PlantLifeCycleState* newState)
{

    // std::cout << "[CareScheduler] State changed for " << plant->name( << "\n";

    if (dynamic_cast<SeedlingState*>(newState)) 
    {
        Commands* testing = new SeedlingStateCmd();
        handler_->handleRequest(testing, plantTesting);    
    } 
    else if (dynamic_cast<GrowingState*>(newState)) 
    {
        Commands* testingN = new GrowingStateCmd();    
         handler_->handleRequest(testingN, plantTesting); 
    } 
    else if (dynamic_cast<DormantState*>(newState)) 
    {
        Commands* testingN = new DormantStateCmd();     
         handler_->handleRequest(testingN, plantTesting); 
    } 
    else if (dynamic_cast<MatureState*>(newState)) 
    {
        Commands* testingN = new MatureStateCmd();      
         handler_->handleRequest(testingN, plantTesting); 
    } else if (dynamic_cast<SellingState*>(newState)) 
    {
        Commands* testingN = new SellingStateCmd();      
         handler_->handleRequest(testingN, plantTesting); 
    } 
    else if (dynamic_cast<DeadState*>(newState)) 
    {
        Commands* testingN = new DeadStateCmd();        
        handler_->handleRequest(testingN, plantTesting); 
    } 

}


CareSchedulerObserver::~CareSchedulerObserver()
{
    // if (handler_) delete handler_;
    // handler_ = nullptr;
}
// -------------------- STRATEGY (param passed in) --------------------

void CareSchedulerObserver::onCareStrategyChanged(Plant* plant, CareStrategy* newStrategy)
{
    if (!plant || !handler_ || !newStrategy) return;

    if (dynamic_cast<RoseCare*>(newStrategy)) {
        Commands* cmd = new RoseStrategyCmd();
        handler_->handleRequest(cmd, plant);

    } else if (dynamic_cast<CactusCare*>(newStrategy)) {
        Commands* cmd = new CactusStrategyCmd();
        handler_->handleRequest(cmd, plant);

    } else if (dynamic_cast<LavenderCare*>(newStrategy)) {
        Commands* cmd = new LavenderStrategyCmd();
        handler_->handleRequest(cmd, plant);
    }
}