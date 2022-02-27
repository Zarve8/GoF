//Builder design pattern

#include <iostream>
#include <vector>

class Cell{
public:
    virtual void show() = 0;
};

class Floor: public Cell{
public:
    void show() override{
        std::cout<<"###\n";
    }
};

class Wall: public Cell{
public:
    void show() override{
        std::cout<<"| |\n";
    }
};

class Roof: public Cell{
public:
    void show() override{
        std::cout<<" # \n# #\n";
    }
};

class House{
    std::vector<Cell*> parts;
public:
    void add_part(Cell* c){
        this->parts.push_back(c);
    }

    void Print(){
        for(int i = parts.size()-1; i > -1; i--){
            this->parts[i]->show();
        }
    }
};

class Builder{
protected:
    House* house;
    Builder(): house(new House){}
public:
    virtual void add_wall() = 0;
    virtual void add_floor() = 0;
    virtual void add_roof() = 0;

    virtual House* GetResult() = 0;
};

class ConcreteBuilder1: public Builder{
public:
    ConcreteBuilder1(): Builder(){}
    void add_wall() override{
        this->house->add_part(new Wall);
    }
    void add_floor() override{
        this->house->add_part(new Floor);
    }
    void add_roof() override{
        this->house->add_part(new Roof);
    }

    House* GetResult() override{
        return this->house;
    }
};

class Director{
    Builder* builder;
public:
    Director(Builder* builder): builder(builder){}
    void add_wall(){
        this->builder->add_wall();
    }
    void add_floor(){
        this->builder->add_floor();
    }
    void add_roof(){
        this->builder->add_roof();
    }

    House* GetResult(){
        return this->builder->GetResult();
    }
};

int main(){
    Director adirector(new ConcreteBuilder1);
    adirector.add_floor();
    adirector.add_wall();
    adirector.add_floor();
    adirector.add_wall();
    adirector.add_roof();
    House* ahouse = adirector.GetResult();
    ahouse->Print();
}