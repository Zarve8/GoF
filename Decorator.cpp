//Decorator design pattern

#include <iostream>

class Component{
protected:
    std::string name_;
public:
    Component(std::string name): name_(name){}
    virtual std::string voice() = 0;
};

class ConcreteComponent: public Component{
public:
    ConcreteComponent(std::string name): Component(name){}
    std::string voice() override{
        return this->name_;
    }
};

class Decorator: public Component{
    std::string board_;
    Component* child_;
public:
    Decorator(std::string board, Component* child): board_(board), child_(child), Component(""){}
    std::string voice() override{
        return board_ + child_->voice() + board_;
    }
};

void Client(Component* component){
    std::cout<<component->voice();
}

int main(){
    ConcreteComponent* concreteComponent = new ConcreteComponent("Hello World");
    Component* acomponent = new Decorator("#", concreteComponent);
    Component* bcomponent = new Decorator("|", acomponent);
    Client(bcomponent);
}