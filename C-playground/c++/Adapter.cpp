#include <iostream>

//In this example, the Target class defines the interface that the client code expects. 
// The Adaptee class has the interface that needs to be adapted. 
// The Adapter class implements the Target interface and has a reference to the Adaptee object as an instance variable.
// The Adapter class translates the calls from the Target interface to the Adaptee interface.

class Target {
public:
    virtual void request() = 0;
};

class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};

class Adapter : public Target {
private:
    Adaptee *adaptee;
public:
    Adapter(Adaptee *adaptee) {
        this->adaptee = adaptee;
    }
    void request() {
        adaptee->specificRequest();
    }
};
