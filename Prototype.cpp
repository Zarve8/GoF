//Prototype design pattern used with Fabric and Singleton

#include <iostream>
#include <map>

class Prototype{
    std::string name;
    std::string value;
public:
    Prototype(std::string name, std::string value): name(name), value(value){}
    Prototype* Clone(){
        return new Prototype(name, value);
    }
    void voice(){
        std::cout<<name<<" "<<value<<"\n";
    }
};

class PrototypeKit{
    static PrototypeKit* instance;
    std::map<std::string, Prototype*> kit{};
    std::string value;
    PrototypeKit(std::string value): value(value){}
public:
    static void Initialize(std::string value){
        instance = new PrototypeKit(value);
    }
    static PrototypeKit* GetInstance(){
        if(instance){
            return instance;
        }
        return nullptr;
    }
    void add_prototype(std::string name){
        Prototype* prototype = new Prototype(name, value);
        kit.insert({name, prototype});
    }
    Prototype* get_prototype(std::string name){
        return kit[name]->Clone();
    }
};
PrototypeKit* PrototypeKit::instance = nullptr;

int main(){
    PrototypeKit::Initialize("###");
    PrototypeKit* Kit = PrototypeKit::GetInstance();
    Kit->add_prototype("first");
    Kit->add_prototype("second");
    Kit->add_prototype("third");
    Kit->get_prototype("second")->voice();
}
