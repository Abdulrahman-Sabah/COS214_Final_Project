#include "Handler.h"
#include <iostream>

Handler::Handler() : successor(nullptr), subject(nullptr) {}

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