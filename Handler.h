#ifndef HANDLER_H
#define HANDLER_H


class Notify;
class Command;

class Handler{
    private:
        Handler* successor;  // Pointer to next handler in chain
        Notify* subject;
    public:
        void setSuccessor(Handler* h);
        virtual void handleRequest(Command* r) = 0;
        virtual ~Handler() = default;  // Virtual destructor for polymorphism
};
#endif