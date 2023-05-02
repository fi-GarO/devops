#include <iostream>
#include <unordered_map>

//In this example, the Flyweight class defines the interface for the shared objects. 
// The ConcreteFlyweight class implements the Flyweight interface and defines the actual behavior of the shared objects. 
// The FlyweightFactory class is responsible for creating and managing the shared objects, it has a cache to store the objects that have already been created.
class Flyweight {
public:
    virtual void operation() = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
    void operation() {
        std::cout << "ConcreteFlyweight's operation" << std::endl;
    }
};

class FlyweightFactory {
private:
    std::unordered_map<int, Flyweight*> flyweights;
public:
    Flyweight* getFlyweight(int key) {
        if (flyweights.count(key) == 0) {
            flyweights[key] = new ConcreteFlyweight();
        }
        return flyweights[key];
    }
};
