/**
 * @file Handler.cpp
 * @brief Implementation of Handler base class for Chain of Responsibility
 * pattern
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "Handler.h"

#include <iostream>

Handler::Handler() : successor(nullptr), subject(nullptr) {}

Handler::~Handler() {
  // delete successor;
  successor = nullptr;
}

void Handler::setSuccessor(Handler *h) { 
  if(!h) return;
  successor = h; 
}

void Handler::passToSuccessor(Commands* r, Plant* plant) {
  if (successor) {
    successor->handleRequest(r, plant);
  } else {
    std::cout << "End of chain reached. No handler available for this request."
              << std::endl;
    delete r;
  }
}