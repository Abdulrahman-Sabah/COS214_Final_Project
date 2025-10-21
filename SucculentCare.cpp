#include "SucculentCare.h"

void SucculentCare::applyCare(Plant& plant) {  
    std::cout << plant.getName() << " is being watered sparingly, allowing soil to dry out between waterings." << std::endl;
    std::cout << plant.getName() << " is now being placed to be in bright, indirect sunlight." << std::endl;
    std::cout << plant.getName() << " is being potted in well-draining soil to prevent root rot." << std::endl;
}