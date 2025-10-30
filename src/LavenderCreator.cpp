/**
 * @file LavenderCreator.cpp
 * @brief Implementation of the LavenderCreator class
 * @author COS214 Students
 * @date 2024
 */

#include "LavenderCreator.h"
#include "Lavender.h"
#include <iostream>

LavenderCreator::LavenderCreator() {}

Plant* LavenderCreator::factoryMethod() const 
{
    std::cout << "anOperation: LavenderCreator has executed successfully." << std::endl;
    return new Lavender();
}
