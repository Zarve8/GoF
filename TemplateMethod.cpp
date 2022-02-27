//Template method design patter

#include <iostream>

class AbstractClass{
public:
    void TemplateMethod(){
        Print(Operation2(Operation1()));
    }
    virtual std::string Operation1() = 0;
    virtual std::string Operation2(std::string s) = 0;
    void Print(std::string s){
        std::cout<<s<<"\n";
    }
};

class ConcreteClass: public AbstractClass{
    std::string Operation1() override{
        return "Operated in concrete class";
    }
    std::string Operation2(std::string s) override{
        return s + " and another operation";
    }
};

int main(){
    ConcreteClass* concreteClass = new ConcreteClass();
    concreteClass->TemplateMethod();
}