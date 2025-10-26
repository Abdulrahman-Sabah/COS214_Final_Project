#include "Rose.h"
// #include "RoseCare.h"     // Will be available after merging branches
#include "SeedlingState.h"     // Will be available after merging branches

// Rose::Rose() : Plant("Rose", "Moderate", "Seedling", "Spring", nullptr, nullptr) {
//     // TODO: When branches are merged, update to:
//     // Plant("Rose", "Moderate", "Seedling", "Spring", new RoseCare(), new Seedling())
//     // Rose typically needs moderate care and starts as a seedling in spring
    
// }
Rose::Rose() {
    setName("Rose");
    setCareType("Moderate");
    setStateText("Healthy");
    setSeason("Spring");   
    setCareStrategy(nullptr);
    setLifeCycle(new SeedlingState());

}

// Rose::~Rose() {
    
// }

Plant* Rose::clone() {
    
    Rose* clonedRose = new Rose();
    clonedRose->setName(this->getName());
    clonedRose->setCareType(this->getCareType());
    clonedRose->setStateText(this->getStateText());
    clonedRose->setSeason(this->getSeason());
    clonedRose->setLifeCycle(this->getLifeCycle());
    return clonedRose;
}

std::string Rose::description() {
    return "Rose Plant";
}

double Rose::price() {
    return 30.00;
}
