#include <iostream>


// In this example, the Receiver class defines the object that the command will operate on.
// The Command interface defines the methods that all commands must implement.
// The ConcreteCommand class implements the Command interface and defines the actual behavior of the command, it has a reference to the Receiver object as an instance variable. 
// The Invoker class is responsible for creating and executing the command, it has a reference to the Command object as an instance variable.

// The main benefit of the Command pattern is that it allows you to encapsulate behavior as objects, which can be easily passed around and composed into more complex behavior. 
// This makes your code more flexible and reusable. 
// It also allows you to separate the logic that initiates a behavior from the logic that performs the behavior, which can make your code easier to understand and maintain.
class Receiver {
public:
    void action() {
        std::cout << "Receiver's action" << std::endl;
    }
};

class Command {
public:
    virtual void execute() = 0;
};

class ConcreteCommand : public Command {
private:
    Receiver *receiver;
public:
    ConcreteCommand(Receiver *receiver) {
        this->receiver = receiver;
    }
    void execute() {
        receiver->action();
    }
};

class Invoker {
private:
    Command *command;
public:
    void setCommand(Command *command) {
        this->command = command;
    }
    void invoke() {
        command->execute();
    }
};
