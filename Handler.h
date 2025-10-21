#ifndef HANDLER_H
#define HANDLER_H


class Notify;
class Command;

class Handler{
    private:
        Handler* successor;  // Pointer to next handler in chain
        Notify* subject;
    protected:
        // Helper method for derived classes to pass requests along the chain
        void passToSuccessor(Command* r); //Add to UML
    public:
        void setSuccessor(Handler* h);
        virtual void handleRequest(Command* r) = 0;
        virtual ~Handler() = default;  // Add destructor to UML
};
#endif