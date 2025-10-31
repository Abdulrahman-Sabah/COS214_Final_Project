/**
 * @file CaresSchedulerObserver.cpp
 * @brief Implementation of CareSchedulerObserver for plant monitoring
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "CactusCare.h"
#include "CactusStrategyCmd.h"
#include "CareScheduleObserver.h"
#include "CareStrategy.h"
#include "DeadState.h"
#include "DeadStateCmd.h"
#include "DormantState.h"
#include "DormantStateCmd.h"
#include "GrowingState.h"
#include "GrowingStateCmd.h"
#include "Handler.h"
#include "LavenderCare.h"
#include "LavenderStrategyCmd.h"
#include "MatureState.h"
#include "MatureStateCmd.h"
#include "Plant.h"
#include "RoseCare.h"
#include "RoseStrategyCmd.h"
#include "SeedlingState.h"
#include "SeedlingStateCmd.h"
#include "SellingState.h"
#include "SellingStateCmd.h"

CareSchedulerObserver::CareSchedulerObserver() : handler_(nullptr) {}

void CareSchedulerObserver::onLifeCycleChanged(Plant* plantTesting,
                                               PlantLifeCycleState* newState) {
  // std::cout << "[CareScheduler] State changed for " << plant->name( << "\n";
  if(!plantTesting || !handler_ || !newState) return;

  Commands *command = nullptr;
  if (dynamic_cast<SeedlingState*>(newState)) {
    command = new SeedlingStateCmd();
  } else if (dynamic_cast<GrowingState*>(newState)) {
    command = new GrowingStateCmd();
  } else if (dynamic_cast<DormantState*>(newState)) {
    command = new DormantStateCmd();
  } else if (dynamic_cast<MatureState*>(newState)) {
    command = new MatureStateCmd();
  } else if (dynamic_cast<SellingState*>(newState)) {
    command = new SellingStateCmd();
  } else if (dynamic_cast<DeadState*>(newState)) {
    command = new DeadStateCmd();
  }

  if (command) {
    plantTesting->detach(this);  
    handler_->handleRequest(command, plantTesting);
    plantTesting->attach(this); 
  }
}

CareSchedulerObserver::~CareSchedulerObserver() {
  // if (handler_) delete handler_;
  // handler_ = nullptr;
}
// -------------------- STRATEGY (param passed in) --------------------

void CareSchedulerObserver::onCareStrategyChanged(Plant* plant,
                                                  CareStrategy* newStrategy) {
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