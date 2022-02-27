//Visitor design pattern

#include <iostream>
#include <vector>


class ComponentA;
class ComponentB;

class Visitor{
public:
    virtual void VisitComponentA(ComponentA* component) = 0;
    virtual void VisitComponentB(ComponentB* component) = 0;
};

class Component{
public:
    virtual void AcceptVisitor(Visitor* visitor) = 0;
};

class ComponentA: public Component{
public:
    void AcceptVisitor(Visitor *visitor) override{
        visitor->VisitComponentA(this);
    }
    std::string SpecialMethodA(){
        return "A";
    }
};

class ComponentB: public Component{
public:
    void AcceptVisitor(Visitor *visitor) override{
        visitor->VisitComponentB(this);
    }
    std::string SpecialMethodB(){
        return "B";
    }
};

class ConcreteVisitor: public Visitor{
public:
    void VisitComponentA(ComponentA *component) override{
        std::cout<<"Visited component "<<component->SpecialMethodA()<<"\n";
    }
    void VisitComponentB(ComponentB *component) override{
        std::cout<<"Visited component "<<component->SpecialMethodB()<<"\n";
    }
};

void Client(std::vector<Component*> component_list){
    Visitor* visitor = new ConcreteVisitor();
    for(auto it : component_list){
        it->AcceptVisitor(visitor);
    }
}

int main(){
    std::vector<Component*> component_list{new ComponentA(), new ComponentB(), new ComponentA};
    Client(component_list);
}