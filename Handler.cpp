#include "Handler.h"
#include <iostream>

void Handler::setSuccessor(Handler* h){
    successor = h;
}

void Handler::passToSuccessor(Command* r) {
    if (successor) {
        successor->handleRequest(r);
    } else {
        std::cout << "End of chain reached. No handler available for this request." << std::endl;
    }
}