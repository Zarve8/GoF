//Flyweight design pattern

#include <iostream>
#include <map>

struct SharedState{
    std::string model_;
public:
    SharedState(std::string model): model_(model){}
    std::string voice(){
        return model_;
    }
};

class Flyweight{
    std::string name_;
    SharedState* sharedstate_;
public:
    Flyweight(std::string name, SharedState* model): name_(name), sharedstate_(model){}
    void voice(){
        std::cout<<sharedstate_->voice()+"_"+name_+"_";
        std::cout<<sharedstate_;
        std::cout<<"_\n";
    }
};

class FlyweightKit{
    std::map<std::string, SharedState*> states{};
public:
    Flyweight* GetFlyWeight(std::string name, std::string model){
        SharedState* sharedState;
        try{
            sharedState = states.at(model);
        }
        catch(const std::out_of_range &e){
            sharedState = new SharedState(model);
            states.insert({model, sharedState});
        }
        return new Flyweight(name, sharedState);
    }
};

int main(){
    FlyweightKit* Kit = new FlyweightKit();
    Flyweight* aflyweight = Kit->GetFlyWeight("a", "new");
    Flyweight* bflyweight = Kit->GetFlyWeight("b", "new");
    aflyweight->voice();
    bflyweight->voice();
}
