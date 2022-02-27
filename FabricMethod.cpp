//Factory method

#include <iostream>

class Product{
public:
    virtual std::string GetResult(int n) = 0;
};

class ConcreteProduct1: public Product{
    std::string s;
public:
    ConcreteProduct1(std::string s): s(s){};
    std::string GetResult(int n) override{
        return s+" " + std::to_string(n);
    }
};

class ConcreteProduct2: public Product{
    std::string x;
public:
    ConcreteProduct2(std::string x): x(x){};
    std::string GetResult(int n) override{
        std::string s = "";
        for(int i = 0; i<n; i++){
            s += x;
        }
        return s;
    }
};

class Creator{
    virtual Product* FabricMethod() = 0;
public:
    std::string Operate(int n){
        Product* product = FabricMethod();
        return "\"" + product->GetResult(n) + "\"\n";
    }
};

class ConcreteCreator1: public Creator{
    Product* FabricMethod() override{
        return new ConcreteProduct1("1");
    }
};

class ConcreteCreator2: public Creator{
    Product* FabricMethod() override{
        return new ConcreteProduct2("2");
    }
};

int main(){
    Creator* acreator = new ConcreteCreator1;
    std::cout<<acreator->Operate(3);
    Creator* bcreator = new ConcreteCreator2;
    std::cout<<bcreator->Operate(3);
}