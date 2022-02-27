//Facade design pattern

#include <iostream>

class SubsystemA{
    std::string name_;
public:
    SubsystemA(std::string name): name_(name){}
    std::string voice(){
        return name_ + " A";
    }
};

class SubsystemB{
    std::string name_;
public:
    SubsystemB(std::string name): name_(name){}
    std::string voice(){
        return name_ + " B";
    }
};

class Facade{
    SubsystemA* subsystemA_;
    SubsystemB* subsystemB_;
public:
    Facade(SubsystemA* A, SubsystemB* B): subsystemA_(A), subsystemB_(B){}
    std::string Operate(){
        return subsystemB_->voice() + " " + subsystemA_->voice();
    }
};

void Client(Facade* facade){
    std::cout<<facade->Operate();
}

int main(){
    Facade* facade = new Facade(new SubsystemA("AAA"), new SubsystemB("BBB"));
    Client(facade);
}