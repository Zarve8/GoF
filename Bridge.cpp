//Bridge design pattern

#include <iostream>

class Implementor{
public:
    virtual std::string Operation() = 0;
};

class ConcreteImplementor1: public Implementor{
public:
    std::string Operation() override {
        return "Implemention 1\n";
    }
};

class ConcreteImplementor2: public Implementor{
public:
    std::string Operation() override {
        return "Implemention 2\n";
    }
};

class Abstraction{
    Implementor* implementor_;
public:
    Abstraction(Implementor* implementor): implementor_(implementor){}
    std::string GetResult(){
        return implementor_->Operation();
    }
};

void Client(Abstraction* abstraction){
    std::cout<<abstraction->GetResult();
}

int main(){
    Abstraction* abstraction = new Abstraction(new ConcreteImplementor2);
    Client(abstraction);
}
