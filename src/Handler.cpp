/**
 * @file Handler.cpp
 * @brief Implementation of Handler base class for Chain of Responsibility pattern
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "Handler.h"
#include <iostream>

void Handler::setSuccessor(Handler* h){
    successor = h;
}

void Handler::passToSuccessor(Commands* r) {
    if (successor) {
        successor->handleRequest(r);
    } else {
        std::cout << "End of chain reached. No handler available for this request." << std::endl;
    }
}