//Proxy design pattern

#include <iostream>

class Product{
public:
    virtual std::string Request() = 0;
};

class RealProduct: public Product{
public:
    std::string Request() override{
        return "RealProduct request handled\n";
    }
};

class ProxyProduct: public Product{
    Product* product_instance_;
    void LogRequest(){
        std::cout<<"Request logged\n";
    }
public:
    std::string Request() override{
        LogRequest();
        if(product_instance_){
            return product_instance_->Request();
        }
        else{
            product_instance_ = new RealProduct();
            return product_instance_->Request();
        }
    }
};

void Client(Product* product){
    std::cout<<product->Request();
}

int main(){
    Product* proxy = new ProxyProduct();
    Client(proxy);
}