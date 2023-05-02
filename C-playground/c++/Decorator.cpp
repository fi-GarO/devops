#include <iostream>
#include <map>
#include <stdexcept>
//In this example, the Component class defines the interface for the objects that will be wrapped. 
// The ConcreteComponent class implements the Component interface and defines the basic behavior of the wrapped objects.
// The Decorator class is an abstract class that implements the Component interface and has a reference to the wrapped object as an instance variable.
// The ConcreteDecoratorA and ConcreteDecoratorB classes are subclasses of the Decorator class, 
// they add new behavior to the wrapped object by delegating the calls to it and by adding their own behavior.

class Component {
public:
    virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
    void operation() {
        std::cout << "ConcreteComponent's operation" << std::endl;
    }
};

class Decorator : public Component {
private:
    Component *component;
public:
    Decorator(Component *component) {
        this->component = component;
    }
    void operation() {
        component->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component *component) : Decorator(component) {}
    void operation() {
        Decorator::operation();
        addedBehaviorA();
    }
    void addedBehaviorA() {
        std::cout << "ConcreteDecoratorA's added behavior" << std::endl;
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component *component) : Decorator(component) {}
    void operation() {
        Decorator::operation();
        addedBehaviorB();
    }
    void addedBehaviorB() {
        std::cout << "ConcreteDecoratorB's added behavior" << std::endl;
    }
};
