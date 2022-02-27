//Factory design pattern

#include <iostream>

class Product{
public:
    virtual std::string voice() = 0;
};

class ConcreteProductA: public Product{
    std::string name_;
public:
    ConcreteProductA(std::string name): name_(name){}
    std::string voice() override{
        return name_ + " A\n";
    }
};

class ConcreteProductB: public Product{
    std::string name_;
public:
    ConcreteProductB(std::string name): name_(name){}
    std::string voice() override{
        return name_ + " B\n";
    }
};

class ConcreteProductC: public Product{
    std::string name_;
public:
    ConcreteProductC(std::string name): name_(name){}
    std::string voice() override{
        return name_ + " C\n";
    }
};

enum class E_Products{A, B, C};

Product* Factory(E_Products product, std::string name){
    switch(product){
        case E_Products::A:
            return new ConcreteProductA(name);
            case E_Products::B:
                return new ConcreteProductB(name);
                case E_Products::C:
                    return new ConcreteProductC(name);
    }
};

void Client(Product* product){
    std::cout<<product->voice();
}

int main(){
    Product* aproduct  = Factory(E_Products::B, "Hi");
    Client(aproduct);
}