//Adapter design pattern

#include <iostream>

class Target{
public:
    virtual std::string Request(){
        return "Target standart behaviour\n";
    }
};

class Adaptee{
public:
    virtual std::string SpecialRequest(){
        return "Adaptee behaviour";
    }
};

class Adapter: public Target{
    Adaptee* adaptee_;
public:
    Adapter(Adaptee* adaptee): adaptee_(adaptee){}
    std::string Request() override{
        return adaptee_->SpecialRequest() + " adapted\n";
    }
};

void ClientCode(Target* target){
    std::cout<<target->Request();
}

int main(){
    Target* atarget = new Target();
    ClientCode(atarget);
    Adaptee* aadaptee = new Adaptee();
    Target* btarget = new Adapter(aadaptee);
    ClientCode(btarget);
}