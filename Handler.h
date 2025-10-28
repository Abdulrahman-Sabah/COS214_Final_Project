#ifndef HANDLER_H
#define HANDLER_H


class Notify;
class Commands;  // Changed from Command to Commands

class Handler{
    private:
        Handler* successor;  // Pointer to next handler in chain
        Notify* subject;
    protected:
        // Helper method for derived classes to pass requests along the chain
        void passToSuccessor(Commands* r); //Add to UML - Changed parameter type
    public:
        void setSuccessor(Handler* h);
        virtual void handleRequest(Commands* r) = 0;  // Changed parameter type
        virtual ~Handler() = default;  // Add destructor to UML
};
#endif