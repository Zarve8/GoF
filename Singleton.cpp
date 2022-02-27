//Singleton design pattern

#include <iostream>

class Singleton{
protected:
    std::string s;
    Singleton(const std::string value): s(value){}
    static Singleton* singleton_;
public:
    static Singleton* GetInstance(std::string s){
        if(singleton_){
            return singleton_;
        }
        else{
            singleton_ = new Singleton(s);
            return singleton_;
        }
    }
    //Singletons should not be cloned
    Singleton(Singleton &other) = delete;
    //Singletons should not be assignable
    void operator=(const Singleton &) = delete;
    void voice(){
        std::cout<<this->s<<"\n";
    }
};

Singleton* Singleton::singleton_= nullptr;

int main(){
    Singleton* asingleton = Singleton::GetInstance("First");
    asingleton->voice();
    Singleton* bsingleton = Singleton::GetInstance("Second");
    bsingleton->voice();
}