//Mediator design pattern

#include <iostream>

enum class E_Event{A, B, C, D};

class BaseComponent;

class Mediator{
public:
    virtual void Notify(BaseComponent *sender, E_Event event) const = 0;
};

class BaseComponent{
protected:
    Mediator* mediator_;
public:
    BaseComponent() = default;
    void set_mediator(Mediator* mediator){
        mediator_ = mediator;
    }
};

class Component1: public BaseComponent{
public:
    void Do_A() {
        std::cout << "Component1 does A.\n";
        this->mediator_->Notify(this, E_Event::A);
    }
    void Do_B() {
        std::cout << "Component1 does B.\n";
        this->mediator_->Notify(this, E_Event::B);
    }
};

class Component2: public BaseComponent{
public:
    void Do_C() {
        std::cout << "Component1 does C.\n";
        this->mediator_->Notify(this, E_Event::C);
    }
    void Do_D() {
        std::cout << "Component1 does D.\n";
        this->mediator_->Notify(this, E_Event::D);
    }
};

class ConcreteMediator: public Mediator{
    Component1* c1;
    Component2* c2;
public:
    ConcreteMediator(Component1* c1, Component2* c2): c1(c1), c2(c2){
        c1->set_mediator(this);
        c2->set_mediator(this);
    }
    void Notify(BaseComponent *sender, E_Event event) const override{
        if (event == E_Event::A) {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            this->c2->Do_C();
        }
        if (event == E_Event::D) {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->c1->Do_B();
            this->c2->Do_C();
        }
    }
};

int main(){
    Component1 *c1 = new Component1;
    Component2 *c2 = new Component2;
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2);
    std::cout << "Client triggers operation A.\n";
    c1->Do_A();
    std::cout << "\n";
    std::cout << "Client triggers operation D.\n";
    c2->Do_D();
}